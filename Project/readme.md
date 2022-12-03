# readme

> 此文件夹(project)是用来练习代码的
> 将程序放在这个目录底下，或者在这个文件夹下写程序
> 然后修改配置文件，就可以测试

## 环境搭建

因为我们编译需要编译器
所以我们需要配置c语言的编译器到系统环境中

- 首先下载mingw-64编译器[网址1](https://gytx.lanzoui.com/iy906s48llc) [网址2](https://cloud.189.cn/web/share?code=yU7bMvJbAbYz)
- 解压到任一目录，记下目录
- 然后添加到系统环境中
- 打开cmd，输入gcc，若不报错说明配置完成

## 以顺序线性表为例

在文件夹下新建`SqList.c`和`SqList.h`

### 写一个简单的demo

在`SqList.h`写下线性表的顺序存储结构和初始化顺序表的声明

```c
#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 10        //初始内存空间分配量
typedef int DataType;       //成员数据类型，可修改
typedef enum{false,true} bool;  //返回类型(使用gcc编译器时，C语言(c98)没有bool型，所以自己定义)
typedef struct
{
    DataType* data;
    int length;
}SqList;

bool initList(SqList *L);                                               //初始化线性表(内存空间)

# endif
```

在`SqList.c`写下初始化顺序表的定义函数，和我们的`main`函数用来测试

```c
#include "SqList.h"

bool initList(SqList *L)
{
    L->data=(DataType *)malloc(sizeof(DataType)*LIST_SIZE); //malloc提前分配动态内存空间给线性表使用
    if(L->data==NULL) //查看是否分配，防止分配到指针为NULL的空间
    {
        printf("init List failed\n"); //可注释
        return false; //分配失败
    }
    L->length=0; //成员参数初始化
    printf("init List success\n"); //可注释
    return true; //分配成功
}



int main(void)
{
    SqList L;
    initList(&L);
    return 0;
}

```

### 配置json文件

接下来我们需要配置`.vscode`底下的`launch.json`和`tasks.json`文件
`tasks.json`是编译相关的配置文件
`launch.json`是调试相关的配置文件

- `tasks.json` 编译相关

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: gcc.exe 生成活动文件",
            "command": "D:\\mingw64\\bin\\gcc.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ],
    "version": "2.0.0"
}
```

首先我们需要配置我们的编译器路径
`"command": "D:\\mingw64\\bin\\gcc.exe"`
`args` 是调用gcc后面带的参数，这里我们不动 


- `launch.json`

```json
{
    // 使用 IntelliSense 了解相关属性。 
    // 悬停以查看现有属性的描述。
    // 欲了解更多信息，请访问: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++.exe - 生成和调试活动文件",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "D:\\mingw64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "为 gdb 启用整齐打印",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: g++.exe 生成活动文件"
        }
    ]
}

```

因为是调试，所以依赖`exe`文件，因此我们需要修改`program`后面的值
`"preLaunchTask": "C/C++: g++.exe 生成活动文件"`是调试必须要等待编译之后

配置完之后切到`main`所在文件，按`F5`开始调试执行




