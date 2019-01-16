---
title: 解决写wyh的矩阵出现内存占用超过限制的问题
date: 2018-04-06 16:58:13
tags: 
    - C/C++题目
categories: C/C++
description: 有时候在提交的时候总是会出现内存占用超过限制的问题，很多时候刚上手也不知道为什么会超过内存限制！而这篇文章将用一个例子讲述怎么查看内存使用。
---

[原题链接](https://www.nowcoder.com/acm/contest/93/B)
题目如下：
给你一个n*n矩阵，按照顺序填入1到n*n的数，例如n=5，该矩阵如下
1  2  3  4  5
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
现在让你连接相邻两条边的中点，然后只保留他们围成封闭图形区域的数字，那么这个矩阵变为
      3
   7  8  9 
11 12 13 14 15
   17 18 19 
      23
      
现在你们涵哥让你求变化后的矩阵的所有元素的和为多少

内存超过限制的代码:
```C++
#include<bits/stdc++.h>//数字
using namespace std;
typedef long long ll;
int a[9000][9000];
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int num=0,m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                a[i][j]=++num;
        int l=(m+1)/2-1;
        ll sum=0;
        for(int i=0;i<m;i++)
            for(int j=abs(l-i);j<m-abs(i-l);j++)
                sum+=a[i][j];
        printf("%lld\n",sum);
    }
    return 0;
}
```
**占用内存262145K**
题目对空间的限制是262144K，所以是没跑完的。
几次修改无果。。放弃了二维数组的做法
AC代码如下：
```C++
#include<bits/stdc++.h>//数字 
using namespace std;
typedef long long ll;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int num=0,m;
		scanf("%d",&m);
		int l=(m+1)/2-1;
		int h=l+1;
		ll sum=0;
		for(int i=0;i<m;i++){
			if(i<=l){
				if(i)	h=h+(m-1);
				for(int j=h;j<h+2*(l-abs(i-l))+1;j++)
					sum+=j;
			}
			else {
				if(i)	h=h+(m+1);
				for(int j=h;j<h+2*(l-abs(i-l))+1;j++)
					sum+=j;
			}
		}
		printf("%lld\n",sum);
//	
//	int availmb;
//    int totalmb;
// 
//    MEMORYSTATUS memstatus; 
// 
//    GlobalMemoryStatus(&memstatus);  
// 
//    availmb = memstatus.dwAvailPhys/1024/1024;      //可用物理内存总量
//    totalmb = memstatus.dwTotalPhys/1024/1024;      //物理内存总量
//    printf("可用内存为:%d MB，物理内存总量:%d MB\n",availmb,totalmb);
	}
	return 0;
}
```
**占用内存352K**
注释中的代码可以查看当前运行使用的内存大小！！！