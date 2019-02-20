---
title: STL之vector
date: 2018-03-28 10:21:06
tags: STL
categories: C/C++
description: 介绍动态数组vector的一些基本特性
---

### vector之insert、erase
vector有内存管理的机制，也就是说对于插入和删除，vector可以动态调整所占用的内存空间。
常用相关函数insert、erase如下：

```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v;
	for(int i=0;i<10;i++)
		v.push_back(i); //在数组尾部插入数字
	vector<int> a(10);
	for(int i=0;i<10;i++)
		a[i]=10-i;

	printf("a[i] v[i]\n");
	for(int i=0;i<10;i++)
		printf("%2d   %2d\n",a[i],v[i]);
	//在第一个元素之前插入111  insert begin+n是在第n个元素之前插入
	v.insert(v.begin()+5,10);
	v.insert(v.end()-5,10);
	printf("insert 插入v[i]后:  ");
	//iterator迭代器
	for(vector<int>::iterator i=v.begin();i<v.end();i++)
		printf("%d ",*i);
	//在最后一个元素之后插入222 insert end + n 是在n个元素之后插入
	printf("\nerase 删除单个数字后:  ");
	a.erase(a.begin()+4);
	for(vector<int>::iterator i=a.begin();i<a.end();i++)
		printf("%d ",*i);
	printf("\nerase 删除范围数字后:  ");
	 a.erase(a.begin(),a.begin()+4);//删除这一范围内的数字
	for(vector<int>::iterator i=a.begin();i<a.end();i++)
		printf("%d ",*i);
	return 0;
}
```

运行截图如下:
{% asset_img vector.png %}

### vector之push_back、back、reverse、size
```C++
#include<bits/stdc++.h>
using namespace std;
int main (){
	vector<int> a;
	int sum (0);
 	for (int i=0;i<10;i++)
		a.push_back(i);	//结尾压入数据
	printf("%d\n",a.size());
	reverse(a.begin(),a.end());  
	for (int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
  	while (!a.empty()){
    	 sum += a.back();
    	 a.pop_back();  //弹出最后压入的数据 (不受reverse影响)
    	 printf("%d ",a.size());
	}
	printf("\n%d\n",a.size());
  	cout << "total: " << sum << '\n';
	return 0;
}
```

运行结果
{% asset_img vector1.png %}

### 求和accumulate
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    for(int i = 0; i < 10; ++i )
        v.push_back(i);
    cout << accumulate(v.begin(),v.end(),0) << endl;
    return 0;
}
```
运行结果
> 45
