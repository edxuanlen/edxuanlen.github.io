---
title: git 配置
date: 2018-03-31 20:17:43
tags: 
    - 应用
categories: 应用
description: git使用上的一些技巧整理。

---

## git 全局配置

```
git config --global user.name "edxuanlen"
git config --global user.email "edxuanlen@gmail.com"
```

## git clone 选择分支

git clone -b 分支名 https:// xxxxx


## 创建 git 仓库
```
git init
# touch README.md
# git add README.md
git add ./
git commit -m "2019.5.6"
git remote add origin https://github.com/edxuanlen/coding.git
git push -u origin master
# git push -f (强行推送)
```

## 大文件传送

git-lfs

```sh
curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | sudo bash
sudo apt-get install git-lfs
git lfs install
```


## 记住密码

```sh
git config credential.helper store
```