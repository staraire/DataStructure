/*************************************************************************************
 * Description  : 线性表的链式存储头文件
 * Author       : star-air
 * Date         : 2021-05-08 12:40:14
 * LastEditTime : 2022-12-04 14:15:25
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/
#ifndef LINKLIST_H
#define LINKLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;//成员数据类型，可修改
//typedef enum {false, true} bool;//返回类型(C98没有bool型，所以自己定义)
/*******************************************************************
*链式单链表结构体成员
*当前节点数据:data
*下一节点指针*Next
********************************************************************/
typedef struct Node
{
    DataType data;
    struct Node *Next;
}LNode;
//这里定义指针类型是因为上面的结构体只是定义的一个结点
//用指针访问节点地址
typedef struct Node *LinkList;

/*************************************************************************************
 * 操作函数
 *************************************************************************************/

bool initList(LinkList* L);                                             //初始化线性表(内存空间)
bool destroyList(LinkList* L);                                          //销毁线性表(内存空间)
void clearList(LinkList L);                                            //清空线性表(里的数据)
bool listEmpty(LinkList L);                                             //线性表判空
int listLength(LinkList L);                                             //返回元素个数
bool getElem(LinkList L,int i,DataType* e);                             //获取元素
int locateElem(LinkList L,DataType e,bool(*compare)(DataType,DataType)); //查找第一个满足compare的序号
bool priorElem(LinkList L,DataType cur_e,DataType* pre_e);                //返回前驱元素
bool nextElem(LinkList L,DataType cur_e,DataType* next_e);                //返回后驱元素
bool listInsert(LinkList* L,int i,DataType e);                            //元素插入
bool listDelete(LinkList* L,int i,DataType* e);                           //指定元素删除
void listTraverse(LinkList L,void (*visit)(DataType*));                  //遍历线性表调用visit函数  

void createListHead(LinkList* L,int n);                                   //头插法创建链表
void createListEnd(LinkList* L,int n);                                    //尾插法创建链表
void reverse(LinkList* L);                                                //翻转链表
int findMiddle(LinkList L,DataType* e);                                   //查找中间节点

void print(DataType* c);                                                  //listTraverse调用的函数
bool equal(DataType d1,DataType d2);                                      //locateElem调用的函数
void LinkListTest();                                                      //测试函数

#endif // LINKLIST_H