---
title: Ubuntu-18 之旅
date: 2018-09-02 19:35:40
tags: Ubuntu
categories:
  - 系统
description: 配置 Ubuntu18的全过程，供自己以后方便使用。
---

# Ubuntu的安装
如果在安装过程中最后提醒grub安装失败，是因为开机启动项安装失败，会导致无法进入系统
我一开始比较丧心病狂，直接把整块硬盘格式化后装Ubuntu就可以了
比较好的的处理方法如下==
https://blog.csdn.net/qq_40883132/article/details/80538539

# HEXO 配置
网上有很多教程
想看的可以百度一下
这里我是想说，把整个文件夹保存下来才是王道，直接可以使用
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
配置下信息
若出现报错 ：修改： themes/BlueLake (修改的内容, 未跟踪的内容) 修改尚未加入提交
git status
git rm -f --cached themes/BlueLake/
git add themes/BlueLake/
git add .
git commit -m ""
如果是要建立分支
```
git checkout -b hexo                 //创建并切换
git remote rm origin                                        //清除当前设备
git remote add origin git@github.com:edxuanlen/github.io.git//添加远程设备
git remote -v                                               //查看当前设备
git push origin hexo                                        
```

# 网易云
抛弃了kali再回到Ubuntu的怀抱，
就是因为kali蓝牙配置搞砸了，听歌都不爽（因为想连蓝牙音箱）
所以emmm 网易云可以直接到官网下载ubuntu版的，
http://d1.music.126.net/dmusic/netease-cloud-music_1.1.0_amd64_ubuntu.deb
下载完双击可以直接安装
无法打开的问题自行百度
sudo netease-cloud-music能正常使用
1. 方法一
用root权限修改文件/usr/share/applications/netease-cloud-music.desktop
 比如：sudo gedit /usr/share/applications/netease-cloud-music.desktop
--no-sandbox
2. 方法二
sudo gedit /etc/sudoers
修改/etc/sudoers文件，加一行：
YOURNAME ALL = NOPASSWD: /usr/bin/netease-cloud-music
YOURNAME为你登录的用户名。
sudo gedit /usr/share/applications/netease-cloud-music.desktop

修改Exec=netease-cloud-music %U 为  Exec=sudo netease-cloud-music %U,
这样点击网易云音乐图标就是以管理员权限启动的了，且不用输入密码。

 网易云无法调整界面大小
搜索.netease-cloud-music（注意前面有个"."）然后把搜索到的文件夹全都删掉
或者删除了~/.cache/netease-cloud-music 目录

# CLion,IdeaJ和Pycharm 三件套==
官网都有直接，由于是穷学生，只能用破解

1、在/etc/hosts 文件末尾添加一行
```
0.0.0.0 account.jetbrains.com  
```

