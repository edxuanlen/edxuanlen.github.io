---
title: Spring-AOP
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-03-08 15:37:30
img:
coverImg:
password: 
summary: 
tags: 
    - SpringBoot
categories:
    - SpringBoot
description: Spring-AOP的学习
---



# Spring AOP

> 传统OOP开发中的代码逻辑自上而下，而这些过程会产生横切性的问题。而这些问题又与主业务逻辑关系不大，散落在代码的各个地方，难以维护。
> AOP的编程思想就是把这些问题和主业务逻辑进行分离，从而起到解耦的目的。

## 技术本质

AOP 底层原理： 动态代理(cglib 动态代理,JDK 动态代理)

如果是接口，就是JDK 动态代理， 否则是cglib动态代理
默认是java动态代理  