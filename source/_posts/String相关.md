---
title: String相关
author: edxuanlen
top: false
cover: false
toc: true
mathjax: false
date: 2020-08-07 10:57:00
img:
coverImg:
password:
summary:
tags:
    - Java
    - String
categories:
    - Java
    - Interview
description: String 和 String Builder， String Buffer的一些区别和String 的一些问题。
---

## 比较

### String

#### 非常用，但有用的方法

- indexOf 字符第一次出现位置
- lastIndexOf
- replace 支持字符或字符串替换
- replaceAll 支持正则匹配替换

String 不可继承原因是 字符数组用final修饰
contact replace等操作都会返回一个新的String 对象


#### 默认编码

系统默认编码  UTF-8 中文 三个字符（不一定）

### String Buffer

transient 修饰字符数组

所有方法几乎都加了synchronized

可修改

线程安全带来的缺点是效率相对StringBuilder而言更低


### String Builder

StringBuilder是StringBuffer的特殊优化版本，不考虑线程安全，效率最高。


## 面试题


1. 

```JAVA
String a = "hello2";
String b = "hello" + 2;
System.out.println("a == b: " + (a == b));
System.out.println("equals: " + a.equals(b));
System.out.println("identityHashCode: " + System.identityHashCode(a) + ": " + System.identityHashCode(b));

a = "hello2";
b = "hello";
String c = b + 2;
System.out.println("a == b: " + (a == c));
System.out.println("equals: " + a.equals(c));
System.out.println("identityHashCode: " + System.identityHashCode(a) + ": " + System.identityHashCode(c));

String aa = "hello2";
final String bb = "hello";
String cc = bb + 2;
System.out.println("a == b: " + (aa == cc));
System.out.println("equals: " + aa.equals(cc));
System.out.println("identityHashCode: " + System.identityHashCode(aa) + ": " + System.identityHashCode(cc));

```

第一个是true。第二个是false。
原因是编译后的字节码中，编译器自动把第一个的String b优化成 String b = "hello2";
第二个则是对引用拼接；

第三个是true;
对于被final修饰的变量，会在class文件常量池中保存一个副本，也就是说不会通过连接而进行访问，对final变量的访问在编译期间都会直接被替代为真实的值。那么String c = b + 2;在编译期间就会被优化成：String c = "hello" + 2。

```JAVA
String a = "hello";
String b =  new String("hello");
String c =  new String("hello");
String d = b.intern();
    
System.out.println(a==b);
System.out.println(b==c);
System.out.println(b==d);
System.out.println(a==d);
```

false; false; false; true;


### StringBuilder

默认长度是16，调用父类AbstractStringBuilder的构造方法

```Java
public StringBuilder() {
    super(16);
}
```

value存储是char[] 类型

```Java
AbstractStringBuilder(int capacity) {
    value = new char[capacity];
}
```

append时，调用ensureCapacityInternal 确定内部空间是否足够

```java
public AbstractStringBuilder append(String str) {
    if (str == null)
        return appendNull();
    int len = str.length();
    ensureCapacityInternal(count + len);
    str.getChars(0, len, value, count);
    count += len;
    return this;
}
```

判断是否空间足够，不足够的时候将StringBuilder进行拷贝到新的字符数组

```Java
private void ensureCapacityInternal(int minimumCapacity) {
    // overflow-conscious code
    if (minimumCapacity - value.length > 0) {
        value = Arrays.copyOf(value,
                newCapacity(minimumCapacity));
    }
}
```

newCapacity = value * 2 + 2，如果还不够，那就直接等于所需要的空间，如果还不够，造nnewCpacity溢出或者已经超过MAX_ARRAY_SIZE，则调用hugeCapacity

```Java
private int newCapacity(int minCapacity) {
    // overflow-conscious code
    int newCapacity = (value.length << 1) + 2;
    if (newCapacity - minapacity < 0) {
        newCapacity = minCapacity;
    }
    return (newCapacity <= 0 || MAX_ARRAY_SIZE - newCapacity < 0)
        ? hugeCapacity(minCapacity)
        : newCapacity;
}
```

都溢出int了 抛出OOM异常，如果minCapacity 大于MAX_ARRAY_SIZE，没超过Integer.MAX_VALUE，那我们就用minCapacity
PS：但是其实MAX_ARRAY_SIZE 定义为 Integer.MAX_VALUE - 8 所以.... 就很迷惑，这波操作太奇怪了

```Java
private int hugeCapacity(int minCapacity) {
    if (Integer.MAX_VALUE - minCapacity < 0) { // overflow
        throw new OutOfMemoryError();
    }
    return (minCapacity > MAX_ARRAY_SIZE)
        ? minCapacity : MAX_ARRAY_SIZE;
}
```
