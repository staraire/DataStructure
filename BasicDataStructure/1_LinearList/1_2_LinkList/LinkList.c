/*************************************************************************************
 * Description  : 线性表的链式存储实现c文件
 * Author       : star-air
 * Date         : 2021-05-08 12:40:14
 * LastEditTime : 2022-12-04 13:57:57
 * LastEditors  : star-air
 * Reference    : 链式存储在实现插入，删除的操作时，不需要移动大量数据。所以，链表经常用于存储需要插入和删除的数据，如飞机航班的乘客表
 *************************************************************************************/
#include "LinkList.h"
#include <time.h>

//头指针：L
//头结点：*L
//头结点的数据域可以什么都不放，也可以存放长度：L->data 或者 *L.data
//头结点的指针域指向第一个结点：L->next 或者 *L.next
//最后一个结点的指针域存放NULL
//--头指针L-->[ 空 | L->next ](头节点*L) ----> [data | next](第一个借点) ... ->[ data | NULL](最后一个结点)


/*************************************************************************************
 * description: 初始化线性表
 * return {bool} 初始化成功返回true，初始化失败返回false
 * param {LinkList} *L 头节点指向是个头指针L，把这个头指针L的地址传进来，传地址是为了可以修改，类似引用
 * algorithm: 
 *************************************************************************************/
bool initList(LinkList *L) // struct Node **L
{
    *L = (LinkList)malloc(sizeof(LNode)); //LinkList=LNode *,*L就是头指针,分配一个LNode型数据地址给*L
    if(*L==NULL) //检查是否分配到空指针
    {
        printf("initial failed\n");//可注释
        return false; //分配失败
    }
    (*L)->data=0; //头结点数据域存放链表长度，初始化0
    (*L)->Next=NULL; //头指针的指针域为空表明线性表为空
    printf("init List success\n"); //可注释
    return true;
}

/*************************************************************************************
 * description: 销毁线性表
 * return {bool} 销毁线性表成功成功返回true，失败返回false
 * param {LinkList} *L 头节点指向是个指针L，把这个指针的地址*L传进来
 * algorithm: 
 *************************************************************************************/
bool destroyList(LinkList *L)
{
    LinkList q;
    if(NULL!=*L)
    {
        while(*L) //从头到尾一个一个释放节点空间
        {
            q=(*L)->Next;
            free(*L);
            *L=q;
        }
        printf("destroy List success\n"); //可注释
        return true;
    }
    else
    {
        printf("List 已经被销毁\n"); //可注释
        return false;
    }
}

/*************************************************************************************
 * description: 清空线性表(里的数据)
 * return {void}
 * param {LinkList} L 头节点指向是个指针L，不需要修改指针指向，所以只传指针
 * algorithm: 删掉除了头指针以外的所有内存空间
 *************************************************************************************/
void clearList(LinkList L)
{
    LinkList q,p;
    p=L->Next; //把头节点的指针域即存放着第一个节点的地址给P 
    while(p)
    {
        q=p->Next; //把下一个节点的地址暂存到q里
        free(p); //释放掉当前节点的地址空间
        p=q; //归还给p
    }
    L->data=0; //链表长度清零
    L->Next=NULL; //头节点指针域
}

/*************************************************************************************
 * description: 线性表判空
 * return {bool} 线性表空返回true，不空返回false
 * param {LinkList} L 不需要对链表进行操作，只需要送头节点就行
 * algorithm: 直接判断头节点的数据域
 *************************************************************************************/
bool listEmpty(LinkList L)
{
    if(L->data == 0) //直接判断头节点数据域
    {
        // printf("list is empty\n");//可注释
        return true;
    }
    else
        return false;
}

/*************************************************************************************
 * description: 返回元素个数
 * return {int} 元素个数
 * param {LinkList} L 不需要对链表进行操作，只需要送头节点就行
 * algorithm: 直接返回头节点的数据域
 *************************************************************************************/
