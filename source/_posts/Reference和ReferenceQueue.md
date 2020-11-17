---
title: Reference和ReferenceQueue
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-08-13 14:44:30
img:
coverImg:
password:
summary:
tags:
    - Java
    - Interview
categories:
    - Java
    - Interview
description: Java的四种引用类型和引用队列。
---

## 强引用

强引用GC的时候不会被清理掉，而且就算内存不足也不会被清理掉，他只会抛出OOM错误。代码实现可以用new 一个对象实现。

```Java
Object obj = new Object();
```

如果想要释放强回收引用对象空间，可以将其置为null

## 软引用

软引用在内存足够的时候并不会被GC，但是如果内存不够了的时候会被GC。可以避免OOM错误，可以应用于图片缓存，内存不足系统回收不再使用的Bitmap

```Java
List<Object> list = new LinkedList<>();
for (int i = 0; i < 5; i++) {
    int[] buff = new int[(int) 3e8];
    WeakReference<int[]> sr = new WeakReference<>(buff);
    list.add(sr);
}

for (Object o : list) {
    Object obj = ((WeakReference) o).get();
    System.out.println(obj);
}
```

上述代码中，最后可能只会有最后几个对象还存在，因为空间不足的时候会把前面的几个进行空间回收。

## 弱引用

弱引用在GC的时候都会被回收。也可用于图片缓存，ThreadLocalMap等。

```Java
List<Object> list = new LinkedList<>();
for (int i = 0; i < 5; i++) {
    int[] buff = new int[(int) 3e8];
    WeakReference<int[]> sr = new WeakReference<>(buff);
    list.add(sr);
}
System.gc(); //主动通知垃圾回收
for (Object o : list) {
    Object obj = ((WeakReference) o).get();
    System.out.println(obj);
}
```

在执行之后所有引用都会变为null

## 虚引用

虚引用在任何时候都可能被垃圾回收器回收。通过它甚至无法获取被引用的对象，它存在的唯一作用就是当它指向的对象回收时，它本身会被加入到引用队列中，这样我们可以知道它指向的对象何时被销毁。

```Java
String str = new String("hello")
ReferenceQueue<String> rq = new ReferenceQueue<>();
// 创建一个虚引用，让此虚引用引用到"疯狂Java讲义"字符串
PhantomReference<String> pr = new PhantomReference<> (str, rq);
// 切断str引用和"疯狂Java讲义"字符串之间的引用
// 取出虚引用所引用的对象，并不能通过虚引用获取被引用的对象，所以此处输出null
System.out.println(pr.get());
// 强制垃圾回收
System.out.println(rq.poll() == pr);

System.gc();
System.runFinalization();
// 垃圾回收之后，虚引用将被放入引用队列中
// 取出引用队列中最先进入队列中的引用与pr进行比较
System.out.println(rq.poll() == pr);

```

这里输出的时null false true

调用System.gc的时候只是