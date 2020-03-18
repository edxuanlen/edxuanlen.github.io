---
title: Spring-IOC
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-03-09 15:08:21
img:
coverImg:
password:
summary:
tags: 
    - SpringBoot
categories:
    - SpringBoot
description: Spring-IOC的学习
---


IOC也称为依赖注入， **创建bean时注入这些依赖项**。


为什么使用Spring？

没有Spring ，处理对象依赖问题
内部new对象： 依赖对象


对象频繁创造，依赖关系复杂

解决： 

1. 以来对象频繁创造
    单例 工厂 创建对象  newIntance() 反射

2. 以来关系复杂
    外部传入： 
        a. 构造器传参
        b. 方法传参
        c. 属性反射 field.set(x)



    