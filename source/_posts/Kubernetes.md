---
title: Kubernetes
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-03-16 09:00:12
img:
coverImg:
password:
summary:
tags:
categories:
description:
---

### 安装


```sh
apt-get update && apt-get install -y apt-transport-https curl # http + https
curl -s https://mirrors.aliyun.com/kubernetes/apt/doc/apt-key.gpg | apt-key add # 签名密钥 与阿里demo略有不同，2020年5月，Ubuntu 16.04 Xenial Xerus 是当前最新的 Kubernetes 存储库
cat <<EOF >/etc/apt/sources.list.d/kubernetes.list
deb https://mirrors.aliyun.com/kubernetes/apt/ kubernetes-xenial main
EOF  
apt-get update  
apt-get install -y kubelet kubeadm kubectl kubernetes-cni # 比阿里多 kubernetes-cni
```

#### 禁止交换内存

sudo swapoff -a

```sh
# 永久禁用
sudo vim /etc/fstab
# 注释掉/swapfile
```

