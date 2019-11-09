---
title: hexo_Bluelake主题
date: 2018-1-24 20:52:30
tags:
    - hexo
categories:
    - 网站
description: Bluelake主题的配置
top: true
---

开始之前

在阅读本文之前，假定您已经成功安装了Hexo，并使用 Hexo 提供的命令创建了一个静态博客。Hexo是一个快速、简洁且高效的博客框架。Hexo基于Node.js ，使用 Markdown（或其他渲染引擎）解析文章，在几秒内，即可利用靓丽的主题生成静态网页。

    需要特别注意的是Hexo有两个_config.yml配置文件，一份位于站点根目录下，主要包含 Hexo 站点本身的配置，下文中会称为根_config.yml；另一份位于主题目录下（themes/主题名/_config.yml），这份配置由主题作者提供，主要用于配置主题相关的选项,下文中会称为主题_config.yml。

1. 安装

您可以直接到BlueLake发布页下载，然后解压拷贝到themes目录下，修改配置即可。
不过我还是推荐使用GIT来checkout代码，之后也可以通过git pull来快速更新。
1.1 安装主题

在根目录下打开终端窗口：
git bash

$ git clone https://github.com/chaooo/hexo-theme-BlueLake.git themes/BlueLake

1.2 安装主题渲染器

BlueLake是基于jade和stylus写的，所以需要安装hexo-renderer-jade和hexo-renderer-stylus来渲染。
git bash

$ npm install hexo-renderer-jade@0.3.0 --save
$ npm install hexo-renderer-stylus --save

1.3 启用主题

打开根_config.yml配置文件，找到theme字段，将其值改为BlueLake(先确认主题文件夹名称是否为BlueLake)。
根_config.yml
_config.yml


theme: BlueLake

1.4 验证

首先启动 Hexo 本地站点，并开启调试模式：
git bash

	

$ hexo s --debug

在服务启动的过程，注意观察命令行输出是否有任何异常信息，如果你碰到问题，这些信息将帮助他人更好的定位错误。 当命令行输出中提示出：INFO Hexo is running at http://0.0.0.0:4000/. Press Ctrl+C to stop.
此时即可使用浏览器访问 http://localhost:4000，检查站点是否正确运行。
1.5 更新主题

今后若主题添加了新功能正是您需要的，您可以直接git pull来更新主题。
git bash

cd themes/BlueLake
git pull

2. 配置
2.1 配置网站头部显示文字

打开根_config.yml，找到：
根_config.yml
_config.yml


title: 
subtitle: 
description: 
author:

title和subtitle分别是网站主标题和副标题，会显示在网站头部；description在网站界面不会显示，内容会加入网站源码的meta标签中，主要用于SEO；author就填写网站所有者的名字，会在网站底部的Copyright处有所显示。
2.2 设置语言

该主题目前有七种语言：简体中文（zh-CN），繁体中文（zh-TW），英语（en），法语（fr-FR），德语（de-DE），韩语 （ko）,西班牙语（es-ES）；例如选用简体中文，在根_config.yml配置如下：
根_config.yml
_config.yml


	

language: zh-CN

2.3 设置菜单

打开主题_config.yml，找到：
主题_config.yml
themes/BlueLake/_config.yml

menu:
  - page: home
    directory: .
    icon: fa-home
  - page: archive
    directory: archives/
    icon: fa-archive
  # - page: about
  #   directory: about/
  #   icon: fa-user
  - page: rss
    directory: atom.xml
    icon: fa-rss

主题默认是展示四个菜单，即主页home，归档archive，关于about，订阅RSS；about需要手动添加，RSS需要安装插件，若您并不需要，可以直接注释掉。
每个页面底部的footer中联系博主的三个图标分别是邮箱，微博主页链接地址，GitHUb个人页链接地址，直接使用主题_config.yml中about页面的配置，若不需要about页面，只需要如下配置就好：
主题_config.yml
themes/BlueLake/_config.yml

	

# About page 
about:
  email: ## 个人邮箱 
  weibo_url: ## 微博主页链接地址
  github_url: ## github主页链接地址

2.3.1 添加about页

此主题默认page页面是关于我页面的布局，在根目录下打开命令行窗口，生成一个关于我页面：
git bash

