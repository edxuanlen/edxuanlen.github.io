---
title: Spring_boot入门
date: 2019-10-01 22:17:28
tags:
    - Spring

categories:
    - Java

description: Sprint_boot入门的一些简述和安装以及简单的例子。
top: true
---

## 是什么

> spring boot其实就是一个启动spring项目的一个工具而已。从最根本上来讲，Spring Boot就是一些库的集合，它能够被任意项目的构建系统所使用。  
> 其设计目的是用来简化新Spring应用的初始搭建以及开发过程。该框架使用了特定的方式来进行配置，从而使开发人员不再需要定义样板化的配置。
> Spring 技术栈的大整合，J2EE开发的一站式解决方案

## 微服务  

2014年，Martin fowler 发表了微服务的设计思想 （What are Microservices）  
微服务其实是一种架构风格  
一个应用应该是一组小型服务，可以通过HTTP来进行沟通  





## 安装准备

1. java SDK  
    8 <= JDK <= 11
2. Maven  
    [Maven](https://maven.apache.org/) >= 3.3  
    在许多操作系统上，Maven可以与软件包管理器一起安装。如果您使用OSX Homebrew，请尝试brew install maven。  
    Ubuntu用户可以运行sudo apt-get install maven。  
    使用Chocolatey的 Windows用户可以从提升（管理员）提示符运行choco install maven。
3. Gradle  
    [Gradle](https://gradle.org) >= 4.4  
    使用sdkman安装  
    curl -s "https://get.sdkman.io" | bash  
    安装完后输入  
    source "$HOME/.sdkman/bin/sdkman-init.sh"

     sdk install gradle 5.6.2


4. Sprint Boot CLI  
    sdk install springboot  



### 使用Spring CLI示例

下面是一个相当简单的web应用，你可以用它测试Spring CLI安装是否成功。创建一个名叫app.groovy的文件：

```java
@RestController
class ThisWillActuallyRun {

    @RequestMapping("/")
    String home() {
        "Hello World!"
    }
}
```

然后只需在shell中运行以下命令：
```sh
$ spring run app.groovy
```

注：首次运行该应用将会花费一些时间，因为需要下载依赖，后续运行将会快很多。

使用你最喜欢的浏览器打开[localhost:8080](localhost:8080)，然后就可以看到如下输出：

Hello World!


下一篇 : [第一个应用的开发](https://edxuanlen.gitee.io/2019/10/02/Spring-boot%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%BA%94%E7%94%A8%E7%9A%84%E5%BC%80%E5%8F%91/)