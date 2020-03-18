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


kubectl

```bash
curl -LO https://storage.googleapis.com/kubernetes-release/release/v1.17.0/bin/windows/amd64/kubectl.exe
```


minikube  

```bash
https://github.com/kubernetes/minikube/releases
```

or

```bash
choco install minikube
```

在 Kubernetes 上使用 Kubernetes 命令行工具 kubectl 部署和管理应用程序。使用 kubectl，您可以检查集群资源；创建、删除和更新组件；查看您的新集群；并启动实例应用程序。

Minikube 是一种可以让您在本地轻松运行 Kubernetes 的工具。Minikube 在笔记本电脑上的虚拟机（VM）中运行单节点 Kubernetes 集群，供那些希望尝试 Kubernetes 或进行日常开发的用户使用。

Minikube 支持以下 Kubernetes 功能：

- DNS
- NodePorts
- ConfigMaps 和 Secrets
- Dashboards
- 容器运行时: Docker、CRI-O 以及 containerd
- 启用 CNI （容器网络接口）
- Ingress

