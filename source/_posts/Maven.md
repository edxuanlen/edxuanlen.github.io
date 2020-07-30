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
    - Maven
categories:
    - Maven

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

### Maven 问题

#### Maven 拉取包失败

本地存在jar包，但是一直会去远程仓库拉取导致失败。  

私服id配置应该不能被镜像MirrorOf拦截到，如:  

- 私服id central, MirrorOf central
- 私服id repo1, MirrorOf *

这样都会导致私服失效。  

