---
title: Catch That Cow
date: 2018-03-31 20:17:43
tags: 
    - BFS
    - STL
categories: C/C++
description: 3D立体迷宫，判断是否有出路，并算出最短时间。使用了广度搜索优先和队列。
---
[原题链接](http://poj.org/problem?id=2251)
### 题目内容

> **Description**
You are trapped in a 3D dungeon and need to find the quickest way out! The dungeon is composed of unit cubes which may or may not be filled with rock. It takes one minute to move one unit north, south, east, west, up or down. You cannot move diagonally and the maze is surrounded by solid rock on all sides. 
Is an escape possible? If yes, how long will it take? 
<br>
**Input**
The input consists of a number of dungeons. Each dungeon description starts with a line containing three integers L, R and C (all limited to 30 in size). 
L is the number of levels making up the dungeon. 
R and C are the number of rows and columns making up the plan of each level. 
Then there will follow L blocks of R lines each containing C characters. Each character describes one cell of the dungeon. A cell full of rock is indicated by a '#' and empty cells are represented by a '.'. Your starting position is indicated by 'S' and the exit by the letter 'E'. There's a single blank line after each level. Input is terminated by three zeroes for L, R and C.
<br>
**Output**
Each maze generates one line of output. If it is possible to reach the exit, print a line of the form 
Escaped in x minute(s).
where x is replaced by the shortest time it takes to escape. 
If it is not possible to escape, print the line 
Trapped!

> **Sample Input**
> <br>
> 3 4 5
> S....
> .###.
> .##..
> ###.#  
> <br>
> #####
> #####
> ##.##
> ##.\..  
> <br>
> #####
> #####
> #.###
> ####E  
> <br>
> 1 3 3
> S##
> #E#
> ###
> <br>
> 0 0 0

> **Sample Output**
> <br>
> Escaped in 11 minute(s).
> Trapped!

题解:
```C++
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int L,R,C;
char a[31][31][31];
bool vis[31][31][31];
int sx,sy,sz,ex,ey,ez;
struct node{
    int x,y,z,step;
};
int d[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int bfs(){
	queue<node>q;
	node now,next;
	now.x=sx;now.y=sy;now.z=sz,now.step=0;
	vis[now.x][now.y][now.z]=true;
	q.push(now);
    while(!q.empty()){
        now=q.front();
        q.pop();
        if(now.x==ex&&now.y==ey&&now.z==ez)
            return now.step;
        for(int i=0;i<6;i++)
        {
            next.x=now.x+d[i][0];
            next.y=now.y+d[i][1];
            next.z=now.z+d[i][2];
            if(a[next.x][next.y][next.z]!='#'&&next.x>=0&&next.x<L&&next.y>=0)
                if(next.y<R&&next.z>=0&&next.z<C&&!vis[next.x][next.y][next.z]){
                //分开写是因为太长了  比较难看=。=
                vis[next.x][next.y][next.z]++;
                next.step=now.step+1;
                q.push(next);
            }
        }
    }
    return 0;
}
int main() {
	while(scanf("%d %d %d",&L,&R,&C),L){
		memset(a,'\0',sizeof(a));
		memset(vis,false,sizeof(vis)); 
		
		for(int l=0;l<L;l++){
			getchar();
			for(int r=0;r<R;r++){
				for(int c=0;c<C;c++){
					a[l][r][c]=getchar();
					 if(a[l][r][c]=='S') {
                        sx=l;
                        sy=r;
                        sz=c;
                    }
                    if(a[l][r][c]=='E'){
                        ex=l;
                        ey=r;
                        ez=c;
                    }
				}
				getchar();
			}
		}
		int ans=bfs();
		if(ans)
			printf("Escaped in %d minute(s).\n",ans);
		else
			printf("Trapped!\n");
	}
	return 0;
}
```

已AC....by edxuanlen

