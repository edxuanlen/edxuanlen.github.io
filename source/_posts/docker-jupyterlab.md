---
title: docker jupyterlab
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-04-06 17:15:04
img:
coverImg:
password:
summary:
tags:
    - docker
    - python
categories:
    - docker
description: 在docker上跑jupyterlab
---


<!-- ## 包 -->
<!-- 
```docker
docker mikebirdgeneau/jupyterlab

docker run -d -p 8888:8888 --name jupyterlab -v D:/docker/python/data:/opt/app/data mikebirdgeneau/jupyterlab
```
 -->

### Ubuntu 换源

```sh
## 阿里源
deb http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse

deb-src http://mirrors.aliyun.com/ubuntu/ bionic main restricted universe multiverse

deb-src http://mirrors.aliyun.com/ubuntu/ bionic-security main restricted universe multiverse

deb-src http://mirrors.aliyun.com/ubuntu/ bionic-updates main restricted universe multiverse

deb-src http://mirrors.aliyun.com/ubuntu/ bionic-proposed main restricted universe multiverse

deb-src http://mirrors.aliyun.com/ubuntu/ bionic-backports main restricted universe multiverse
```


```sh
jupyter notebook list
## 然后才能用这个token进入lab
```


### pip换源

```sh

mkdir ~/.pip
vim ~/.pip/pip.conf
# 然后将下面这两行复制进去就好了
[global]
index-url = https://mirrors.aliyun.com/pypi/simple
```

### 配置密钥

```sh
jupyter notebook --generate-config

jupyter notebook password  # 自己造一个密码输入一确认一次

vim ~/.jupyter/jupyter_notebook_config.json


vim ~/.jupyter/jupyter_notebook_config.py

# 修改

c.NotebookApp.ip='*'                                  # 就是设置所有ip皆可访问  
c.NotebookApp.password = u'sha1:03...       # 刚才复制的那个密文'  
c.NotebookApp.open_browser = False       # 禁止自动打开浏览器  
c.NotebookApp.port =1234                         #随便指定一个端口  

```
