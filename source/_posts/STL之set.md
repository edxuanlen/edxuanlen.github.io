---
title: STL之set
date: 2018-03-28 22:48:14
tags: STL
categories: C/C++
description: set容器它会自动调节二叉树排列，把元素放到适合的位置，确保每个子树根节点的键值大于左子树所有的值、小于右子树所有的值，插入重复数据时会忽略。
---

### set容器
set是用红黑树的平衡二叉索引树的数据结构来实现的，插入时，它会自动调节二叉树排列，
把元素放到适合的位置，确保每个子树根节点的键值大于左子树所有的值、小于右子树所有的值，
插入重复数据时会忽略。set迭代器采用中序遍历，检索效率高于vector、deque、list，
并且会将元素按照升序的序列遍历。set容器中的数值，一经更改，set会根据新值旋转二叉树，
以保证平衡，构建set就是为了快速检索（python中的set一旦建立就是一个常量，不能改的）。
![平衡检索二叉树(set集合)示意图](https://ws1.sinaimg.cn/large/005xm8nggy1fpsxcunkc5j30fz09et9m.jpg)
**multiset，与set不同之处就是它允许有重复的键值。**

```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
	set<int>s;
	srand(time(NULL));  //生成随机数种子 
	for(int i=0;i<10;i++)
		s.insert(rand()%10);
	for(set<int>::iterator i=s.begin();i!=s.end();i++)
		printf("%d ",*i);
	cout<<endl;
	for(set<int>::reverse_iterator i=s.rbegin();i!=s.rend();i++)
		printf("%d ",*i);
	return 0;
}
```
运行结果：
{% asset_img set1.png %}
由于重复的被删去，所以可能输出不够十个数。而用上面把set改成上面提及的multiset就可以支持重复数字。
{% asset_img set2.png %}
在上面set的代码将set改为multiset即可。
```C++
#include<bits/stdc++.h>
using namespace std;
int main(){
	multiset<int>s;
	srand(time(NULL));  //生成随机数种子 
	for(int i=0;i<10;i++)
		s.insert(rand()%10);
	for(multiset<int>::iterator i=s.begin();i!=s.end();i++)
		printf("%d ",*i);
	cout<<endl;
	int a=rand()%10;
	cout<<"delete the num as :"<<a<<endl;
	int h=s.erase(a);      //multiset的erase函数删除所有要删除的数并返回个数
	cout<<"delete "<<h<<" "<<"\""<<a<<"\""<<endl;
	cout<<"after delete "<<a<<":";
	for(multiset<int>::reverse_iterator i=s.rbegin();i!=s.rend();i++)
		printf("%d ",*i);
	return 0;
}
```
运行结果:
{% asset_img set3.png %}

### set的重载
重载可改变排序依据。
set的重载会与priority_queue放一起比较，[详情点此跳转](https://edxuanlen.tk/2018/03/30/STL%E4%B9%8Bstack-queue/#set%E7%9A%84%E9%87%8D%E8%BD%BD)！
