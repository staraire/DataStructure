/*************************************************************************************
 * Description  : 
 * Author       : star-air
 * Date         : 2022-12-10 22:15:05
 * LastEditTime : 2022-12-10 22:15:05
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/
#ifndef LINKLIST_H
#define LINKLIST_H


typedef int DataType;//成员数据类型，可修改

typedef struct Node
{
    DataType data;
    struct Node *Next;
}LNode;

typedef struct Node *LinkList; // 链表 带头结点
typedef enum{false,true}bool;  //返回类型(使用gcc编译器时，C语言(c98)没有bool型，所以自己定义)

bool initList(LinkList *L); //初始化链表
bool destoryList(LinkList *L); //销毁链表 要修改头结点
bool clearList(LinkList L); // 清空元素
bool listEmpty(LinkList L); // 链表判空
int listLength(LinkList L); // 链表长度
bool getElem(LinkList L,int i,DataType *e); //根据位置查找元素
LinkList locateElem_L(LinkList L,DataType e); //根据元素查找结点
int locateElem_I(LinkList L,DataType e); //根据元素查找位置
bool listInsert(LinkList L,int i,DataType e);//指定位置插入
bool listDelete(LinkList L,int i,DataType *e);//指定位置删除
void createList_H(LinkList L,int n); // 头插法
void createList_R(LinkList L,int n); // 尾插法
void printList(LinkList L); //打印链表

#endif // LINKLIST_H