#define NOLENGTHDATA 0 //1头结点存了长度数据 0没有存
int listLength(LinkList L)
{
#if NOLENGTHDATA
    return L->data;

#else
    LinkList p=L->Next;
    int i=0;
    while(p)
    {
        p=p->Next;
        i++;
    }
    return i;
#endif
}

/*************************************************************************************
 * description: 获取表内元素
 * return {bool} 成功返回true，失败返回false
 * param {LinkList} L 不需要操作，只要查询
 * param {int} i 第i个
 * param {DataType} *e 返回的数据
 * algorithm: 
 *           1.声明节点p指向链表第一个节点，初始化j从1开始
 *           2.当j<i时，就遍历链表，让p的指针向后移动，不断指向下一个节点，j累加1
 *           3.若到链表结尾p为空，则说明第i个元素不存在
 *           4.若查找成功，返回节点p的数据
 *************************************************************************************/
bool getElem(LinkList L,int i,DataType *e)
{

    LinkList p=L->Next;///声明一个节点指针指向第一个节点
    for(int j=1;j<i;j++)///初始化j从1开始遍历到i-1
    {
        p=p->Next;///p指向下一个节点
        if(p==NULL)///如果p为空，说明超范围
        {
            printf("超范围!");//可注释
            return 0;
        }
    }//此时节点到了对应i的位置
    *e=p->data;///返回数据
    return 1;
}


/*************************************************************************************
 * description: 查找第一个满足compare的序号
 * return {int} 返回序号i，若没有返回0 
 * param {SqList} L 
 * param {DataType} e
 * param {bool} 判定函数
 * algorithm: 
 *************************************************************************************/
int locateElem(LinkList L,DataType e,bool (*compare)(DataType,DataType))
{
    int index = 0;
    LinkList p = L->Next;
    while(p)
    {
        index++;
        if(compare(p->data,e))
        {
            return index;
        }
        p = p->Next;
    }
    return 0;
}


/*************************************************************************************
 * description: 返回前驱元素 初始条件:线性表已存在
 * return {bool}  
 * param {LinkList} L 线性表 
 * param {DataType} cur_e 待查元素 
 * param {DataType} *pre_e 前驱元素 
 * algorithm: 空链表和只含一个的链表不存在前驱元素，第一个结点也不存在前驱元素
 *************************************************************************************/
bool priorElem(LinkList L,DataType cur_e,DataType *pre_e)
{
    LinkList p=L->Next; //指向第一个节点
    LinkList q=NULL;
    if(p==NULL||p->Next ==NULL) //空链表和只有一个元素的链表都不存在前驱元素
        return false;
    q=p->Next; //指向第二个节点(存在)

    while(q)
    {
        if(q->data==cur_e)
        {
            *pre_e=p->data;
            return true; //找到了
        }
        p=q;
        q=q->Next;
    }
    return false; //没找到
}

/*************************************************************************************
 * description: 返回后驱元素
 * return {bool} 存在返回true，不存在返回false
 * param {LinkList} L 线性表 
 * param {DataType} cur_e 待查元素 
 * param {DataType} *next_e 后驱元素
 * algorithm: 空链表和只含一个的链表不存在后驱元素;最后一个元素也不存在后驱元素
 *************************************************************************************/
bool nextElem(LinkList L,DataType cur_e,DataType *next_e)
{
    LinkList p=L->Next;
    LinkList q=NULL;
    if(p==NULL||p->Next ==NULL) //空链表和只有一个元素的链表都不存在前驱元素
        return false;
    q=p->Next; //指向第二个节点(存在)
    while(q)
    {
        if(p->data==cur_e)
        {
            *next_e=q->data;
            return true; //找到了
        }
        p=q;
        q=q->Next;
    } 
    return false; //没找到
}

/*************************************************************************************
 * description: 元素插入
 * return {bool} 插入成功返回true，插入失败返回false 
 * param {LinkList} *L 线性表指针
 * param {int} i 第i个元素
 * param {DataType} e 新元素e
 * algorithm: 
 *************************************************************************************/
