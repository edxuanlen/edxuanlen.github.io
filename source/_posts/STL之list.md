---
title: STL之list
date: 2018-03-29 18:37:29
tags: STL
categories: C/C++
description: list与数据结构中的双向链表有点相似。
---

### list
list的插入，遍历，删除，查找，排序都与vector容器相似。下面直接在实例中展示。
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int>l,l1;
    for(int i=0;i<3;i++)
    	l1.push_back(i*i);
    l.push_back(3);
    l.push_front(1);
    l.insert(++l.begin(),2);  //list 的迭代器只能++--不能+n-n 
    l.insert(l.end(),l1.begin(),l1.end());
    // 正向遍历 
	for(list<int>::iterator i=l.begin();i!=l.end();i++)
    	cout<<*i<<" ";  
    cout<<endl;
    //  反向遍历 
    for(list<int>::reverse_iterator i=l.rbegin();i!=l.rend();i++)
    	cout<<*i<<" ";
    cout<<endl;
    // 排序&去重 
	l.sort();
	l.unique();
	for(list<int>::iterator i=l.begin();i!=l.end();i++)
    	cout<<*i<<" ";
    cout<<endl;
    //查找元素以及删除迭代器位置的元素 
    l.erase(find(l.begin(),l.end(),4));
    for(list<int>::iterator i=l.begin();i!=l.end();i++)
    	cout<<*i<<" ";
    cout<<endl;
    srand(time(0));
    // pop首、尾的弹出 
    for(int i=0;i<4;i++){
    	if(i%2)
			l.pop_back();
		else l.pop_front();
		for(list<int>::iterator i=l.begin();i!=l.end();i++)
    		cout<<*i<<" ";
		cout<<endl;
	}
    return 0;	
}
```
运行结果：
{% asset_img list.png %}

**主要注意点是list的迭代器只能用++ -- 到达想要的位置**
