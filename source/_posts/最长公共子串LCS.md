---
title: 最长公共子串LCS
date: 2018-03-27 08:36:12
tags: 动态规划
categories: C/C++
description: 解决最长公共子序列（LCS）问题，即求字符串A，B的公共子序列LCS。
---

### 算法思路
我们首先想到的肯定是暴力枚举法。
先来看看：假设序列A有n 个元素，序列B有 m 个元素，那么A，B分别有2^n，2^m个子序列，
如果任意两个子序列一一比较，比较的的子序列高达2^(m+n)对，这还没有算具体的复杂度。
所以我们可以试试动态规划，把这个问题分解成子问题：
求A的前i个元素和B的前j个元素之间的最长公共子序列长度。这时的空间复杂度为O(m+n)。
**算法思想** 
1. 定义dp [i][j]：表示字符串序列A的前i个字符组成的序列Ax和字符串序列B的前j个字符组成
的序列By之间的最长公共子序列L(i,j )的长度（m ，n分别为Ax和By的长度，i<=m,j<=n）
2. 如果Ax [i] =By [j]，那么Ax与By之间的最长公共子序列L( i,j )的最后一项一定是这个元素，
所以dp [i][j] = dp[i-1][j-1] + 1。
3. 如果Ax[i] != By[j]，设LCS（i-1,j-1)是L( i -1, j-1 )的最后一个元素，
或者L（i-1,j-1）是空序列，则 t!= Ax[i]和t!=By[j]至少有一个不成立。
    (1). 当 LCS（i-1,j-1) != Ax[i] 时，dp[i][j]= dp[i-1][j]；
    (2). 当 LCS（i-1,j-1) != By[j] 时，ap[i][j]= dp[i][j-1]；
   所以dp[i][j]= max ( dp[i-1][j]，dp[i][j-1] )。
4. 初始值为：dp[0][j] = dp[i][0] = 0.
5. 题意要求求出任意一个最长公共子序列，这点要如何实现呢？
   仍然考虑上面的递推式，L（i,j）的最后一个元素LCS( i，j )的来源有三种情况，定义数组flag[MAXN][MAXN]用以标记来的方向：
   (1). dp[i][j] = dp[i-1][j-1] + 1，对应字符LCS( i-1,j-1)接上LCS( i,j)，flag[i][j] = 1,表示从斜向上左方来；
   (2). dp[i][j] = dp[i-1][j]，对应字符LCS（i-1,j）接上LCS（i,j），flag[i][j] = 2,表示从/上方过来；
   (3). dp[i][j] = dp[i][j-1]，对应字符LCS（I,j-1）接上LCS（i,j），flag[i][j] = 3,表示从左方过来。
    **我们只要在计算dp[i][j]时根据来源进行不同的标记，回溯就可以找到一个最长公共子序列。**
{% asset_img lcs.png LCS示意图 %}
```C++
#include<bits/stdc++.h>
char a[500],b[500];
int lcs[501][501]; 	///记录中间结果的数组
int flag[501][501];    ///标记数组，用于标识下标的走向，构造出公共子序列
void LCS(){ ///动态规划求解
    int i,j;
    for(i=1;i<=strlen(a);i++)
        for(j=1;j<=strlen(b);j++)
            if(a[i-1]==b[j-1]){
                lcs[i][j]=lcs[i-1][j-1]+1;
                flag[i][j]=1;  ///斜向下标记
            }
            else if(lcs[i][j-1]>lcs[i-1][j]) {
                lcs[i][j]=lcs[i][j-1];
                flag[i][j]=2;  ///向右标记
            }
            else {
                lcs[i][j]=lcs[i-1][j];
                flag[i][j]=3;  ///向下标记
            }
}
void getLCS(){///采用倒推方式求最长公共子序列
    char res[500];
    int i=strlen(a);
    int j=strlen(b);
    int k=0;    ///用于保存结果的数组标志位
    while(i>0 && j>0){
        if(flag[i][j]==1){     ///如果是斜向下标记
            res[k]=a[--i];
            k++;
            j--;
        }
        else if(flag[i][j]==2)  ///如果是向右标记
            j--;
        else if(flag[i][j]==3)  ///如果是向下标记
            i--;
    }
    for(i=k-1;i>=0;i--)
        printf("%c",res[i]);
}
int main(){
    int i;
    strcpy(a,"ABCBDAB");
    strcpy(b,"BDCABA");
    memset(lcs,0,sizeof(lcs));
    memset(flag,0,sizeof(flag));
    LCS();
    printf("%d\n",lcs[strlen(a)][strlen(b)]);
    getLCS();
    return 0;
}
```
运行结果:
{% asset_img lcs1.png %}
