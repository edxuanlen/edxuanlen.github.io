---
title: STL之stack&queue
date: 2018-03-30 00:47:44
tags:
  - STL
  - 栈
categories: C/C++
description: 本文介绍栈(stack)和队列(queue)以及优先级队列(priority_queue)。
---

### 栈(stack)
stack堆栈是一个**后进先出**的线性表插入和删除元素都只能在表的一端进行。
插入元素的一端称为栈顶(另一端称为栈底)。插入元素为入栈(Push)，删除为出栈(Pop)。
{% asset_img stack.png %}
过程就像压入和弹出数据。
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<int> s;
	//压入数据
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(5);
    cout << s.size() << endl;
    while(s.empty() != true){
        cout << s.top() << endl;
        s.pop();//弹出数据
    }
    return 0;
}
```
输出:
> 4
> 5 4 2 1

### 队列(queue)
queue队列容器是一个**先进先出**的线性存储表，元素插入只能在队尾，删除只能在队首。
将上面的代码 stack改为queue ，s.top改为s.front 可得到：
> 4
> 1 2 4 5

### 优先队列(priority_queue)
priority_queue与队列一样只能在队尾插入元素，队首删除元素，但是队首永远是队列中的最大元素。
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int> pq;
    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(8);
    pq.push(9);
    pq.push(0);
    cout << "size: " << pq.size() << endl;
    while(pq.empty() != true){
        cout << pq.top() <<" ";
        pq.pop();
    }
    return 0;
}
```
运行结果：
{% asset_img queue.png %}

### set和priority_queue的重载
#### set的重载
set的重载与sort函数的重载相似。
```C++
#include<bits/stdc++.h>
using namespace std;
struct Comp
{
    bool operator()(int a,int b)
    {
        return a > b;
    }
};
int main()
{
    set<int,Comp> v;
    v.insert(1);
    v.insert(3);
    v.insert(5);
    v.insert(2);
    v.insert(4);
    v.insert(3);
    for(set<int,Comp>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
    for(set<int,Comp>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
        cout << *rit << " ";
    cout << endl;
    return 0;
}
```
输出结果为：
> 5 4 3 2 1
> 1 2 3 4 5
#### priority_queue的重载
priority_queue的重载与set的重载差不多，但中间需要一个多一个容器作为参数(暂时我也不知道为啥==)。
```C++
#include<bits/stdc++.h>
using namespace std;
//重载
struct C{
	bool operator()(int a,int b){
		return a>b;
	}
} ;
int main(){
	priority_queue<int,vector<int>,C> pq;  //少了vector报错
    pq.push(1);
    pq.push(3);
    pq.push(2);
    pq.push(8);
    pq.push(9);
    pq.push(0);
    cout << "size: " << pq.size() << endl;
    while(pq.empty() != true){
        cout << pq.top() <<" ";
        pq.pop();
    }
    return 0;
}
```
数据与上面优先队列的例子相同，重载后输出结果为:
{% asset_img queue1.png %}
