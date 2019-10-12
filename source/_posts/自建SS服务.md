---
title: 自建SS服务
date: 2019-10-09 17:47:28
tags:
categories:
description:
top:
---

https://viencoding.com/article/90  

Vultr  
ssserver -s 0.0.0.0 -p 2333 -k "QWERTYU" -t 600 -m aes-256-cfb

cd ~
mkdir ss
cd ss
vim ss.json

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

ssserver -c ~/ss/ss.json


后台挂起
nohup ssserver -c ~/ss/ss.json >/dev/null 2>&1 &



// 5835