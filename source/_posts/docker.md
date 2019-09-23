---
title: Docker
date: 2019-9-22
tags: 
    - 应用
categories: 应用
description: docker容器技术，换源和dockerfile的简介，包括一些自己的配置。
---

## 换源

1. settings -> daemon
2. 点击basic 变成 advanced
3. "registry-mirrors":["<https://docker.mirrors.ustc.edu.cn>"]
4. applay

> Docker中国区官方镜像 : <https://registry.docker-cn.com> \
> 网易 : <http://hub-mirror.c.163.com> \
> ustc : <https://docker.mirrors.ustc.edu.cn> \
> 中国科技大学 : <https://docker.mirrors.ustc.edu.cn> \
> 阿里云容器 : <https://cr.console.aliyun.com/>
( 首页点击“创建我的容器镜像”  得到一个专属的镜像加速地址，类似于“<https://1234abcd.mirror.aliyuncs.com”)>

## Dockerfile

how to write a dockerfile?
> Create an empty directory on your local machine.
> Change directories (cd) into the new directory,
> create a file called Dockerfile,
> copy-and-paste the following content into that file, and save it.
> Take note of the comments that explain each statement in your new Dockerfile.

```dockerfile
# Use an official Python runtime as a parent image
FROM python:3.4-alpine
# Set the working directory to /app
ADD /app
# Copy the current directory contents into the container at /app
COPY . /app
# Install any needed packages specified in requirements.txt
RUN pip install -r requirements.txt

# Define environment variable
ENV NAME python_web
# Run app.py when the container launches
CMD ["python", "app.py"]
```

## Docker-compose

官方文档 <https://docs.docker.com/compose/overview/>
官方例子 <https://docs.docker.com/compose/gettingstarted/>

> Using Compose is basically a three-step process:
>
> 1. Define your app’s environment with a Dockerfile so it can be reproduced anywhere.
> 2. Define the services that make up your app in docker-compose.yml so they can be run together in an isolated environment.
> 3. Run docker-compose up and Compose starts and runs your entire app.

## 设置支持中文

> -p 3306:3306：将容器的 3306 端口映射到主机的 3306 端口。
> -v -v $PWD/conf:/etc/mysql/conf.d：将主机当前目录下的 conf/my.cnf 挂载到容器的 /etc/mysql/my.cnf。
> -v $PWD/logs:/logs：将主机当前目录下的 logs 目录挂载到容器的 /logs。
> -v $PWD/data:/var/lib/mysql ：将主机当前目录下的data目录挂载到容器的 /var/lib/mysql 。
> -e MYSQL_ROOT_PASSWORD=123456：初始化 root 用户的密码。

## 常用镜像

### Mysql:5.7

```markdown
docker pull mysql:5.7

docker run -p 3306:3306 --name mysql -v $PWD/conf:/etc/mysql/conf.d -v $PWD/logs:/logs -v $PWD/data:/var/lib/mysql -e MYSQL_ROOT_PASSWORD=19980504 --restart=always -d mysql:5.7

docker exec -it mysql  env LANG=C.UTF-8 bash
```

### nodejs

```bash
docker run -it -e "NODE_ENV=production" -u "node"  -m "300M" --memory-swap "1G" -w "/home/node/app" -v D:\coding\web\nodejs:/home/node/app --name "node" -d node
```
