---
title: choco
date: 2018-03-31 20:17:43
tags: 
    - 应用
categories: 应用
description: windows 下的apt。
---

# choco

## 更改默认文件夹

设置path变量 ChocolateyInstall

## powershell

```sh
iex ((new-object net.webclient).DownloadString('https://chocolatey.org/install.ps1'))
```

## cmd

```sh
@powershell -NoProfile -ExecutionPolicy Bypass -Command "iex ((new-object net.webclient).DownloadString('https://chocolatey.org/install.ps1'))" && SET PATH=%PATH%;%ALLUSERSPROFILE%\chocolatey\bin
```
