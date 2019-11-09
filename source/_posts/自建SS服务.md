---
title: 自建SS服务
date: 2019-10-09 17:47:28
tags:
    - 应用
categories:
    - 应用
description: 科学上网，求学必备的方式。
top: true
---


最近zf的净网行动导致了很多VPN崩溃了，由于科学上网的需要，我决定自己动手搭建一个VPN\
事实证明特别简单，费用也不是很高，($2.5/month)


## 服务器

### 选用和购买

由于需要外网ip的VPS才能科学上网，所以需要一个国外的服务器。\
这里要注意的是 **千万不要选阿里云等国内代理商的国外服务器** \
原因是他不会允许你使用服务器代理流量访问国外的网站， 如果你这么做了会接受到警告和封闭  

我们可以选用国外服务器的代理商，我选用了Vultr，因为对比下来价格最便宜  
注册送$50, 但仅限于第一个月内用  
我选用了一个美国的服务器, 最低$3.5/mo  
不同地区的价格和延迟都不一样，大家自己都可以试一下  
**要注意的是，$2.5/mo的服务器是ipv6 only**


### 安装相关软件

```bash
sudo apt-get -y update && sudo apt-get install python-pip python-setuptools m2crypto shadowsocks
ssserver -s 0.0.0.0 -p 2333 -k "QWERTYU" -t 600 -m aes-256-cfb
// 2333是服务器开放的ssr的端口，QWERTYU是连接的密码，最大延迟时间，aes-256-cfb是加密方式
```

这样就可以运行了，只需要本地用shadowsocks的客户端连接即可。
需要客户端可以到 https://github.com/Alvin9999/new-pac/wiki/ss免费账号#ssssr免费账号长期更新 去下载

上面ssr服务器端的配置也可以写成一个配置文件

```sh
cd ~
mkdir ss
cd ss
vim ss.json
```

ss.json 内容如下:

```json
{
    "server":"0.0.0.0",
    "server_port": 2333,
    "local_address": "127.0.0.1",
    "local_port": 1080,
    "password":"QWERTYU",
    "timeout":600,
    "method":"aes-256-cfb"
}
```

然后运行：

```sh
ssserver -c ~/ss/ss.json
```

后台挂起
```sh
nohup ssserver -c ~/ss/ss.json >/dev/null 2>&1 &
```



如果有需求，但自己不想搭的话也可以联系我，或者在下面评论，可以一起合租一个服务器。
// 5835

参考博客: https://viencoding.com/article/90  
