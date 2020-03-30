---
title: HTML
date: 2018-03-23 14:04:56
tags: HTML
categories: HTML
description: HTML的初步学习，包括HTML段落、列表、超链接、表格、图像和多媒体......
---

# HTML 段落

```md
1. 分六个等级的字体(h1-h6)
2. 换行<br>(line break)
3. 水平线<hr>(horizontal rule)

4. 字体特性设定<font></font>:
	字体大小size;
	字体颜色color;
	字体名称face 如<font face=标楷体> 标楷体</font>
	
5. 文本格式化：
	<b><strong>定义粗体字体
	<em> 定义着重文字
	<i><em>定义斜体字
	<small>、<big>定义小、大号字
	<sub> <sup>上下标
	<ins><del>定义插入字、删除字
	
	<abbr><acronym>定义缩写、定义地址
	<bdo>定义文字方向 如<p><bdo dir="rtl"	
	<blockquote>定义长的引用
	<q>短的引用定义
	<address>定义地址
	<cite>定义引用、引证
```

# HTML 列表

```md
1. 无序列表ul：
	<ul>
		<li>Coffee</li>
		<li>Mile</li>
	</ul>

2. 有序列表ol：
	<ol type="a"/"A"/"Ⅰ"/"1">
		<li>Coffee</li>
		<li>Mile</li>
	</ol>
	
3. 定义列表dl:
	<dt>标题
	<dd>内容
列表可嵌套

```

# HTML 超链接<a>

```md
1. href="": 链接地址
2. 标签间可以为文字描绘或图片
3. target: 打开位置  ex:_top、_blank、_self、_parent
4. 定义位置<a id=""></a>
5. iflame 独立模块
```
	
# HTML 图像

```md
1. <img>定义图像(包含属性，并且灭有闭合标签)
2. src源属性: <img src="">
3. alt替代文本属性: 如:<img src="" alt="属性文本">
4. height、width、border属性
```
	
# HTMl 多媒体

```md
1. 音乐播放器： <audio src=""  controls="controls" /*循环：loop*/>不显示提示</audio>
2. 视频播放器:  <video source> 多个格式播放
```

# HTML 表格(table)

```md
1. rowspan
```
# 无语义元素
1. div模块
2. span
**span更改文段中某一小段文字的属性。**

# 语义元素
1. header
2. section
3. article
4. nav
5. aside
6. footer

# 微格式
<time>
<pubdate>
<time datetime="YYYY-MM-DDThh-mm-ssTZD">T规定时间分隔符 TZD时区标识符

<input>元素类型

date month	week time datetime_local 
	
email search tel url

其他表单元素：
select option optgroup  textarea
	
	
	
	
	
	
	