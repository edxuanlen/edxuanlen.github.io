---
title: Spring-MVC
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-07-18 16:30:54
img:
coverImg:
password:
summary:
tags:
    - Java
    - Spring-MVC
categories:
    - Java
    - Spring
description: Spring MVC框架学习。
---

## ICO容器

装Bean  

容器中是怎么实现的？

```java 
Map iocMap = new HashMap();
OrderService orderService = new OrderService();
iocMap.put("orderService", orderService);
```

如何使用？

```java
@Autowired
private OrderService orderSerive; // 直接从iocMap.get("orderService")
```

### DispatherServlet


## Spring 流程

1. Springmvc -> mvn -> war -> tomcat/webapps -> startup.bat  

war  -------- spring-mvc.xml  --- basePackage = 'com.xxx'

1. 扫描 tomcat启动的时候到war下的com.xxx 包路径下找特殊注解的类如 @Controller @Service 
2. 生成对象，创建好的对象放在ioc容器中  
3. Bean的依赖注入
    查找哪个类里面存在依赖注入的关系
    ```java
    if(clzzIsController){
        for(Field field:fields){
            if(fieldIsAutowired){

            }
        }
    }
    ```

4. 路径方法一一映射
/test/query 一定存在控制类
先找到控制类，一定是有路径的
先把注解对应的路径拿到，先是controller然后是method 拼起来就是request url
然后再绑定到 map中 map.put("url", method);

url_port -> servlet -> doGet/doPost -> url -> map.get() -> method

## 拦截器和过滤器

### 区别

1. 拦截器是基于java的反射机制的，而过滤器是基于函数回调。
2. 拦截器不依赖与servlet容器，过滤器依赖与servlet容器。
3. 拦截器只能对action请求起作用，而过滤器则可以对几乎所有的请求起作用。
4. 拦截器可以访问action上下文、值栈里的对象，而过滤器不能访问。
5. 在action的生命周期中，拦截器可以多次被调用，而过滤器只能在容器初始化时被调用一次。
6. 拦截器可以获取IOC容器中的各个bean，而过滤器就不行，这点很重要，在拦截器里注入一个service，可以调用业务逻辑。

PS： 拦截器可以获取ioc中的service bean实现业务逻辑

过滤器和拦截器触发时机不一样: 过滤器是在请求进入容器后，但请求进入servlet之前进行预处理的。请求结束返回也是，是在servlet处理完后，返回给前端之前。  

### 用途

1. 过滤器
    过滤器可以拦截到方法的请求和响应（ServletRequest request, SetvletResponse response），并对请求响应做出响应的过滤操作，比如设置字符编码、鉴权操作
2. 拦截器
    拦截器可以在方法之前（preHandle）和方法执行之后（afterCompletion）进行操作，回调操作（postHandle），可以获取执行的方法的名称，请求（HttpServletRequest）。
3. AOP
    AOP操作可以对操作进行横向的拦截，最大的优势在于可以获取执行方法的参数，对方法进行统一的处理，常见使用日志，事务，请求参数安全验证等。

![2020-07-28-09-10-54](http://image.edxuanlen.cn/2020-07-28-09-10-54.png)

