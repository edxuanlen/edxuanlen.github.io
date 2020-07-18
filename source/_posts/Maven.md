---
title: Maven
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-06-24 22:12:47
img:
coverImg:
password:
summary:

tags:
categories:

description: Maven的配置以及使用。
---


maven setting.xml

```xml
<localRepository>
    D:\mvn
</localRepository>
<mirrors>
    <mirror>
        <id>alimaven</id>
        <name>aliyun maven</name>
        <url>http://maven.aliyun.com/nexus/content/groups/public/</url>
        <mirrorOf>central</mirrorOf>
    </mirror>
</mirrors>
```

- localRepository 指定包下载的位置  
- morrors指定加速镜像


打包的插件

```xml
<plugin>
    <artifactId>maven-jar-plugin</artifactId>
    <version>3.0.2</version>
</plugin>
```
/bin	用于存放命令文件，系统中所有用户都可以使用
/sbin	用于存放命令文件，大多数命令只能由管理员root用户使用

1. 命令文件； 所有用户； 管理员root用户；
2. 存放个人数据；普通用户；管理员root用户；
3. /etc
4. /usr/share/man
5. /proc; /sys
6. /media
7. /etc
8. /




 