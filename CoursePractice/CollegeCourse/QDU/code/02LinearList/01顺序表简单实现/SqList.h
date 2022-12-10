/*************************************************************************************
 * Description  : 
 * Author       : star-air
 * Date         : 2022-12-10 22:14:26
 * LastEditTime : 2022-12-10 22:14:26
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/
#ifndef SQLIST_H
#define SQLIST_H



#define LIST_SIZE 10        //初始内存空间分配量
typedef int DataType;       //成员数据类型，可修改
typedef enum{false,true} bool;  //返回类型(使用gcc编译器时，C语言(c98)没有bool型，所以自己定义)
typedef struct
{
    DataType* data;
    int length;
}SqList;

bool initList(SqList *L);                                               //初始化线性表(内存空间)
void destoryList(SqList *L); // 销毁线性表
void clearList(SqList *L); // 清空线性表
bool getElem(SqList L,int i,DataType *e); //取值
int locateElem(SqList L,DataType e); // 查找元素
bool listInsert(SqList *L,int i,DataType e); // 插入元素
bool listDelete(SqList *L,int i,DataType *e); // 删除元素


void printList(SqList L);//打印线性表

# endif