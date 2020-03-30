---
title: hexo+github搭建个人博客
date: 2018-1-24 20:50:02
tags: 
    - hexo
categories:
    - 网站
description: hexo+github搭建个人博客的第一次配置和遇到的问题。
top: true
---


#hexo +  GitHub + git 搭建个人博客
## ** 安装配置node.js**

	   安装配置node.js (http://www.runoob.com/nodejs/nodejs-install-setup.html)

## **安装配置git：**

	安装配置git：（(https://git-scm.com)）(https://jingyan.baidu.com/article/9f7e7ec0b17cac6f2815548d.html)）

## **在GitHub上注册一个仓库：**

    新建一个名为 你的用户名.github.io 的仓库，比如说，如果你的github用户名是test，那么你就新建test.github.io的仓库（必须是你的用户名，其它名称无效），将来你的网站访问地址就是 http://test.github.io 了，是不是很方便？
    由此可见，每一个github账户最多只能创建一个这样可以直接使用域名访问的仓库。
    几个注意的地方：
    注册的邮箱一定要验证，否则不会成功；
    仓库名字必须是：username.github.io，其中username是你的用户名；
    仓库创建成功不会立即生效，需要过一段时间，大概10-30分钟，或者更久；
    创建成功后，默认会在你这个仓库里生成一些示例页面，以后你的网站所有代码都是放在这个仓库里啦。

##   **如果要绑定域名：**
    
    域名配置最常见有2种方式，CNAME和A记录，CNAME填写域名，A记录填写IP，由于不带www方式只能采用A记录，所以必须先ping一下你的用户名.github.io的IP，然后到你的域名DNS设置页，将A记录指向你ping出来的IP，将CNAME指向你的用户名.github.io，这样可以保证无论是否添加www都可以访问，如下：

    然后到你的github项目根目录新建一个名为CNAME的文件（无后缀），里面填写你的域名可以不加www。比如edxuanlen.io
    另外说一句，在你绑定了新域名之后，原来的你的用户名.github.io并没有失效，而是会自动跳转到你的新域名。

    过程中可能需要到购买域名的地方修改一下它的DNS：
    Nameserver 1
    ns2.alidns.com
    Nameserver 1
    ns1.alidns.com
## **hexo的下载和安装：**
	1、利用 npm 命令即可安装。在任意位置点击鼠标右键，选择Git Bash输入命令：npm install -g hexo
	2、创建文件夹（我的是在E盘创建的Hexo），然后在Hexo文件下，右键运行Git Bash，输入命令：hexo init在_config.yml,进行基础配置
	3、 hexo new "postName" #新建文章
		hexo new page "pageName" #新建页面
		hexo generate #生成静态页面至public目录
		hexo server #开启预览访问端口（默认端口4000，'ctrl + c'关闭server）
		hexo deploy #部署到GitHub
		hexo help  # 查看帮助
		hexo version  #查看Hexo的版本

	** 部分报错 **
	1.找不到git部署 ERROR Deployer not found: git
	解决方法
		npm install hexo-deployer-git --save
	3.部署类型设置git
	hexo 3.0 部署类型不再是github，_config.yml 中修改
	# Deployment
	## Docs: http://hexo.io/docs/deployment.html
	deploy:
	  type: git
	  repository: git@***.github.com:***/***.github.io.git
	  branch: master
	4. xcodebuild
	xcode-select: error: tool 'xcodebuild' requires Xcode, but active developer directory '/Library/Developer/CommandLineTools' is a command line tools instance
	npm install bcrypt
	5. RSS不显示
	安装RSS插件
	npm install hexo-generator-feed --save
	开启RSS功能
	编辑hexo/_config.yml，添加如下代码：
		
```
rss: /atom.xml #rss地址  默认即可
```

## ** hexo d 没办法用：**


	正常来说只要安装了就能用了
    一开始卡在死活用不了hexo d 最后发现== 我在config.yml 里面把原来我写的repository：改成repo就行了==


```Git
$ hexo d
INFO  Deploying: git
You have to configure the deployment settings in _config.yml first!
For more help, you can check the docs: http://hexo.io/docs/deployment.html
INFO  Deploy done: git

Example:
  deploy:
    type: git
    repo: <repository url>
    branch: [branch]
    message: [message]

    extend_dirs: [extend directory]

```


##  warning: “warning:LF will be replacee by CRLF”：

	在Windows环境下使用git进行add的时候，会提示如下warning: “warning:LF will be replacee by CRLF”。
	这是因为在Windows中的换行符为CRLF，而在Linux中的换行符为LF。在git创建的项目中换行符为LF，而执行git add时，系统会提示LF将被转换为CRLF。解决的办法很简单，禁止git的自动转换即可。
	$ git config --global core.autocrlf false //禁用自动转换然后再进行git操作即可。如果项目已经创建，则需要先删除之前创建的.git 文件后添加上面的设置。

`$ rm -rf .git
$ git config --globalcore.autocrlf false
**完成后再重新执行git操作**
$ git init
$ git add .
$ git remote add `

P.S.

CRLF : Carriage-Return Line-Feed 回车换行。即回车(CR,ASCII 13, \r)换行(LF, ASCII 10, \n).

在windows中使用回车换行标识一行的结束，而Linux中则只有换行符。

## ** 主题使用主题：**
	我用了bluelake ,详情转至bluelake主题配置介绍：http://blog.csdn.net/edxuanlen/article/details/79149778
## ** 文章编辑器的使用方法：**
	markdown：https://coding.net/help/doc/project/markdown.html#i-5
	注意

    所有markdown标志后面要有一个空格
    如果标题上一行是列表，则必须在标题和列表之间空一行
        “`代码注释上下都空一行。（github是没问题，csdn如果不空行界面会不好看）
        
###标题

	# 一级标题
	## 二级标题
	### 三级标题
	列表
	
	- 无序列表1
	- 无序列表2
	- 无序列表3
	1. 有序列表1 //注意1.后面有空格
	2. 有序列表2
	3. 有序列表3
	引用
	
	>这个是引用
	粗体
	
	**这个是粗体**
	*这个是斜体*
	***这个是粗体加斜体***
	链接和图片
	
	[link text](http://example.com/ “optional title”)
	![图片描述](链接)
	代码
	
	`    `
	```   ```
	分割线
	
	*************
	————————————
	_____________________
	markdown文档转为word,pdf
	
	    使用Pandoc https://www.zhihu.com/question/22972843/answer/30096928
	    安装Pandoc,使用Typora http://blog.csdn.net/u012814856/article/details/69258511

## ** 图标设置：**
	在设置图标的时候一直没办法替换点原来的  后来发现  改名后的ico要放在所用主题的 source 下才行 而不是 根目录下的source（值得一提，解析24小时候 域名自带的logo才会消失）