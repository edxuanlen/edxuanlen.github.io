---
title: String相关
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-08-07 10:57:00
img:
coverImg:
password:
summary:
tags:
    - JAVA
    - String
categories:
description:
---

## String

### 非常用，但有用的方法

- indexOf 字符第一次出现位置
- lastIndexOf
- replace 支持字符或字符串替换
- replaceAll 支持正则匹配替换

String 不可继承原因是 字符数组用final修饰
contact replace等操作都会返回一个新的String 对象


### 默认编码

系统默认编码  UTF-8 中文 三个字符（不一定）

## String Buffer

transient 修饰字符数组

所有方法几乎都加了synchronized

可修改

线程安全带来的缺点是效率相对StringBuilder而言更低


## String Builder

StringBuilder是StringBuffer的特殊优化版本，不考虑线程安全，效率最高。

