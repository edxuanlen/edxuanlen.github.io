---
title: redis配置与使用
date: 2018-09-05 10:36:23
tags:
    - python3小练手
categories:
    - Python3
description:
    redis的基本配置和与python3 搭配使用。
---

# 下载安装配置
担心MYSQL开着会影响到redis 所以先检查和关闭mysql
```
service mysql status
service mysql stop
```
然后下载redis 到官网下载也行 ， 用wget也行。
```
wget http://download.redis.io/releases/redis-4.0.10.tar.gz
tar -zxvf redis-4.0.10.tar.gz
cd redis-4.0.10
make test
cd src
make install
cd ..
mkdir etc
mkdir bin
mv redis.conf etc/
cd src
mv mkreleasehdr.sh  redis-benchmark  redis-check-aof  redis-check-rdb  redis-cli  redis-sentinel  redis-server  redis-trib.rb ../bin
./redis-server
```
这时候会看到一些about
ctrl + c 出来，
```
cd
./redis-c
```
这时候会报错
Could not connect to Redis at 127.0.0.1:6379: Connection refused
Could not connect to Redis at 127.0.0.1:6379: Connection refused
修改一下配置文件
具体目录find找一下
把daemonize配置项改为yes
```
redis-server /home/edxuanlen/redis-4.0.10/etc/redis.conf
redis-cli
```
然后就可以连接了

附录：配置信息
daemonize 如果需要在后台运行，把该项改为yes
pidfile 配置多个pid的地址 默认在/var/run/redis. pid
bind 绑定ip，设置后只接受来自该ip的请求
port 监听端口，默认是6379
loglevel 分为4个等级：debug verbose notice warning
logfile 用于配置log文件地址
databases 设置数据库个数，默认使用的数据库为0
save 设置redis进行数据库镜像的频率。
rdbcompression 在进行镜像备份时，是否进行压缩
dbfilename 镜像备份文件的文件名
Dir 数据库镜像备份的文件放置路径
Slaveof 设置数据库为其他数据库的从数据库
Masterauth 主数据库连接需要的密码验证
Requriepass 设置 登陆时需要使用密码
Maxclients 限制同时使用的客户数量
Maxmemory 设置redis能够使用的最大内存
Appendonly 开启append only模式
Appendfsync 设置对appendonly. aof文件同步的频率（对数据进行备份的第二种方式）
vm-enabled 是否开启虚拟内存支持 （vm开头的参数都是配置虚拟内存的）
vm-swap-file 设置虚拟内存的交换文件路径
vm-max-memory 设置redis使用的最大物理内存大小
vm-page-size 设置虚拟内存的页大小
vm-pages 设置交换文件的总的page数量
vm-max-threads 设置VM IO同时使用的线程数量
Glueoutputbuf 把小的输出缓存存放在一起
hash-max-zipmap-entries 设置hash的临界值
Activerehashing 重新hash




## redis中的list

#题目：
 做为 Apple Store App 独立开发者，你要搞限时促销，为你的应用生成激活码（或者优惠券），使用 Python 如何生成 200 个激活码（或者优惠券）？ 将 0001 题生成的 200 个激活码（或者优惠券）保存到 Redis 非关系型数据库中。



http://www.runoob.com/redis/redis-lists.html
使用LPUSH将数据插入到名为 Code的列表当中
```python3
# coding : utf-8
import redis
import random

r = redis.Redis(host='127.0.0.1',port=6379,db=0)
list = []
for i in range (65,91):
    list.append(str(chr(i)))
for i in range (97,123):
    list.append(str(chr(i)))
for i in range (10):
    list.append(str(i))

# file = open('code.txt','w')
for i in range (200):
    Code = ''
    for j in range (16):
        Code += random.choice(list)
        if (j + 1) % 4 == 0 and j != 15:
            Code = Code + '-'
    r.lpush('Code', Code )
```
