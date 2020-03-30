---
title: STL之sort和unique
date: 2018-03-28 23:39:29
tags: STL
categories: C/C++
description: 常用的排序(升降序)和去重函数。
---

```C++
#include<bits/stdc++.h> 
using namespace std;
bool hh(int a,int b){	//改sort规则为降序 
	return a>b;
}
int main(){
	int a[13]={1,3,6,6,8,5,7,4,9,4,2,3};
	int i;
	for(i=0;i<12;i++)
		printf("%d ",a[i]);
		
	printf("\nafter sort:");
	sort(a,a+12);	//默认升序 
	for(i=0;i<12;i++)
		printf("%d ",a[i]);
		
	printf("\nafter sort:");
	sort(a,a+12,hh);
	for(i=0;i<12;i++)
		printf("%d ",a[i]);
	
	printf("\nafter unique:");
	int ans=unique(a,a+12)-a;
	for(i=0;i<ans;i++)
		printf("%d ",a[i]);
	return 0;
}
```
运行结果:
{% asset_img sort&unique.png %}