$ hexo new page 'about'

打开主题_config.yml，补全关于我页面的详细信息：
主题_config.yml
themes/BlueLake/_config.y

# About page 
about:
  photo_url: ## 头像的链接地址
  email: ## 个人邮箱 
  weibo_url: ## 微博主页链接地址
  weibo_name: ## 微博用户名 
  github_url: ## github主页链接地址
  github_name: ## github用户名

当然您也可以自定义重新布局about页面，只需要修改layout/page.jade模板就好。
2.3.2 安装 RSS(订阅) 和 sitemap(网站地图) 插件

在根目录下打开命令行窗口：
git bash

$ npm install hexo-generator-feed --save
$ npm install hexo-generator-sitemap --save
$ npm install hexo-generator-baidu-sitemap --save

添加主题_config.yml配置：
主题_config.yml
themes/BlueLake/_config.yml

Plugins:
  hexo-generator-feed
  hexo-generator-sitemap
  hexo-generator-baidu-sitemap
feed:
  type: atom
  path: atom.xml
  limit: 20
sitemap:
  path: sitemap.xml
baidusitemap:
  path: baidusitemap.xml

2.4 添加本地搜索

默认本地搜索是用原生JS写的，但还需要HEXO插件创建的JSON数据文件配合。安装插件hexo-generator-json-content来创建JSON数据文件：
git bash

	

$ npm install hexo-generator-json-content@2.2.0 --save

然后在根_config.yml添加配置：
根_config.yml
_config.yml

	

jsonContent:
  meta: false
  pages: false
  posts:
    title: true
    date: true
    path: true
    text: true
    raw: false
    content: false
    slug: false
    updated: false
    comments: false
    link: false
    permalink: false
    excerpt: false
    categories: false
    tags: true

最后在主题_config.yml添加配置：
主题_config.yml
themes/BlueLake/_config.yml
	

local_search: true

2.5 修改站点图标

站点图标存放在主题的Source目录下，已经默认为您准备了两张图片。您也可以自己设计站点LOGO。
您需要准备一张ico格式并命名为 favicon.ico ，请将其放入hexo目录的source文件夹，建议大小：32px X 32px。
您需要为苹果设备添加网站徽标，请命名为 apple-touch-icon.png 的图像放入hexo目录的“source”文件夹中，建议大小为：114px X 114px。
(有很多网站都可以在线生成ico格式的图片。)
2.6 添加站点关键字

请在hexo目录的根_config.yml中添加keywords字段，如：
根_config.yml
_config.yml

	

# Site
title: Hexo
subtitle: 副标题
description: 网站简要描述,如：Charles·Zheng's blog.
keywords: 网站关键字, key, key1, key2, key3
author: Charles
language: zh-CN

2.7 其他配置

主题_config.yml的其他配置

    show_category_count——是否显示分类下的文章数。
    widgets_on_small_screens——是否在小屏显示侧边栏，若true,则侧边栏挂件将显示在底部。
    主题_config.yml
    themes/BlueLake/_config.yml


    show_category_count: true 
    widgets_on_small_screens: true

3.集成第三方服务
3.1 添加评论

目前主题集成六种第三方评论，分别是多说评论、Disqus评论、来必力评论、友言评论、网易云跟帖评论、畅言评论，多说马上就要停止服务了，友言好像也没怎么维护,目前我已把自己的博客评论从多说转移到畅言了，在国内目前网易云跟帖和畅言还不错。

    注册并获得代码。
        若使用多说评论，注册多说后获得short_name。
        若使用Disqus评论，注册Disqus后获得short_name。
        若使用来必力评论，注册来必力,获得data-uid。
        若使用友言评论，注册友言,获得uid。
        若使用网易云跟帖评论，注册网易云跟帖,获得productKey。
        若使用畅言评论，注册畅言，获得appid，appkey。
    配置主题_config.yml：
    主题_config.yml
    themes/BlueLake/_config.yml

    	

    #Cmments
    comment:
      duoshuo: ## duoshuo_shortname
      disqus: ## disqus_shortname
      livere: ## 来必力(data-uid)
      uyan: ## 友言(uid)
      cloudTie: ## 网易云跟帖(productKey)
      changyan: ## 畅言需在下方配置两个参数，此处不填。
        appid: ## 畅言(appid)
        appkey: ##畅言(appkey)

