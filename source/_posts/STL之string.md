---
title: STL之string
date: 2018-03-28 11:33:20
tags: STL
categories: C/C++
description: string的常用函数以及int和string的转换。
---

### string的insert、erase和clear

```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;char ss[1000];
	gets(ss);//无法直接gets string 
	s=ss;
	//尾部添加字符字符串直接用+号 或者使用append()
	s+=" wo";
	s.append("rld!");
	cout<<"insert添加后:  "<<s<<endl;
	string::iterator i=s.begin();
	s.erase(s.begin()+5,i+12);
	cout<<"erase删除后:  "<<s<<endl;
	s.clear();
	cout<<"clear后:"<<s;
	return 0;
}
```

### string的find
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){  
   string s="what are you dong";  
   string s1="are "; 
   if(s.find(s1)<0)   //找不到返回-1
		cout<<"not find"<<endl;  
   else  //找到返回位置
    	cout<<"position= "<<s.find(s1)+1<<endl;  
   return 0;  
}  
```
运行结果
> position= 6


### string数字处理
c++11标准增加了全局函数std::to_string:
```C++
#include<bits/stdc++.h>
using namespace std;
void StrToInt(){
	string s="87654321";
	int a=stoi(s);
	printf("%d\n",a);
} 
void IntToStr(){
	int a=12345678;
	string s;
	s=to_string(a);
	cout<<s<<endl;
}
int main(){
	StrToInt();
	IntToStr();	
	return 0;
}
```

运行结果
> 87654321
> 12345678


### sscanf分离
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    char s[6]="4,5$6";
    sscanf(s,"%d,%d$%d",&a,&b,&c);
    cout << a << " " << b << " " << c << endl;
    return 0;
}
```

运行结果:
> 4 5 6






































