---
title: Dungeon Master
date: 2018-03-31 20:18:01
tags: 
    - BFS
    - STL
categories: C/C++
description: 人抓牛，三种状态。使用BFS和队列可以解决问题。
---
[原题链接](http://poj.org/problem?id=3278)
### 题目内容

> **Description**
Farmer John has been informed of the location of a fugitive cow and wants to catch her immediately. He starts at a point N (0 ≤ N ≤ 100,000) on a number line and the cow is at a point K (0 ≤ K ≤ 100,000) on the same number line. Farmer John has two modes of transportation: walking and teleporting.
* Walking: FJ can move from any point X to the points X - 1 or X + 1 in a single minute
* Teleporting: FJ can move from any point X to the point 2 × X in a single minute.
If the cow, unaware of its pursuit, does not move at all, how long does it take for Farmer John to retrieve it?
<br>
**Input**
Line 1: Two space-separated integers: N and K
<br>
**Output**
Line 1: The least amount of time, in minutes, it takes for Farmer John to catch the fugitive cow.

> **Sample Input**
> <br>
5 17

> **Sample Output**
> <br>
4

> **Hint**
The fastest way for Farmer John to reach the fugitive cow is to move along the following path: 5-10-9-18-17, which takes 4 minutes.

题解:
```C++
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
queue<int> q;
bool vis[100001];
int step[100001];
int n,k;
int bfs(){
	q.push(n);
	vis[n]=true;
	while(!q.empty()){
		n=q.front();
		q.pop();
		int nn=n;
		for(int i=0;i<3;i++){
			if(i==0) n=nn+1;
			else if(i==1) n=nn-1;
			else n=nn*2;
			if(n>=0&&n<=100000&&!vis[n]){
				q.push(n);
				step[n]=step[nn]+1;
				vis[n]=true;
			}
			if(n==k)return step[n];
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&k)!=EOF){
		memset(vis,false,sizeof(vis));
		while(!q.empty())q.pop();
		printf("%d\n",bfs());
	}
	return 0;
}
```

已AC....by edxuanlen

