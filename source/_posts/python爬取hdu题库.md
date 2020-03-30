---
title: python爬取hdu题库
date: 2018-09-03 07:48:27
tags: Python
categories: Python
description: Python实现爬取后台题库。
---

这里涉及到很多的点，比如python利用正则表达式爬下来之后怎么把html标签去除，还有伪装浏览器访问，错误处理。

```python
import webbrowser
import urllib
import requests
import re
def getHtml(url):
    page = urllib.request.urlopen(url)
    html = page.read()
    unicodehtml = html.decode("gbk")	## 转化为gbk格式
    return unicodehtml

def zhenghe(str1,id,imgre):
    html=getHtml( str1+id )
    return re.findall(imgre,html)

headers = {'User-Agent':
    'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) '
    'Chrome/51.0.2704.63 Safari/537.36'}    ## 改request的头  模拟浏览器
num =1000;
Url = "http://acm.hdu.edu.cn/showproblem.php?pid="
reg = r'<div class=panel_content>.*?[\s\S]*?</div>'	## 正则表达式
imgre=re.compile(reg)
while num<=6275:
        list = zhenghe(Url,str(num),imgre)
        t = open("hdu题库\hdu%s.txt"%num,"w")
        for i in list:
            dr = re.compile(r'<[^>]+>',re.S)
            dd = dr.sub('',i)
            ## 上面两行时用来去除html标签
            t.write(dd)		## 写入
            t.write("\n")
        t.close()
        num=num+1
```

然而有一些问题 。就是转化gbk格式失败会终止程序，因此要写个错误处理
```python
def getHtml(url):
    page = urllib.request.urlopen(url)
    html = page.read()
    try:
        unicodehtml = html.decode("gbk")
    except:
        print("%s had not been install\n"%url)
        return "a" 	## 错误时return一个a
    return unicodehtml

while num<=6275:
        list = zhenghe(Url,str(num),imgre)
        if(list=="a"):	## 当发生错误时不写入
            continue
        t = open("hdu题库\hdu%s.txt"%num,"w")
```
到了这一步其实基本都已经实现了，但是还是不太完美，输入输出没有分开，而且也没有标题：
{% asset_img 1.png %}
这时候详化一下正则表达式就可以了，最终版本代码：

```python
import webbrowser
import urllib
import requests
import re
import codecs
def getHtml(url):
    page = urllib.request.urlopen(url)
    html = page.read()
    try:
        unicodehtml = html.decode("gbk")
    except:
        print("%s had not been install\n"%url)
        return "a"
    return unicodehtml

def zhenghe(str1,id,imgre):
    html=getHtml( str1+id )
    return re.findall(imgre,html)
headers = {'User-Agent':
    'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) '
    'Chrome/51.0.2704.63 Safari/537.36'}
num =1013;
Url = "http://acm.hdu.edu.cn/showproblem.php?pid="
reg = {}
reg[0] = r"<td align=center><h1 style='color:#1A5CC8'>.*?[\s\S]</h1>"
reg[1] = r"<br><br><div class=panel_title align=left>.*?[\s\S]*?</div> <div class=panel_content>"
reg[2] = r"</div> <div class=panel_content>.*?[\s\S]*?<br></div><div class=panel_bottom>"
reg[3] = r'Sample Input</div><div class=panel_content><pre><div style="font-family:Courier New,Courier,monospace;">.*?[\s\S]*?</div>'
reg[4] = r'Sample Output</div><div class=panel_content><pre><div style="font-family:Courier New,Courier,monospace;">.*?[\s\S]*?</div>'
while num<=1013:
    t = open("hdu题库\hdu%s.txt"%num,"a")
    for j in range (0,5):
        imgre=re.compile(reg[j])
        list = zhenghe(Url,str(num),imgre)
        if(list=="a"):
            continue

        for i in list:
            dr = re.compile(r'<[^>]+>',re.S)
            dd = dr.sub('',i)
            dr = re.compile(r'Input',re.S)
            dd = dr.sub('Input\n',dd)
            dr = re.compile(r'Output',re.S)
            dd = dr.sub('Output\n',dd)
            t.write(dd)
            t.write("\n\n")
    t.close()
    num=num+1
```

{% asset_img 2.png %}
