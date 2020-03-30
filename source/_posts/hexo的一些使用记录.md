---
title: hexo的一些使用记录
date: 2019-09-23 08:25:30
tags: 
    - 网站
categories: 网站
description: hexo使用过程中一些问题的解决。
top:
---

## BlueLake 的使用

[BlueLake配置](https://chaooo.github.io/2016/12/29/BlueLake%E5%8D%9A%E5%AE%A2%E4%B8%BB%E9%A2%98%E7%9A%84%E8%AF%A6%E7%BB%86%E9%85%8D%E7%BD%AE.html#comments)

## 报错cannot read  property 'count' of undefined
百度的插件有问题
```
1. npm remove hexo-baidu-url-submit
2. hexo clean
3. hexo g
```