bool listInsert(LinkList* L,int i,DataType e) // struct Node **L
{
    LinkList p=*L,s;
    for(int j=1;j<i;j++)///初始化j从1开始到i-1
    {
        p=p->Next;
        if(p==NULL)///如果p为空，说明超过范围
            return false;
    }
    s=(LinkList)malloc(sizeof(LNode));
    s->data=e;
    s->Next=p->Next;
    p->Next=s;
    (*L)->data++;
    return true;
}

/*************************************************************************************
 * description: 线性表指定元素插入
 * return {bool} 删除成功返回true，失败false
 * param {LinkList} *L 线性表指针
 * param {int} i 第i个元素
 * param {DataType} *e 新元素地址指针*e
 * algorithm: 
 *************************************************************************************/
bool listDelete(LinkList* L,int i,DataType *e)
{
    LinkList p=*L,s;
    for(int j=1;j<i;j++)///初始化j从1开始到i-1
    {
        p=p->Next;
        if(p==NULL)///如果p为空，说明超过范围
            return false;
    }
    s=p->Next;
    p->Next=s->Next;
    *e=s->data;
    free(s);
    (*L)->data--;
    return true;
}

/*************************************************************************************
 * description: 遍历线性表调用visit函数      
 * return {bool} 
 * param {LinkList} L 线性表
 * param {void} * visit函数
 *************************************************************************************/
void listTraverse(LinkList L,void (*visit)(DataType *))
{
    LinkList p=L;
    printf("链表的总长度为%d\n",p->data);
    p=p->Next;
    while(p)
    {
        visit(&p->data);
        p=p->Next;
    }
    printf("\n");
}

/*************************************************************************************
 * description: 头插法创建链表
 * return {void}
 * param {LinkList} L 线性表
 * param {int} n 
 *************************************************************************************/
void createListHead(LinkList* L,int n)
{
    LinkList p;///新建一个节点
    srand(time(0));///初始化随机种子
    ///本函数里没有初始头指针的操作，所以在创建之前需要先初始化InitList
    for(int i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));///生成新节点
        p->data=rand()%100+1;///rand()%100+1;生成数
        p->Next=(*L)->Next;
        (*L)->Next=p;///插入到表头
        (*L)->data++;
    }
}

/*************************************************************************************
 * description: 尾插法创建链表
 * return {void}
 * param {LinkList} L 线性表
 * param {int} n 插入数量
 *************************************************************************************/
void createListEnd(LinkList* L,int n)
{
    LinkList p,end=*L;///end为指向尾部的节点
    srand(time(0));///初始化随机种子

    for(int i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(LNode));///生成新结点
        p->data=rand()%100+1;///rand()%100+1;生成数
        p->Next=NULL;
        end->Next=p;///将表终端节点的指针指向新结点
        end=p;///将当前的新节点定义为表尾终端节点
        (*L)->data++;///刷新链表长度
    }
}

/*************************************************************************************
 * description: 翻转链表
 * return {void}
 * param {LinkList} L 线性表
 *************************************************************************************/
void reverse(LinkList* L)
{
    LinkList cur,tmp;
    ///初始化新的头节点
    cur=*L;
    cur=cur->Next;///旧链表的头节点被删除
    (*L)->Next=NULL;
    while(cur)
    {
        tmp=cur;
        cur=cur->Next;///顺序删旧链表的元素
        tmp->Next=(*L)->Next;///被删掉的元素用头插法插入新的头节点
        (*L)->Next=tmp;
    }
}

/*************************************************************************************
 * description: 查找中间节点
 * return {int} 返回查找元素位置
 * param {LinkList} L 
 * param {DataType} *e 返回元素
 *************************************************************************************/
int findMiddle(LinkList L,DataType* e)
{
    LinkList fast,slow;
    int i;
    fast=slow=L;//指向头指针

    for(i=0;fast!=NULL&&fast->Next!=NULL;fast=fast->Next->Next)
    {
        slow=slow->Next;
        i++;
    }
    *e=slow->data;
    return i;
}

