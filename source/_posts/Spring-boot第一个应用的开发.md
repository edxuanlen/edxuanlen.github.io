---
title: Spring_boot第一个应用的开发
date: 2019-10-02 10:45:00
tags:
    - Spring

categories:
    - Java
description: Spring_boot 的第一个应用
top:
---

## 生成项目

### 使用Intellij IDEA

点击菜单栏 File ➤New➤Project ➤ 选择 Spring Initializr 创建界面如下图，可以看到图中 default 指定的 Initializr Service URL 就是 Spring 官方提供的 Spring Initializr 工具地址，一般默认即可，所以这里创建的工程实际上也是基于它的 Web 工具来实现的。


关于工程的一些信息：

- Group 顾名思义就是你的公司名，一般是填写com.公司名。
- Artifact groupId 和 artifactId 是maven管理项目包时用作区分的字段，就像是地图上的坐标。这里填写项目名即可。
-Type 就是构建的项目类型，意思就是你希望你的项目使用什么工具构建，可选 maven 和 gradle 一般选 maven。
- Language 顾名思义就是你的项目用啥语言开发，可选 Java、Groovy、Kotlin
- Packaging 就是你希望你的项目打成什么形式的包，可选 Jar、War SpringBoot 项目一般选 Jar
- Java Version 意指项目使用的 java 版本，根据你的需要选择。
- Version 项目的初始版本，默认即可。
- Name 项目名称。
- Description 项目描述，默认即可。
- Package 包名，填完 Group 和 Artifact 后自动生成，默认即可。

选择需要的配置

其中web中的web必选

然后生成项目


### spring 官网

[spring.io](spring.io)网站包含很多Spring Boot"入门"指南，如果你正在找特定问题的解决方案，可以先去那瞅瞅。你也可以简化下面的步骤，直接从[start.spring.io](spring.io)的依赖搜索器选中web starter，这会自动生成一个新的项目结构。具体详情参考[文档](https://github.com/spring-io/initializr)。

## POM

创建Maven pom.xml文件，是构建爱你项目的处方。如下:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>com.example</groupId>
    <artifactId>myproject</artifactId>
    <version>0.0.1-SNAPSHOT</version>

    <parent>
        <groupId>org.springframework.boot</groupId>
        <artifactId>spring-boot-starter-parent</artifactId>
        <version>1.4.1.BUILD-SNAPSHOT</version>
    </parent>

    <!-- Additional lines to be added here... -->

    <!-- (you don't need this if you are using a .RELEASE version) -->
    <repositories>
        <repository>
            <id>spring-snapshots</id>
            <url>http://repo.spring.io/snapshot</url>
            <snapshots><enabled>true</enabled></snapshots>
        </repository>
        <repository>
            <id>spring-milestones</id>
            <url>http://repo.spring.io/milestone</url>
        </repository>
    </repositories>
    <pluginRepositories>
        <pluginRepository>
            <id>spring-snapshots</id>
            <url>http://repo.spring.io/snapshot</url>
        </pluginRepository>
        <pluginRepository>
            <id>spring-milestones</id>
            <url>http://repo.spring.io/milestone</url>
        </pluginRepository>
    </pluginRepositories>
</project>
```
这样一个可工作的构建就完成了，你可以通过运行mvn package测试它（暂时忽略"jar将是空的-没有包含任何内容！"的警告）。


## 编写代码

为了完成应用程序，我们需要创建一个单独的Java文件。Maven默认会编译src/main/java下的源码，所以你需要创建那样的文件结构，并添加一个名为src/main/java/Example.java的文件：

```java
// Example.java

import org.springframework.boot.*;
import org.springframework.boot.autoconfigure.*;
import org.springframework.stereotype.*;
import org.springframework.web.bind.annotation.*;

@RestController
@EnableAutoConfiguration

public class Example {

    @RequestMapping("/")
    String home() {
        return "Hello World!";
    }

    public static void main(String[] args) throws Exception {
        SpringApplication.run(Example.class, args);
    }

}
```

## 解析代码

### @RestController 和 @RequestMapping 注解


Example类上使用的第一个注解是@RestController，这被称为构造型（stereotype）注解。它为阅读代码的人提供暗示（这是一个支持REST的控制器），对于Spring，该类扮演了一个特殊角色。在本示例中，我们的类是一个web @Controller，所以当web请求进来时，Spring会考虑是否使用它来处理。

@RequestMapping注解提供路由信息，它告诉Spring任何来自"/"路径的HTTP请求都应该被映射到home方法。@RestController注解告诉Spring以字符串的形式渲染结果，并直接返回给调用者。

注：@RestController和@RequestMapping是Spring MVC中的注解（它们不是Spring Boot的特定部分），具体参考Spring文档的[MVC章节](http://mvc.linesh.tw/)。

### @EnableAutoConfiguration注解

第二个类级别的注解是@EnableAutoConfiguration，这个注解告诉Spring Boot根据添加的jar依赖猜测你想如何配置Spring。由于spring-boot-starter-web添加了Tomcat和Spring MVC，所以auto-configuration将假定你正在开发一个web应用，并对Spring进行相应地设置。

Starters和Auto-Configuration：Auto-configuration设计成可以跟"Starters"一起很好的使用，但这两个概念没有直接的联系。你可以自由地挑选starters以外的jar依赖，Spring Boot仍会尽最大努力去自动配置你的应用。

### main方法

应用程序的最后部分是main方法，这是一个标准的方法，它遵循Java对于一个应用程序入口点的约定。我们的main方法通过调用run，将业务委托给了Spring Boot的SpringApplication类。SpringApplication将引导我们的应用，启动Spring，相应地启动被自动配置的Tomcat web服务器。我们需要将Example.class作为参数传递给run方法，以此告诉SpringApplication谁是主要的Spring组件，并传递args数组以暴露所有的命令行参数。

## 运行代码

到此，示例应用可以工作了。由于使用了spring-boot-starter-parent POM，这样我们就有了一个非常有用的run目标来启动程序。在项目根目录下输入mvn spring-boot:run启动应用：

