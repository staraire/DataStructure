/*************************************************************************************
 * Description  : 
 * Author       : star-air
 * Date         : 2022-12-10 22:14:44
 * LastEditTime : 2022-12-10 22:14:44
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/
#include "SqList.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化线性表
bool initList(SqList *L)
{
    L->data = (DataType *)malloc(sizeof(DataType)*LIST_SIZE);
    if(NULL==L->data)
    {
        printf("error");
        return false;
    }
    L->length = 0;
    return true;
}

// 销毁线性表
void destoryList(SqList *L)
{
    if(L->data!=NULL)
        free(L->data);
}

// 清空线性表
void clearList(SqList *L)
{
    L->length = 0;
}

// 取值
bool getElem(SqList L,int i,DataType *e)
{
    if(i<1||i>L.length)
        return false;
    *e = L.data[i-1];
    return true;
}

// 查找元素
int locateElem(SqList L,DataType e)
{
    
    for(int i=0;i<L.length;i++)
        if(L.data[i]==e)
            return i;
    return 0;
}

// 插入元素
bool listInsert(SqList *L,int i,DataType e)
{
    // 判断i范围
    if(i<1||i>L->length+1) return false;
    // 判断表存储空间
    if(L->length==LIST_SIZE) return false;
    for(int j=L->length-1;j>i-2;j--)
        L->data[j+1]=L->data[j];
    L->data[i-1]=e;
    L->length++;
    return true;
}

// 删除元素
bool listDelete(SqList *L,int i,DataType *e)
{
    // 判断i范围
    if(i<1||i>L->length) return false;
    *e = L->data[i-1];
    for(int j=i-1;j<L->length;j++)
        L->data[j]=L->data[j+1];
    L->length--;
    return true;
}


// 打印线性表
void printList(SqList L)
{
    if(L.length==0)printf("NO ELEM");
    for(int i=0;i<L.length;i++)
        printf("%d ",L.data[i]);
    printf("\n");
}


int main(void)
{
    SqList L;
    DataType e;
    initList(&L);
    listInsert(&L,L.length+1,1);
    listInsert(&L,L.length+1,2);
    listInsert(&L,L.length+1,3);
    printList(L);
    listDelete(&L,1,&e);
    printf("删除的元素是%d\n",e);
    printList(L);
    return 0;
}