/*************************************************************************************
 * description: listTraverse配套函数:打印
 * return {void}
 * param {DataType} c
 *************************************************************************************/
void print(DataType *c)
{
    printf("%d ",*c);
}

/*************************************************************************************
 * description: locateElem配套compare函数:判断两个数是否相等
 * return {bool}
 * param {DataType} d1
 * param {DataType} d2
 *************************************************************************************/
bool equal(DataType d1,DataType d2)
{
    if(d1==d2)
        return true;
    else 
        return false;
}

/*************************************************************************************
 * description: 测试函数
 * return {void}
 *************************************************************************************/
void LinkListTest()
{
    DataType e,e0;
    bool status;
    LinkList L=NULL; // struct Node *L=NULL;
    int j,k;
    //测试初始化函数
    printf("[...测试初始化函数...]\n");
    status=initList(&L);
    printf("\n");

     //测试插入函数
    printf("[...测试插入元素函数...]\n");
    for(int j=1;j<=5;j++)
        status=listInsert(&L,1,j);
    printf("在L的表头依次插入1~5之后：\n");
    listTraverse(L,print);
    printf("\n");
    
    //测试判空函数
    printf("[...测试判空函数...]\n");
    status=listEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",status);
    printf("\n");

    //测试清除数据函数
    printf("[...测试清除数据函数...]\n");
    clearList(L);
    printf("清空数据后：\n");
    listTraverse(L,print);
    status=listEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",status);
    printf("\n");
    
    //测试插入函数
    printf("[...测试获取元素函数...]\n");
    for(int j=1;j<=5;j++)
        status=listInsert(&L,j,j);
    printf("在L的表尾依次插入1~5之后：\n");
    listTraverse(L,print);
        getElem(L,5,&e);
    printf("第5个元素的值为%d\n",e);
    printf("\n");

    //测试locateElem函数调用equal
    printf("[...测试locateElem函数equal...]\n");
    for(j=0;j<=1;j++)
    {
        k=locateElem(L,j,equal);
        if(k) // k不为0，表明有符合条件的元素，且其位序为k
            printf("第%d个元素的值为%d\n",k,j);
        else
            printf("没有值为%d的元素\n",j);
    }
    printf("\n");
    
    //测试前驱函数(头两个数据)
    printf("[...测试前驱函数...]\n");
    printf("头插法创建链表\n");
    clearList(L);
    createListHead(&L,5);
    listTraverse(L,print);
    for(j=1;j<=2;j++) // 测试头两个数据
    {
        getElem(L,j,&e0); // 把第j个数据赋给e0
        status=priorElem(L,e0,&e); // 求e0的前驱
        if(status==false)
            printf("元素%d无前驱\n",e0);
        else
            printf("元素%d的前驱为%d\n",e0,e);
    }
    printf("\n");
    
    //测试后驱函数
    printf("[...测试后驱函数...]\n");
    printf("尾插法创建链表\n");
    clearList(L);
    createListEnd(&L,5);
    listTraverse(L,print);
    for(j=listLength(L)-1;j<=listLength(L);j++) // 最后两个数据
    {
        getElem(L,j,&e0); // 把第j个数据赋给e0
        status=nextElem(L,e0,&e); // 求e0的后继·16· 《数据结构》算法实现及解析(第二版)
        if(status==false)
            printf("元素%d无后继\n",e0);
        else
            printf("元素%d的后继为%d\n",e0,e);
    }
    printf("\n");

    //测试删除元素函数
    printf("[...测试删除元素函数(删除第三个)...]\n");
    listDelete(&L,3,&e);
    printf("删除后\n");
    listTraverse(L,print);
    printf("删除数据为%d\n",e);
    printf("\n");

    //测试翻转元素函数
    printf("[...测试翻转元素函数...]\n");
    reverse(&L);
    printf("翻转后\n");
    listTraverse(L,print);
    printf("\n");
    
}

int main(int argc, char const *argv[])
{
    /* code */
    LinkListTest();//测试函数
    return 0;
}
