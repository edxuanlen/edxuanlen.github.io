---
title: Spring
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-08-10 13:46:33
img:
coverImg:
password:
summary:
tags:
    - Java
    - Spring
    - Interview
categories:
    - Java
    - Spring
    - Interview
description:
---


## Spring

### 你了解Spring IOC吗

IOC(Inversion of Control): 控制反转

- Spring Core最核心的部分
- 需要先了解依赖注入(DI)

#### 依赖注入

DI: 将底层类作为参数传递给上层类，实现上层对下层的"控制"

IOC: DI和DL

DL: 因为需要用户实现API所以被移除

#### 注入的方式

- Setter
- Interface
- Constructor
- Annotation

IOC容器的优势

- 避免在各处使用new来创建类，并且可以做到统一维护
- 创建实例的时候不需要了解其中的细节

#### Spring IOC支持的功能

- 依赖注入
- 依赖检查
- 自动装配
- 支持集合
- 指定初始化方法和销毁方法
- 支持回调方法

#### Spring Bean

BeanDefinition: 主要用来描述Bean的
BeanDefinitionRegistry: 提供向IOC容器注册BeanDefinition对象的方法

** BeanFactory **: Spring框架最核心的接口

- 提供IOC的配置机制
- 包含Bean的各种定义，便于实例化Bean
- 建立Bean之间的依赖关系
- Bean生命周期的控制

##### BeanFactory与ApplicationContext的比较

- BeanFactory是Spring框架的基础设施
- ApplicationContext面向Spring开发者

继承多个接口

- BeanFactory: 能够管理、装配Bean
- ResourcePatternResolver: 能够加载资源文件
- MessageSource: 能够实现国际化等功能
- ApplicationEventPublisher: 能够注册监听器，实现监听机制


##### Spring Bean 的作用域

作用域

- singleton: Spring默认的作用域，容器里拥有唯一的Bean实例
- prototype: 针对每个getBean请求，容器都会创建一个bean实例
- request: 会为每个HTTP请求创建一个Bean
- session: 会为每个session创建一个Bean
- globalSession: 会为每个全局Http Session创建一个Bean实例，该作用域仅对Portlet有效

##### Spring Bean 的生命周期


### AOP

关注点分离: 不同的问题交给不同的部分去解决

- 面向切面编程AOP正是这种技术的体现
- 通用化功能代码的实现，对应的就是所谓的切面(Aspect)
- 业务功能和切面代码分开,架构将变得高内聚低耦合
- 确保功能的完整性: 切面最终需要合并到业务中(Weave)

#### AOP的三种织入

- 编译时织入: 需要特殊的Java编译器，如AspectJ
- 类加载时织入: 需要特殊的Java编辑器，如AspectJ,AspectWerkz
- 运行时织入: Spring采用的方式，通过动态代理的方式，实现简单



### 七个事务传播属性  

什么是事务传播属性  
传播两个方法: 两个方法都带事务，但是事务设置不同。

为什么要事务？
事务是为解决数据安全操作提出的，事务控制实际上就是控制数据的安全访问。

|传播行为|含义|
|:---:|:---:|
|propagation_required（xml文件中为required)|表示当前方法必须在一个具有事务的上下文中运行，如有客户端有事务在进行，那么被调用端将在该事务中运行，否则的话重新开启一个事务。（如果被调用端发生异常，那么调用端和被调用端事务都将回滚）|
|propagation_supports(xml文件中为supports)|表示当前方法不必需要具有一个事务上下文，但是如果有一个事务的话，它也可以在这个事务中运行|
|propagation_mandatory(xml文件中为mandatory)|表示当前方法必须在一个事务中运行，如果没有事务，将抛出异常|
|propagation_nested(xml文件中为nested)|表示如果当前方法正有一个事务在运行中，则该方法应该运行在一个嵌套事务中，被嵌套的事务可以独立于被封装的事务中进行提交或者回滚。如果封装事务存在，并且外层事务抛出异常回滚，那么内层事务必须回滚，反之，内层事务并不影响外层事务。如果封装事务不存在，则同propagation_required的一样|
|propagation_never（xml文件中为never)|表示当方法务不应该在一个事务中运行，如果存在一个事务，则抛出异常|
|propagation_requires_new(xml文件中为requires_new)|表示当前方法必须运行在它自己的事务中。一个新的事务将启动，而且如果有一个现有的事务在运行的话，则这个方法将在运行期被挂起，直到新的事务提交或者回滚才恢复执行。|
|propagation_not_supported（xml文件中为not_supported)|表示该方法不应该在一个事务中运行。如果有一个事务正在运行，他将在运行期被挂起，直到这个事务提交或者回滚才恢复执行|

### Spring中的事务隔离级别

|隔离级别|含义|
|:----:|:----:|
|isolation_default|使用数据库默认的事务隔离级别|
|isolation_read_uncommitted|允许读取尚未提交的修改，可能导致脏读、幻读和不可重复读|
|isolation_read_committed | 允许从已经提交的事务读取，可防止脏读、但幻读，不可重复读仍然有可能发生|
|isolation_repeatable_read|对相同字段的多次读取的结果是一致的，除非数据被当前事务自生修改。可防止脏读和不可重复读，但幻读仍有可能发生|
|isolation_serializable |完全服从acid隔离原则，确保不发生脏读、不可重复读、和幻读，但执行效率最低。|

除了default另外四个与JDBC的隔离级别相对应。

### 高并发如何修改同一行数据

#### jvm解决

1. jvm 下用synchronized锁。


2. lock 锁

try lock finally unlock

JVM 解决不了分布式环境多任务对共享资源竞争的协同操作问题

#### 分布式解决

分布式锁 三种实现方式

- 数据库 (性能差)
- redis (死锁)
- zookeeper
    - 基于异常 (临时节点)
    - 基于相互监听 (性能比较高，占用资源，临时有序节点)

##### Zookeerper 数据结构

- Zookeeper 数据结构类似Linux  
- 每一个节点都有值  
