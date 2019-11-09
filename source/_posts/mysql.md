---
title: Mysql
date: 2018-03-31 20:17:43
tags: 
    - SQL
categories: SQL
description: docker Mysql的使用上的一些记录。
---


## 开启远程访问

如果是docker上的镜像不需要

```SQL
use mysql;
select host,user from user;
# Grant all privileges on *.* to 'root'@'%' identified by 'password' with grant option;
# (%表示是所有的外部机器，如果指定某一台机，就将%改为相应的机器名；‘root’则是指要使用的用户名，里面的password需要自己修改成root的密码
flush privileges;  
```

## 支持中文

```SQL
set names utf8;
```

## 查看comment注释

```SQL
show full columns from table_name
```

## foreign key 外键

```SQL
alter table 表名 add constraint FK_ID foreign key(你的外键字段名) REFERENCES 外表表名(对应的表的主键字段名);
-- FK_ID 是外键名
```

## mysql insert

```SQL
insert into Stu values('col1','col2','col3');
```

## mysql update

```SQL
UPDATE table_name SET col1 = '', col2 = '' WHERE col3 = value;
```

## mysql 更改列

```SQL
alter table table_name modify column_name data_type;
```

## mysql Check 实现

一个限制插入年龄15-45的Check

```SQL
delimiter //
create trigger AgeCheck before insert on Stu
for each row
begin
if new.Age < 15 or new.Age > 45 then
signal sqlstate 'TX000' set message_text = "Age limit is 15 to 45";
end if;
end //
```
