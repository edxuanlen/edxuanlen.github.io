---
title: string 的使用
date: 2018-04-14 13:37:39
tags:	STL
categories: C/C++
description: string的处理
---

```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[101];

	while(gets(a)){
		string b=a;
		int i=0;
		transform(b.begin(),b.end(),b.begin(),::tolower);
		if(!b.find("lovelive"))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}

```