2、打开这三个软件，运行.sh文件，选择 Activate code，输入
```
    EB101IWSWD-eyJsaWNlbnNlSWQiOiJFQjEwMUlXU1dEIiwibGljZW5zZWVOYW1lIjoibGFuIHl1IiwiYXNzaWduZWVOYW1lIjoiIiwiYXNzaWduZWVFbWFpbCI6IiIsImxpY2Vuc2VSZXN0cmljdGlvbiI6IkZvciBlZHVjYXRpb25hbCB1c2Ugb25seSIsImNoZWNrQ29uY3VycmVudFVzZSI6ZmFsc2UsInByb2R1Y3RzIjpbeyJjb2RlIjoiSUkiLCJwYWlkVXBUbyI6IjIwMTgtMTAtMTQifSx7ImNvZGUiOiJSUzAiLCJwYWlkVXBUbyI6IjIwMTgtMTAtMTQifSx7ImNvZGUiOiJXUyIsInBhaWRVcFRvIjoiMjAxOC0xMC0xNCJ9LHsiY29kZSI6IlJEIiwicGFpZFVwVG8iOiIyMDE4LTEwLTE0In0seyJjb2RlIjoiUkMiLCJwYWlkVXBUbyI6IjIwMTgtMTAtMTQifSx7ImNvZGUiOiJEQyIsInBhaWRVcFRvIjoiMjAxOC0xMC0xNCJ9LHsiY29kZSI6IkRCIiwicGFpZFVwVG8iOiIyMDE4LTEwLTE0In0seyJjb2RlIjoiUk0iLCJwYWlkVXBUbyI6IjIwMTgtMTAtMTQifSx7ImNvZGUiOiJETSIsInBhaWRVcFRvIjoiMjAxOC0xMC0xNCJ9LHsiY29kZSI6IkFDIiwicGFpZFVwVG8iOiIyMDE4LTEwLTE0In0seyJjb2RlIjoiRFBOIiwicGFpZFVwVG8iOiIyMDE4LTEwLTE0In0seyJjb2RlIjoiUFMiLCJwYWlkVXBUbyI6IjIwMTgtMTAtMTQifSx7ImNvZGUiOiJDTCIsInBhaWRVcFRvIjoiMjAxOC0xMC0xNCJ9LHsiY29kZSI6IlBDIiwicGFpZFVwVG8iOiIyMDE4LTEwLTE0In0seyJjb2RlIjoiUlNVIiwicGFpZFVwVG8iOiIyMDE4LTEwLTE0In1dLCJoYXNoIjoiNjk0NDAzMi8wIiwiZ3JhY2VQZXJpb2REYXlzIjowLCJhdXRvUHJvbG9uZ2F0ZWQiOmZhbHNlLCJpc0F1dG9Qcm9sb25nYXRlZCI6ZmFsc2V9-Gbb7jeR8JWOVxdUFaXfJzVU/O7c7xHQyaidCnhYLp7v32zdeXiHUU7vlrrm5y9ZX0lmQk3plCCsW+phrC9gGAPd6WDKhkal10qVNg0larCR2tQ3u8jfv1t2JAvWrMOJfFG9kKsJuw1P4TozZ/E7Qvj1cupf/rldhoOmaXMyABxNN1af1RV3bVhe4FFZe0p7xlIJF/ctZkFK62HYmh8V3AyhUNTzrvK2k+t/tlDJz2LnW7nYttBLHld8LabPlEEjpTHswhzlthzhVqALIgvF0uNbIJ5Uwpb7NqR4U/2ob0Z+FIcRpFUIAHEAw+RLGwkCge5DyZKfx+RoRJ/In4q/UpA==-MIIEPjCCAiagAwIBAgIBBTANBgkqhkiG9w0BAQsFADAYMRYwFAYDVQQDDA1KZXRQcm9maWxlIENBMB4XDTE1MTEwMjA4MjE0OFoXDTE4MTEwMTA4MjE0OFowETEPMA0GA1UEAwwGcHJvZDN5MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAxcQkq+zdxlR2mmRYBPzGbUNdMN6OaXiXzxIWtMEkrJMO/5oUfQJbLLuMSMK0QHFmaI37WShyxZcfRCidwXjot4zmNBKnlyHodDij/78TmVqFl8nOeD5+07B8VEaIu7c3E1N+e1doC6wht4I4+IEmtsPAdoaj5WCQVQbrI8KeT8M9VcBIWX7fD0fhexfg3ZRt0xqwMcXGNp3DdJHiO0rCdU+Itv7EmtnSVq9jBG1usMSFvMowR25mju2JcPFp1+I4ZI+FqgR8gyG8oiNDyNEoAbsR3lOpI7grUYSvkB/xVy/VoklPCK2h0f0GJxFjnye8NT1PAywoyl7RmiAVRE/EKwIDAQABo4GZMIGWMAkGA1UdEwQCMAAwHQYDVR0OBBYEFGEpG9oZGcfLMGNBkY7SgHiMGgTcMEgGA1UdIwRBMD+AFKOetkhnQhI2Qb1t4Lm0oFKLl/GzoRykGjAYMRYwFAYDVQQDDA1KZXRQcm9maWxlIENBggkA0myxg7KDeeEwEwYDVR0lBAwwCgYIKwYBBQUHAwEwCwYDVR0PBAQDAgWgMA0GCSqGSIb3DQEBCwUAA4ICAQC9WZuYgQedSuOc5TOUSrRigMw4/+wuC5EtZBfvdl4HT/8vzMW/oUlIP4YCvA0XKyBaCJ2iX+ZCDKoPfiYXiaSiH+HxAPV6J79vvouxKrWg2XV6ShFtPLP+0gPdGq3x9R3+kJbmAm8w+FOdlWqAfJrLvpzMGNeDU14YGXiZ9bVzmIQbwrBA+c/F4tlK/DV07dsNExihqFoibnqDiVNTGombaU2dDup2gwKdL81ua8EIcGNExHe82kjF4zwfadHk3bQVvbfdAwxcDy4xBjs3L4raPLU3yenSzr/OEur1+jfOxnQSmEcMXKXgrAQ9U55gwjcOFKrgOxEdek/Sk1VfOjvS+nuM4eyEruFMfaZHzoQiuw4IqgGc45ohFH0UUyjYcuFxxDSU9lMCv8qdHKm+wnPRb0l9l5vXsCBDuhAGYD6ss+Ga+aDY6f/qXZuUCEUOH3QUNbbCUlviSz6+GiRnt1kA9N2Qachl+2yBfaqUqr8h7Z2gsx5LcIf5kYNsqJ0GavXTVyWh7PYiKX4bs354ZQLUwwa/cG++2+wNWP+HtBhVxMRNTdVhSm38AknZlD+PTAsWGu9GyLmhti2EnVwGybSD2Dxmhxk3IPCkhKAK+pl0eWYGZWG3tJ9mZ7SowcXLWDFAk0lRJnKGFMTggrWjV8GYpw5bq23VmIqqDLgkNzuoog==  
```
给Pycharm添加桌面快捷键
sudo gedit /usr/share/applications/Pycharm.desktop
编辑
```
[Desktop Entry]
Type=Application
Name=Pycharm
GenericName=Pycharm3
Comment=Pycharm3:The Python IDE
Exec=sh **/**.sh  （sh的完整路径）
Icon= （图标所在的完整路径）
Terminal=pycharm
Categories=Pycharm;
```


# Mysql
坑： ERROR 2002 (HY000): Can't connect to local MySQL server through socket '/var/run/mysqld/mysqld.sock' (2)
不能直接输入mysql连接
官网有很全的安装指南
https://dev.mysql.com/doc/mysql-apt-repo-quick-guide/en/#apt-repo-fresh-install

安装后登录的时候输入
mysql -h<locolhost> -uroot -p<密码>
记得 -h和-p后面都不能加空格
如 mysql -h127.0.0.1 -uroot -p88888888
导出问题（https://stackoverflow.com/questions/34102562/mysql-error-1290-hy000-secure-file-priv-option）

show variables like '%secure%';
找出secure_file_priv的目录，输出到该目录下即可


# 还原某些桌面设置
dconf reset -f /

# 解压zip乱码
unzip -O cp936 xxxx.zip







