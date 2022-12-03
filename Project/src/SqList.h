/*************************************************************************************
 * Description  : 
 * Author       : star-air
 * Date         : 2022-12-03 19:10:08
 * LastEditTime : 2022-12-03 19:27:34
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/
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