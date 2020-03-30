---
title: 配置apache-tomcat
date: 2018-09-22 09:28:13
tags:
categories:
description:
---


官网下载
然后解压
# 问题1
Cannot find /usr/local/apache-tomcat-6.0.30//bin/setclasspath.sh
This file is needed to run this program



# 问题2
运行setclasspath.sh报错  找不到jdk
方法：
编辑setclasspath.sh  在文件开始添加jdk的位置

CATALINA_HOME=/usr/local/apache-tomcat/
JAVA_HOME= JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64
这两个加在文件前面  目录一定要正确


java -verbose 可以查看jdk位置
/usr/lib/jvm/java-11-openjdk-amd64/lib/modules
