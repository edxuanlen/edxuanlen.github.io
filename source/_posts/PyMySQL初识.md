---
title: PyMySQL初识
date: 2018-09-03 22:53:15
tags:
    - python3小练手
categories:
    - Python3
description:
    Python与MySQL的连接。

---

先用pip 下载PyMySQL的库
然后就是mysql 的配置
然后是sql语句的使用
了解MySQL的游标含义
使用pymysql对MySQL进行操作

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

## 题目：做为 Apple Store App 独立开发者，你要搞限时促销，为你的应用生成激活码（或者优惠券），使用 Python 如何生成 200 个激活码（或者优惠券）？并将其保存到MySQL关系型数据库中。
## 代码：
```python3
import random
import pymysql

## 创建新的数据库
con = pymysql.connect(host='127.0.0.1', user='root', passwd='88609723')
cursor = con.cursor() # 获取游标
sql = 'DROP DATABASE Code'
cursor.execute(sql)
sql = 'CREATE DATABASE Code'
cursor.execute(sql)
sql = 'USE Code'
cursor.execute(sql)
sql = 'CREATE TABLE Code(Code_id int NOT NULL,Code VARCHAR(100) NOT NULL)'
cursor.execute(sql)

# 输入文件
# file = open('code.txt','w')
# for j in range(200):
#     Code = ''
#     Code = Code + str(j + 1) + ': '
#     for i in range(16):
#         f = random.randint(0,2) # randint 跟range范围不同
#         if f == 0:
#             Code = Code + chr(random.randint(48,57))
#         if f == 1:
#             Code = Code + chr(random.randint(65,90))
#         if f == 2:
#             Code = Code + chr(random.randint(97,122))
#         if (i + 1) % 4 == 0 and i != 15:
#             Code = Code + '-'
#     Code = Code + '\n'
#     file.write(Code)

for j in range(200):
    Code = ''
    for i in range(16):
        f = random.randint(0,2)
        if f == 0:
            Code = Code + chr(random.randint(48,57))
        if f == 1:
            Code = Code + chr(random.randint(65,90))
        if f == 2:
            Code = Code + chr(random.randint(97,122))
        if (i + 1) % 4 == 0 and i != 15:
            Code = Code + '-'
    sql = 'INSERT INTO Code(Code_id,Code) VALUES ( "%d","%s")' %((j+1),Code)
    cursor.execute(sql)


sql = ' SELECT * FROM Code INTO OUTFILE "/var/lib/mysql-files/Code.txt" '
cursor.execute(sql)

# 关闭连接，释放资源
cursor.close()
con.commit()
con.close()
```
