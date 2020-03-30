---
title: Python文件处理
date: 2018-09-10 08:23:03
tags:
    - python3小练手
categories:
    - Python3
description:
    用python对文件的基本处理，字典的使用
---

# 题目
 任一个英文的纯文本文件，统计其中的单词出现的个数。

```python3
import re
f = open('words.txt')

words_dict = {}
List = []
for line in f :
    # for i in line:
        E = re.findall(r'[^a-zA-Z]+', line)
        for j in E:
            line = line.replace( j , ' ')
        List = line.split()
        for j in List:
            if j not in words_dict:
                words_dict[j] = 1
            else:
                words_dict[j] = words_dict[j] + 1

print(words_dict)
words_dict = sorted ( words_dict.items() ,key=lambda item: item[1] )

print(words_dict)
# for i in words_dict:
#     print (i  , words_dict[i] )
```
