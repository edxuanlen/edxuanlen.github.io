---
title: STL之map
date: 2018-03-29 12:01:49
tags: STL
categories: C/C++
description: map也是使用红黑树，是一个键值对(key:value映射)，遍历时依然默认按照key程序的方式遍历(与set相同)。
---

### map映照容器

{% asset_img map1.png %}
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
	map<string,double>m;
	m["li"]=123.4;
	m["wang"]=23.1;
	m["zhang"]=-21.9;
	m["abc"]=12.1;
	for(map<string,double>::iterator i=m.begin();i!=m.end();i++)
		cout<<(*i).first<<":"<<(*i).second<<endl;
	return 0; 
}
```
运行结果：
{% asset_img map.png %}


### map实现数字分离
#### string->number
下面给出例子，可以实现超级大数的每位相加！！！
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<char,int> m;
    for(int i = 0; i < 10; ++i)
        m['0' + i] = i;
    string s;
    s = "9876543210123456789876543210123456789";
    int sum = 0;
    for( int i = 0; i < s.size(); ++i)
        sum += m[s[i]];
    cout << sum << endl;
    return 0;
}
```
运行结果：
> 171

#### number->string
与上面的转换原理相同。
```
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<long long int,char> m;
    long long i;
    for(i = 0; i < 10; ++i){
        m[i] = '0' + i;
    }
    long long  n[10] ={1,2,3,4,5,6,7,8,9,0};
    for(int i=0;i<10;i++)
   		cout <<m[n[i]] ;
    return 0;
}
```
运行结果：
> 1234567890

### multimap
multimap与map的关系和multiset与set的关系相同，允许重复的元素，所以元素的插入删除和查找都与map不同。
>  multimap<string,double> m;
>  m.insert(pair<string,double>("Abc",123.2));
上述插入方法同样适用于map。

### find & erase

在上面的代码加上
``C++ printf("%d",m.find('5')->second);``
可以得到‘5’对应的数字 5。

```C++ m.erase("1");```
会使这一个map删除。












