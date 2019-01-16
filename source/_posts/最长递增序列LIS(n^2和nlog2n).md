---
title: 最长递增序列LIS(n^2和nlog2n)
date: 2018-03-27 00:33:00
tags: 动态规划
categories: C/C++
description: 给出一个数列，找出其中最长的单调递增子序列。O(n<sup>2</sup>)和O(nlog<sub>2</sub>n)两种方法。
---

### 例题：
>LIS是最长上升子序列。什么是最长上升子序列？ 
>就是给你一个序列，请你在其中求出一段最长严格上升的部分，它不一定要连续。
>就像这样：2, 3, 4, 7 和 2, 3, 4, 6 
>就是序列 2 5 3 4 1 7 6 的两个上升子序列，最长的长度是 4。

### O(n<sup>2</sup>)的方法:
对于每一个数，他都是在“可以接下去”的中，从前面的最优值+1转移而来。
{% asset_img LIS.png LIS最优 %}
代码示例如下：

```C++
#include<iostream>
#include<cstring>
using namespace std;
int f[10000], b[10000];
int lis(int n) {
    memset(f, 0, sizeof f);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j)
            if (b[j] < b[i]) {
                f[i]=max(f[i],f[j]+1);
        res = max(res, f[i]);
    }
    return res+1;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
    }
    printf("%d\n", lis(n));
    return 0;
}
```

### O(nlog<sub>2</sub>n)的方法:
我们回想一下，在上面O(n<sup>2</sup>)的程序中，哪些地方看起来比较费时？
没错，就是内层用于更新i的循环。因为每一次他都要查找一遍，效率并不高。
回到题目，我们发现，他只要我们求长度，所以，我们可以模拟一个栈。
所以每遇到一个比栈顶元素大的数，就放进栈里，遇到比栈顶元素小的就二分查找前边的元素，
找到一个“最应该被换掉的元素”，用新数去更新前边的元素。
这个算法不难证明也是正确的。因为前面每一次的枚举都换成了二分，
内层的复杂度从n降到了log<sub>2</sub>n，外层不变。所以总的复杂度是O(nlog<sub>2</sub>n)。
lis代码:

```C++
int lis(int n) {
     f[0]=b[0];
    int len=0;
    for(int i=1;i<n;i++)
    {
        if(b[i]>f[len])
            f[++len]=b[i];
        else
        {
            int j=lower_bound(f,f+len,b[i])-f;
            f[j]=b[i]; 
           // for(int k=0;k<len;k++)    
           // 	printf("%d ",f[k]);
        }
       // printf("\n");
    }
   return len+1;  
}
```
注释的代码是为了更好的理解这个算法。




