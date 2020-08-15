---
title: redis
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-06-13 13:51:44
img:
coverImg:
password:
summary:
tags:
    - Interview
    - redis
categories:
    - Interview
    - redis
description: 
---


## Redis


### 缓存知识考点

#### 缓存中间件-Memcache 和 Redis 的区别

|                    | Memcache | Redis |
|:------------------:|:--------:|:-----:|
|      数据类型      | 类似Hash |  丰富 |
| 数据磁盘持久化存储 |  不支持  |  支持 |
|        主从        |  不支持  |  支持 |
|        分片        |  不支持  |  支持 |

简单key-value可以选择Memcache  

### 为什么Redis能这么快

10w+ QPS(query per second)

- 完全基于内存，绝大部分请求是纯粹的内存操作，执行效率高
- 数据结构简单，对数据操作也简单
- 采用单线程，单线程也能处理高并发请求，想多核也可以多实例
- 多路I/O复用模型，非阻塞IO

#### 多路I/O复用

##### I/O复用模型

Redis 采用的I/O多路复用函数: epoll/kqueue/evport/select

- 因地制宜
- 优先选择时间复杂度为O(1)的多路服用函数作为底层实现
- 以时间复杂度为O(n)的select作为保底
- 基于react设计模式监听I/O事件

#### Redis 数据类型

供用户使用的数据类型

- String : 最基本的数据类型，二进制安全(可以存JPG图片)
    - get (key)
    - set (key) (value)
- Hash: String元素组成的字典，适合用于存储对象
    - hget (struct) (key)
    - hmset (struct) (key1) (value1) (key2) (value2) ... 
- List: 列表，按照String元素插入顺序排序(有点像栈)
    - lrange (list) (min) (max)
    - lpush (list) (key)
- Set: Sting 元素组成的无序集合，通过哈希表实现，不允许重复
    - smembers (set)
    - sadd (set) (key)
- Sorted Set: 通过分数来为集合中的成员进行从小到大的排序
    - zrangebyscore (set) (min) (max)
    - zadd (set) (score) (key)
- HyperLogLog 用于计数
- Geo 存储地理位置

##### 底层数据类型基础

- 简单动态字符串
- 链表
- 字典
- 跳跃表
- 整数集合
- 压缩列表
- 对象

### 从海量key里查询出某一固定前缀的key


- KEYS pattern: 查找所有符合给定模式pattern的key
    - KEYS指令一次性返回所有匹配的KEY
    - 键的数量过大会使服务卡顿

- SCAN cursor [MATCH pattern] [COUNT count]
    - 基于游标的迭代器，需要基于上一次的游标延续之前的迭代过程
    - 以0作为游标开始一次新的迭代，知道命令返回游标0完成一次便利
    - 并不保证每次执行都返回某个给定数量的元素，支持模糊查询
    - 一次返回的数量不可控，只能是大概率符合count参数

### Redis实现分布式锁

分布式锁需要解决的问题

- 互斥性
- 安全性
- 死锁
- 容错

#### SET

SET key value [EX seconds] [PX milliseconds] [NX|XX]

- EX second: 设置键的过期时间为 second 秒
- PX millisecond: 设置键的过期时间为millisecond 毫秒
- NX: 只在键不存在时，才对键进行设置
- XX: 只在键已经存在时，才对键进行设置操作
- SET操作成功完成时，返回OK，否则返回nil

#### 大量的key同时过期的注意事项

集中过期，由于清除大量的key很耗时，会出现断站的卡顿现象
    - 解决方案: 在设置key 的过期时间时，给每个key加上随机值

### 使用Redis做异步队列

使用List作为队列，RPush生产消息，LPOP消费消息

```redis
rpush list aaa
rpush list bbb
rpush list ccc
lpop list // aaa
lpop list // bbb
lpop list // ccc

```

- 缺点： 没有等待，队列里有值就直接消费
- 弥补： 可以通过在应用层引入Sleep机制去调用LPOP重试

如果不想用sleep 可以用BLPOP

#### BLPOP

blpop key [key ...] timeout: 阻塞直到队列有消息或者超时

```redis
session 1:
    blpop list 30  // 为空进入等待30s

session 2:
    rpush list a

s~~ession 1:
    1) "a"

```


缺点是只能共给一个消费者使用

#### pub/sub

主题订阅者模式

- 发送者(pub)发送消息，订阅者(sub)接收消息
- 订阅者可以订阅任意数量的频道

```redis
subscribe (channel) 接收广播
publish (channel) (content) 发送广播
```

