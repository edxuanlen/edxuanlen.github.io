---
title: LinkedBlockingQueue 和 ArrayBlockingQueue的区别
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-08-04 15:41:48
img:
coverImg:
password:
summary:
tags:
    - Java
    - 数据结构
categories:
    - Java
    - 数据结构

description: 阻塞队列 ArrayBlockingQueue，LinkedBlockingQueue的区别和使用
---


### ArrayBlockingQueue与LinkedBlockingQueue区别

1. ArrayBlockingQueue采用动态数组

      takeIndex和putIndex 表示存和取的两个数组下标。

      有界 （必须指明数组大小）

      不能存放null

      读和写公用一个ReentrantLock

2. LinkedBlockingQueue采用链表实现

     默认无界（可以在初始化时指明大小）

    不能存放null

    读和写有两把锁ReentrantLock takeLock和putLock

总结: 最大的区别就是Array内部只有一把锁，offer和take使用同一把锁，而Link的offer和take使用不同的锁。

### 使用场景

ArrayBlockingQueue预先分配好一段连续内存，更稳定  
LinkedBlockingQueue 读写锁分离，吞吐量更大  

### ReentrantLock和Condition的关系

在做具体分析之前，先介绍一下ReentrantLock 和Condition之间的关系。  
ReentrantLock内部维护了一个双向链表，链表上的每个节点都会保存一个线程，锁在双向链表的头部自选，取出线程执行。  
而Condition内部同样维持着一个双向链表，但是其向链表中添加元素（await）和从链表中移除（signal）元素没有像ReentrantLock那样，保证线程安全，所以在调用Condition的await()和signal()方法时，需要在lock.lock()和lock.unlock()之间以保证线程的安全。  
在调用Condition的signal时，它从自己的双向链表中取出一个节点放到了ReentrantLock的双向链表中，所以在具体的运行过程中不管ReentrantLock new 了几个Condition其实内部公用的一把锁。介绍完这个之后，我么来分析ArrayBlockingQueue和LinkedBlockingQueue的内部实现不同。

#### ArrayBlockingQueue

先看其内部锁的定义：

```Java
    int count;
    lock = new ReentrantLock(fair);
    notEmpty = lock.newCondition();
    notFull =  lock.newCondition();
```

lock 其内部的锁
notEmpty 当调用offer时，会调用notEmpty.signal() 通知之前因为队列空而被阻塞的线程。同时在take后，如果内部计数器count=0时，会调用notEmpty.await() 阻塞调用take的线程。  

notFull 当调用offer时，如果现在count=内部数组的长度时，会调用notFull.await()阻塞现在添加元素的所有线程；当调用take时，总会调用notFull.signal()唤醒之前因为队列满而阻塞的线程。  

根据上面分析ReentrantLock和其Condition的关系，可以看到放元素和取元素用的同一把锁，无法使放元素和取元素同时进行，只能先后相继执行。  

#### LinkedBlockingQueue

内部锁定义：

```Java

    /** Current number of elements */
    private final AtomicInteger count = new AtomicInteger();

    /** Lock held by take, poll, etc */
    private final ReentrantLock takeLock = new ReentrantLock();

    /** Wait queue for waiting takes */
    private final Condition notEmpty = takeLock.newCondition();

    /** Lock held by put, offer, etc */
    private final ReentrantLock putLock = new ReentrantLock();

    /** Wait queue for waiting puts */
    private final Condition notFull = putLock.newCondition();
```

count 内部元素计数器使用的原子类型的计数器，使的元素个数的更新支持并发，为下面取和放元素并发提供了支持。  
takeLock 取元素单独的锁，和放元素分开，这样即使有Condition也可以使的取和放元素在不同的节点上自选  

notEmpty 取元素的Condition锁，和放元素锁分开。  
putLock notFull 和上面介绍的takeLock notEmpty一直。  
通过这种设置，可以将在链表头上放元素和在链表尾部取元素不再竞争锁，在一定程度上可以加快数据处理。  
