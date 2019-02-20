---
title: Python3 图像的基本处理
date: 2018-09-03 10:44:02
tags:
    - python3小练手
categories:
    - Python3
description:
    对图像的基本处理
---


# python3 图像的基本处理
## 图像的大小
```python3
jpg = Image.open("**.jpg")
x , y = jpg.size
```
此时， xy分别为图像的高和宽

官方文档如下：
https://pillow.readthedocs.io/en/4.0.x/reference/ImageDraw.html

```python3
from PIL import Image, ImageDraw , ImageFont

jpg = Image.open("old.jpg")
draw = ImageDraw.Draw(jpg)
x , y = jpg.size
print (x,y)
font = ImageFont.truetype('Ubuntu-RI.ttf', 40)
draw.text((250 , 20), "中文？", "red" , font = font )
# jpg.save("old.jpg")
jpg.show()
```

## 题目：
将你的 QQ 头像（或者微博头像）右上角加上红色的数字，类似于微信未读信息数量那种提示效果。 类似于图中效果

## 代码：
```python
from PIL import Image, ImageDraw , ImageFont
jpg = Image.open("new.jpg")
#
draw = ImageDraw.Draw(jpg)
x , y = jpg.size
print (x,y)
# draw.test( (10, y - 40) , "4" , "red" , font = 'LiberationSans-Regular.ttf')

font = ImageFont.truetype('Ubuntu-RI.ttf', 40)
draw.text((250 , 20), "中文？", "red" , font =  font )
jpg.save("new.jpg")

jpg.show()
```

## 效果
{% asset_img 1.jpg %}