缺点： 消息的发布是无状态的，无法保证可达

kafka 和 MQ

### 持久化方法之 RDB

RDB(快照)持久化：保存某个时间点的全量数据快照

手动：

- SAVE: 阻塞Redis的服务器进程，直到RDB文件创建完毕
- BGSAVE: Fork出一个子进程来创建RDB文件，不阻塞服务器进程

自动：

- 根据redis.conf配置里面的SAVE m n定时触发(用的是BGSAVE)
- 主从复制时，主节点自动触发
- 执行Debug Reload
- 执行Shutdown且没有开启AOF持久化
 
缺点：

- 内存数据的全量同步，数据量大会由于I/O而严重影响性能
- 可能会因为Redis 挂掉而丢失从当前至最后一次快照期间的数据

### 持久化之 AOF

AOF (Append-Only-File) 持久化：保存写状态

- 记录下除了查询以外的所有变更数据库状态的指令
- 以append的形式追加保存到AOF文件中

日志重写解决AOF文件大小不断增大的问题，原理如下

    - 调用fork(), 创建一个子进程
    - 子进程把新的AOF写道临时文件，不依赖原来的AOF文件
    - 主进程持续把新的变动同时写到内存和原来的AOF里
    - 主进程获取子进程重写AOF的完成信号，往新的AOF同步增量变动
    - 使用新的AOF文件替换掉旧的AOF文件

手动重写指令: BGREWRITEAOF

### RDB和AOF

#### RDB和AOF共存时的恢复流程 

![2020-06-13-13-56-17](http://image.edxuanlen.cn/2020-06-13-13-56-17.png)

#### RDB和AOF的优缺点

|      |               RDB              |                    AOF                   |
|:----:|:------------------------------:|:----------------------------------------:|
| 优点 |  全量数据快照，文件小，恢复快  | 可读性高，适合保存增量数据，数据不易丢失 |
| 缺点 | 无法保存最近一次快照之后的数据 |          文件体积大，恢复时间大          |

### RDB-AOF混合持久化方式

default RDB-AOF

- BGSAVE做镜像全量持久化，AOF做增量持久化

### pipeline 的好处

- pipeline 跟linux 的管道类似
- Redis基于请求/响应模型，单个请求处理需要一一对应
- pipeline批量执行指令，节省多次IO往返的时间
- 有顺序依赖的指令建议分批发送

### redis的同步机制

主从同步原理

#### 全同步过程

- Salve 发送sync 命令到Master
- Master启动一个后台进程，将Redis中的数据快照保存到文件中(BGSAVE)
- Master将保存数据快照期间接收到的写命令缓存起来
- Master完成写文件操作后，将该文件发送给Salve
- 使用新的AOF文件替换掉旧的AOF文件
- Master将这期间收集的增量写命令发送给Salve端

#### 增量同步过程

- Master接收到用户的操作指令，判断是否需要传播到Slave
- 将操作记录追加到AOF文件
- 将操作传播到其他Slave:
    1. 对齐主从库
    2. 往响应缓存写入指令
- 将缓存中的数据发给Slave


### Redis Sentinel (哨兵机制)

解决主从同步Master宕机后的主从切换问题：

- 监控： 检查主从服务器是否运行正常
- 提醒： 通过API向管理员或者其他应用程序发送故障通知
- 自动故障迁移：主从切换

#### 流言协议Gossip

在杂乱无章中寻求一致

- 每个节点都随机的与对方通信，最终所有节点达成一致的状态
- 种子节点定期随机向其他节点发送节点列表以及需要传播的信息
- 不保证信息一定会传递给所有节点，但是最终会趋于一致

### Redis 的集群原理 

如何从海量数据里快速找到所需？

- 分片：按照某种规则去划分数据，分散存储在多个节点上
- 常规的按照哈希划分无法实现节点的动态增减

一致性哈希算法： 对2^32取模，将哈希值空间组织成虚拟的圆环
将数据key使用相同的函数hash计算出哈希值
 
数据存储节点如下，若Node C宕机，则会存储到D节点上

![2020-06-13-13-57-13](http://image.edxuanlen.cn/2020-06-13-13-57-13.png)
 
新增Node X服务器，则在B到X之间的数据(object c)更改存储位置到X的位置上

![Node-X](http://image.edxuanlen.cn/2020-06-13-13-55-16.png)


### Hash环数据倾斜问题

引入虚拟节点解决数据倾斜问题

![2020-08-10-11-29-06](http://image.edxuanlen.cn/2020-08-10-11-29-06.png)

