---
title: Linux_Communication 
date: 2018-03-31 20:17:43
tags: 
    - Linux
categories: 系统
description: linux 通信，操作系统的一些学习记录。
---


## 使用信号

信号在头文件signal.h中定义，信号都以SIG开头
常用信号有

- SIGALRM (由alarm函数设置的定时器产生)
- SIGHUP由一个处于非连接状态的终端发送给控制进程，或者由控制进程在自身结束时发送给每个前台进程
- SIGINT一般由Ctrl+C或者预先设置好的终端字符产生
- SIGPIPE如果向管道写数据时没有与之对应的读进程产生的信号
- SIGTERM作为一个请求被发送，要求进程结束运行。(是KILL命令默认发送的信号)
- SIGUSR1,SIGUSR2进程之间可以用这个信号进行通信，例如让进程报告状态信息

### 信号处理--signal函数

```C++
# include <bits/stdc++.h>
# include <unistd.h>

// 原型
// void (*signal(int sig, void (*func)(int)))(int);
void handle(int sign){
    //sign 是信号类型
    signal(SIGINT, SIG_DFL); // 恢复终端中断信号的默认行为
}

int main(){
    //改变终端中断信号SIGINT的默认行为，使之执行handle函数
	signal(SIGINT, handle);
    while (true){
        printf("i'm running\n");
        sleep(1);
    }
    return 0;
}
```

### 信号处理--sigaction函数

```C++
# include <bits/stdc++.h>
# include <unistd.h>

// 原型
// int sigaction(int sig, const struct sigaction *act, struct sigaction *oact);

# include <bits/stdc++.h>
#include <unistd.h>

void handle(int sign){
}

int main(){
    struct sigaction act;
    act.sa_handler = handle;
    // 创建空的信号屏蔽集，即不屏蔽任何信息
    sigemptyset(&act.sa_mask);
    // 使sigaction函数重置为默认行为
    act.sa_flags = SA_RESETHAND;
    sigaction(SIGINT, &act, 0);
    while (true){
        printf("i'm running\n");
        sleep(1);
    }
    return 0;
}
```

### 发送信号--kill & alarm

```C++
# include <bits/stdc++.h>
using namespace std;

// int kill (pid_t pid, int sig);
// unsigned int alarm(unsigned int seconds);
```

> kill调用失败返回-1，调用失败通常有三大原因：
> 给定的信号无效（errno = EINVAL)
> 发送权限不够( errno = EPERM ）
> 目标进程不存在( errno = ESRCH )

## 使用信号量

### semget函数

```C++
// 原型
// int semget(key_t key, int num_sems, int sem_flags);
// int semop(int sem_id, struct sembuf *sem_opa, size_t num_sem_ops);
// semctl

```
