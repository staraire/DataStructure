/*************************************************************************************
 * Description  : 线性表的顺序存储头文件
 * Author       : star-air
 * Date         : 2021-05-06 19:29:40
 * LastEditTime : 2022-09-04 22:14:23
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/
#ifndef SQLIST_H
#define SQLIST_H
#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 10        //初始内存空间分配量
#define LIST_INCREMENT 2    //内存空间增加量
typedef int DataType;       //成员数据类型，可修改
//typedef enum{false,true} bool;  //返回类型(使用gcc编译器时，C语言(c98)没有bool型，所以自己定义)
/*************************************************************************************
* 顺序存储线性表结构体成员
* 存储空间的初始地址    : data 数据数组
* 线性表的当前长度      : lengh
* 线性表的最大存储容量  : listsize 内存分配变量
 *************************************************************************************/
typedef struct
{
    DataType* data;
    int length;
    int listSize;
}SqList;

/*************************************************************************************
 * 操作函数
 *************************************************************************************/

bool initList(SqList *L);                                               //初始化线性表(内存空间)
bool destroyList(SqList *L);                                            //销毁线性表(内存空间)
void clearList(SqList *L);                                              //清空线性表(里的数据)
bool listEmpty(SqList L);                                               //线性表判空
int listLength(SqList L);                                               //返回元素个数
bool getElem(SqList L,int i,DataType *e);                               //获取元素
int locateElem(SqList L,DataType e,bool (*compare)(DataType,DataType)); //查找第一个满足compare的序号
bool priorElem(SqList L,DataType cur_e,DataType *pre_e);                //返回前驱元素
bool nextElem(SqList L,DataType cur_e,DataType *next_e);                //返回后驱元素
bool listInsert(SqList *L,int i,DataType e);                            //插入元素
bool listDelete(SqList *L,int i,DataType *e);                           //指定元素删除
void listTraverse(SqList L,void (*visit)(DataType *));                  //遍历线性表调用visit函数                                //遍历元素函数


bool equal(DataType d1,DataType d2);                                    //locateElem调用的函数
void print(DataType *c);                                                //listTraverse调用的函数
void sqListTest(void);                                                  //测试函数

#endif // SQLIST_H