3.2 百度统计

    登录百度统计，定位到站点的代码获取页面。
    复制//hm.baidu.com/hm.js?后面那串统计脚本id(假设为：8006843039519956000)
    配置主题_config.yml:
    主题_config.yml
    themes/BlueLake/_config.yml


    baidu_analytics: 8006843039519956000

    注意： baidu_analytics不是你的百度id或者百度统计id
    如若使用谷歌统计，配置方法与百度统计类似。

3.3 卜算子阅读次数统计
主题_config.yml
themes/BlueLake/_config.yml

busuanzi: true

若设置为true将计算文章的阅读量(Hits)，并显示在文章标题下的小手图标旁。
3.4 微博秀

微博秀挂件的代码放在layout/_widget/weibo.jade下，需要您去微博开放平台获取您自己的微博秀代码来替换。

    登录微博开放平台，选择微博秀。
    为了与主题风格统一，作如下配置
        基础设置：高400px；勾选宽度自适应；颜色选择白色；
        样式设置：主字色#333；链接色#40759b；鼠标悬停色#f7f8f8；
        模块设置：去掉标题、边框、粉丝的勾选框，只留微博。
    复制代码里src=""里引号包裹的内容，替换到layout/_widget/weibo.jade
    weibo.jade
    layout/_widget/weibo.jade

    	

    .widget
      .widget-title
        i(class='fa fa-weibo')= ' ' + __('新浪微博')
      iframe(width="100%",height="400",class="share_self",frameborder="0",scrolling="no",src="http://widget.weibo.com/weiboshow/index.php?language=&width=0&height=400&fansRow=2&ptype=1&speed=0&skin=5&isTitle=0&noborder=0&isWeibo=1&isFans=0&uid=1700139362&verifier=85be6061&colors=d6f3f7,ffffff,333,40759b,f7f8f8&dpc=1")

    这只是为了和主题的风格统一，当然您也可以自由随意发挥。

        注意：最主要是是要把src里uid=和verifier=后面的字段替换为您自己代码里的就好。



转载: https://chaooo.github.io/




后面来补充一下遇到的问题，about界面的图片应该怎么放置：


	在hexo/source目录下新建一个img文件夹，将图片放入该文件夹下，插入图片时链接即为/img/图片名称。
	我在themes/source下找到的img 文件夹 有bg的图片 灵机一动加在了这个img里，在git编辑themes的主题config的时候成功的调用。
	 /img/调用图片名 （例如  头像.jpg） 即可
	 
 **2. 使用图床：**
 
	 https://sm.ms/  然后再用url进行调用！
	 
 **3. 文章内如何调用图片：**
		
	前提：修改_config.yml配置文件post_asset_folder项为true。
	
	创建博客是使用命令创建：
	
	hexo new [layout] <title>
	
	其中的layout项可以省略，例如：
	
	hexo new "这是一个新的博客"
	
	使用完命令之后，在source/_post文件夹里面就会出现一个“这是一个新的博客.md”的文件和一个“这是一个新的博客”的文件夹。
	这是一个新的博客的图片
	
	这是一个新的博客的图片
	
	下一步就是把需要的图片放到新创建的那个文件夹里面去。
	引用图片的第一种方法
	
	{% asset_img 这是一个新的博客的图片.jpg 这是一个新的博客的图片的说明 %}
	
	用此种方法，而不是以前的![]()方法，前提是你的hexo的版本是hexo3以上，到package.json里面看一下吧。如果不是hexo3以上的版本，那就只能用第二种方法了。
	
	例子
	
	我现在写了一个段落，并且想在这个段落的某一个地方{% asset_img 这是一个新的博客的图片.jpg 这是一个新的博客的图片的说明 %}引入一张图片


**在写作过程中乱码问题：**

将博客文件保存为UTF-8即可解决问题。

方法：

    1.将博客文件保存为UTF-8

     用记事本打开本地的博客文件“xxx.md”，然后点“另存为”，“编码(E):”选择“UTF-8”，点击“保存”，替换原文件。

    2.重新生成，部署，博客乱码即消除。