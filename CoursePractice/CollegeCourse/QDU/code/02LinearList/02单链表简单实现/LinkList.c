/*************************************************************************************
 * Description  : 
 * Author       : star-air
 * Date         : 2022-12-10 22:15:21
 * LastEditTime : 2022-12-10 22:15:21
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/
#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>


// 初始化链表
bool initList(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LinkList)); //创建一个头结点空间
    if((*L)==NULL)
    {
        printf("分配失败");
        return false;
    }
    (*L)->data = 0; // 头结点数据清0
    (*L)->Next = NULL; //头结点指针域指向NULL
    printf("分配成功\n");
    return true;
}

//销毁链表 要修改头结点
// 让老大走
bool destoryList(LinkList *L)
{
    LinkList p = *L;
    while(p!=NULL)
    {
        *L = (*L)->Next; // L往后移
        free(p);
        p = *L;
    }
    return true;
}

// 清空元素
bool clearList(LinkList L)
{
    LinkList p=L->Next;
    LinkList q=NULL;// 小弟
    L->Next=NULL;
    while(p!=NULL)
    {
        q=p->Next;
        free(p);
        p=q;
    }
    return true;
}

// 链表判空
bool listEmpty(LinkList L)
{
    if(L->Next==NULL)
        return true;
    else
        return false;
}

// 链表长度
int listLength(LinkList L)
{
    LinkList p = L->Next;
    int x=0;
    while(p!=NULL)
    {
        x++;
        p=p->Next;
    }
    return x;
}

//根据位置查找元素
bool getElem(LinkList L,int i,DataType *e)
{
    LinkList p=L;
    int x = 0;
    while((p!=NULL)&&(x<i))
    {
        x++;
        p=p->Next;
    }
    if(p==NULL) return false; // 超出范围
    *e=p->data;
    return true;
}

//根据元素查找结点
// 拿一个结点扫过去就行了
LinkList locateElem_L(LinkList L,DataType e)
{
    LinkList p=L->Next;
    while(p)
    {
        if(p->data == e)
            return p;
        p=p->Next;

    }
    return NULL;

}

//根据元素查找位置
int locateElem_I(LinkList L,DataType e)
{
    LinkList p=L->Next;
    int x=1;
    while(p)
    {
        if(p->data == e)
            return x;  
        p=p->Next;
        x++;
    }
    return 0;
}

//指定位置插入
// 算法：让一个指针往后走，走到待插入位置的前一个，然后另一个指针分配一个结点，插入进去
bool listInsert(LinkList L,int i,DataType e)
{
    LinkList p = L;

    int x=0;
    while((p!=NULL)&&(x<i-1))//p指针到尾和到达待插入位置时                                                                                                                                                    
    {
        x++;
        p=p->Next;
    }
    if(p==NULL) return false; // 如果以及到尾部了，说明超出返回，插入失败
    LinkList q = (LinkList)malloc(sizeof(LinkList));//分配结点空间
    if(q==NULL) // 分配失败
    {
        return false;
    }
    q->data = e; // 填入分配结点的数据
    q->Next=p->Next; // 将分配结点插入进去
    p->Next=q; 
    return true;
}

// 指定位置删除
// 让一个指针往后遍历，遍历到待删除结点的前一个，另一个指针指向删除结点，然后free掉
bool listDelete(LinkList L,int i,DataType *e)
{
    LinkList p = L;
    LinkList q = NULL;
    int x=0;
    while((p!=NULL)&&(x<i-1))
    {
        p=p->Next;
        x++;
    }
    if(p==NULL) return false;
    q=p->Next;//让q指向p后面一个，即待删除的结点
    p->Next=q->Next; //删除q
    *e=q->data;
    free(q); //释放被删除的点
    return true;
}


// 头插法
void createList_H(LinkList L,int n)
{
    LinkList p=L;//指向头结点
    LinkList q=NULL;//指向待插元素

    for(int i=0;i<n;i++)
    {
        q=(LinkList)malloc(sizeof(LinkList)); //分配一个结点
        printf("请输入第%d个元素\n",i);
        scanf("%d",&(q->data));
        q->Next=p->Next;
        p->Next=q;
    }

}


// 尾插法
void createList_R(LinkList L,int n)
{
    LinkList p=L;
    LinkList q=NULL;//指向待插元素
    while(p->Next!=NULL) // 遍历到最后一个结点
        p=p->Next;
    for(int i=0;i<n;i++)
    {
        q=(LinkList)malloc(sizeof(LinkList)); //分配一个结点
        printf("请输入第%d个元素\n",i);
        scanf("%d",&(q->data));
        q->Next=p->Next;
        p->Next=q;
        p=q;
    }
}

// 打印链表
void printList(LinkList L)
{
    if(L==NULL)
    {
        printf("链表不存在\n");
        return;
    }
    LinkList p = L->Next;
    if(p==NULL)
    {
        printf("链表中没有元素\n");
        return;
    }
    printf("有%d个元素: ",listLength(L));
    while(p)
    {
        printf("%d ",p->data);
        p=p->Next;
    }
    printf("\n");
}

int main()
{
    LinkList L=NULL;
    int e;
    printList(L);
    initList(&L);
    printList(L);
    listInsert(L,1,2);
    listInsert(L,1,3);
    getElem(L,2,&e);
    printList(L);
    printf("元素值为3的元素下标是%d\n",locateElem_I(L,3));
    printf("元素值为2的元素下标是%d\n",locateElem_I(L,2));
    printf("第2个元素是%d\n",e);
    listDelete(L,2,&e);
    printf("删除元素：%d\n",e);
    // listDelete(L,1,&e);
    // printf("删除元素：%d\n",e);
    printf("头插法\n");
    createList_H(L,3);
    printList(L);
    printf("尾插法\n");
    createList_R(L,3);
    printList(L);
    clearList(L);
    printList(L);
    destoryList(&L);
    printList(L);
    return 0;
}
