/*************************************************************************************
 * Description  : 线性表的顺序存储实现c文件
 * Author       : star-air
 * Date         : 2021-05-06 19:29:40
 * LastEditTime : 2021-06-08 22:01:57
 * LastEditors  : star-air
 * Reference    : 顺序表存储结构容易实现随机存取线性表的第I个数据元素的操作，但在实现插入，删除的操作时要移动大量数据元素，所以，它适用于数据相对稳定的线性表，如职工表，学生学籍表
 * notice       : 如果使用gcc编译器，c语言里没有bool变量(需要自己定义),没有引用传递,没有new
 *************************************************************************************/
#include "sqList.h" //包括进头文件有利于编译器检查 

/*************************************************************************************
 * description: 初始化线性表 
 * return {bool} 初始化成功返回true，不成功返回false
 * param {SqList} *L 线性表L的指针
 * algorithm: 先申请内存空间,判断L里是否为空，如果为空，初始化成功
 *************************************************************************************/
bool initList(SqList *L)
{
    L->data=(DataType *)malloc(sizeof(DataType)*LIST_SIZE); //malloc提前分配动态内存空间给线性表使用
    if(L->data==NULL) //查看是否分配，防止分配到指针为NULL的空间
    {
        printf("init List failed\n"); //可注释
        return false; //分配失败
    }
    L->length=0; //成员参数初始化
    L->listSize=LIST_SIZE; //结构体成员变量初始化
    printf("init List success\n"); //可注释
    return true; //分配成功
}

/*************************************************************************************
 * description: 销毁线性表 初始条件:线性表已存在
* return {bool} 销毁成功返回true，不成功返回false
 * param {SqList} *L 线性表L的指针
 * algorithm: 先判断数据是否为空
 *************************************************************************************/
bool destroyList(SqList *L)
{
    if(NULL!=L->data) //判断是否已经被销毁
    {
        free(L->data); //释放内存空间
        L->data=NULL; //指针指向NULL
        L->length=0;
        L->listSize=0;
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
 * description: 清空线性表
 * return {void} 
 * param {SqList} *L 线性表L的指针
 * algorithm: 直接将数据长度清0即可
 *************************************************************************************/
void clearList(SqList *L)
{
    L->length=0;
}


/*************************************************************************************
 * description: 判断线性表空
 * return {bool} 若表为空返回true,非空返回false
 * param {SqList} L 线性表
 * algorithm: 直接判断结构体里length即可
 *************************************************************************************/
bool listEmpty(SqList L)
{
    if(L.length == 0)//直接判断结构体成员
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
 * param {SqList} L 
 * algorithm: 直接返回结构体里length即可
 *************************************************************************************/
int listLength(SqList L)
{
    return L.length;
}

/*************************************************************************************
 * description: 获得线性表L中的第i个元素
 * return {bool} 获取成功返回true，不成功返回false
 * param {SqList} L 
 * param {int} i
 * param {DataType} *e
 * algorithm: 
 *************************************************************************************/
bool getElem(SqList L,int i,DataType *e)
{
    if(i<1||i>L.length) //传入参数范围检测
    {
        printf("position error\n"); //可注释
        return false;
    }
    *e = L.data[i-1];///返回参数
    return true;
}


/*************************************************************************************
 * description: 返回L中第一个于e相等的序列号
 * return {int} 返回序号i，若没有返回0 
 * param {SqList} L 
 * param {DataType} e
 * param {bool} 判定函数
 * algorithm: 
 *************************************************************************************/
int locateElem(SqList L,DataType e,bool (*compare)(DataType,DataType))
{
    int i;
    for(i=0;i<L.length;i++)///遍历线性表
    {
        if(compare(L.data[i],e))
            return i+1; //得到条件值，返回
    }
    return 0;
}


/*************************************************************************************
 * description: 返回前驱元素 初始条件:线性表已存在
 * return {bool}  
 * param {SqList} L 线性表 
 * param {DataType} cur_e 待查元素 
 * param {DataType} *pre_e 前驱元素 
 * algorithm: 
 *************************************************************************************/
bool priorElem(SqList L,DataType cur_e,DataType *pre_e)
{
    int i=0;
    if(cur_e==L.data[0]) //判断是不是第一个元素
        return false;
    i=locateElem(L,cur_e,equal); //查找是第几个
    if(i==0) //没找到 
        return false;
    else
    {
        // *pre_e=L.data[i-2]; //i-1元素前一个i-2
        getElem(L,i-1,pre_e);
        return true;
    }
}

/*************************************************************************************
 * description: 返回后驱元素
 * return {bool}
 * param {SqList} L 线性表 
 * param {DataType} cur_e 待查元素 
 * param {DataType} *next_e 后驱元素
 * algorithm: 
 *************************************************************************************/
bool nextElem(SqList L,DataType cur_e,DataType *next_e)
{
    int i=0;
    if(cur_e==L.data[listLength(L)-1])///判断是不是最后一个元素
        return 0;
    i=locateElem(L,cur_e,equal);///查找是第几个
    if(i==0) //没找到
        return 0;
    else
    {
        // *next_e=L.data[i];///i-1元素后一个i
        getElem(L,i+1,next_e);
        return 1;
    }
}

/*************************************************************************************
 * description: 线性表元素插入,第i个元素前插入
 * return {bool} 插入成功返回true，失败false
 * param {SqList} *L 线性表指针
 * param {int} i 第i个元素
 * param {DataType} e 新元素e
 * algorithm: 
 *           1.插入位置不合理，抛出异常
 *           2.如果线性表长度大于等于数组长度，则抛出异常或者动态增加容量
 *           3.从最后一个元素开始向前遍历到第i个位置，分别将它们向后移动一个位置
 *           4.将要插入元素填入位置i处
 *           5.表长+1
 *************************************************************************************/
bool listInsert(SqList *L,int i,DataType e)
{
    if(i<1 || i>L->length+1) //i的范围判断
    {
        printf("position error\n"); //可注释
        return false;
    }

    if(L->length>=L->listSize) //判断长度溢出
    {
        L->data=(DataType*)realloc(L->data,(L->listSize+LIST_SIZE)*sizeof(DataType));///重新分配内存空间
        L->listSize+=LIST_INCREMENT; //线性表数组内存+10
    }
    if(!L->data) //判断是否分配到指针为NULL的空间
    {
        printf("realloc error");
        return false;
    }

    DataType *q=NULL; //申请一个指针*q
    q=&L->data[i-1]; //地址指向第i个元素
    DataType *p=NULL; //申请一个指针*p
    //将要插入位置后面的数据元素整体向后移动一位
    for(p=&L->data[L->length-1];p>=q;p--)
    {
        *(p+1)=*p; //把前面的值赋给后一个位置
    }

    *q=e; //第i个元素前插入数e
    L->length++; //长度加1
    
    return true;
}

/*************************************************************************************
 * description: 线性表指定元素插入
 * return {bool} 删除成功返回true，失败false
 * param {SqList} *L 线性表指针
 * param {int} i 第i个元素
 * param {DataType} *e 新元素地址指针*e
 * algorithm: 
 *           1.如果删除位置不合理，抛出异常
 *           2.取出删除元素
 *           3.从删除元素位置开始遍历到最后一个元素位置，分别将它们都向前移动一个位置
 *           4.表长-1   
 *************************************************************************************/
bool listDelete(SqList *L,int i,DataType *e)
{
    if(i<1 || i>L->length) //i范围判断
    {
        printf("position error\n"); //可注释
        return false;
    }
    DataType *q=NULL;
    DataType *p=NULL; //申请两个指针
    q=&L->data[i-1]; //q指针指向待删除元素
    p=&L->data[L->length - 1]; //p指针指向最后一个元素
    *e=*q; //将删除元素返回
    //删除元素后面的整体前移一位
    for(;q<=p;q++)
    {
        *(q)=*(q+1);
    }
    L->length--; //表长-1
    return true;
}

/*************************************************************************************
 * description: 遍历线性表调用visit函数      
 * return {bool} 
 * param {SqList} L 线性表
 * param {void} * visit函数
 *************************************************************************************/
void listTraverse(SqList L,void (*visit)(DataType *))
{
    for (int i = 0; i < L.length; i++)
    {
        visit(&L.data[i]);
    }   
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
 * description: listTraverse配套函数:打印
 * return {void}
 * param {DataType} c
 *************************************************************************************/
void print(DataType *c)
{
    printf("%d ",*c);
}

/*************************************************************************************
 * description: 测试函数
 * return {void}
 *************************************************************************************/
void sqListTest(void)
{
    SqList L;
    DataType e,e0;
    int status;
    int j,k;
    //测试初始化函数
    printf("[...测试初始化函数...]\n");
    printf("初始化前：L.data=%u L.length=%d L.listSize=%d\n",L.data,L.length,L.listSize);
    initList(&L);
    printf("初始化后：L.data=%u L.length=%d L.listSize=%d\n",L.data,L.length,L.listSize);
    printf("\n");
    
    //测试插入函数
    printf("[...测试插入元素函数...]\n");
    for(j=1;j<=5;j++)
        status=listInsert(&L,1,j);
    printf("在L的表头依次插入1-5后，L.data=");
    for(j=1;j<=5;j++)
        printf("%d ",L.data[j-1]);
    printf("\n");
    printf("插入表头数据后：L.data=%u L.length=%d L.listSize=%d\n",L.data,L.length,L.listSize);
    printf("\n");
    
    //测试返回元素个数
    printf("[...测试返回元素个数函数...]\n");
    printf("listLength函数返回表长为%d\n",listLength(L));
    printf("\n");
    
    //测试判空函数
    printf("[...测试判空函数...]\n");
    status=listEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",status);
    printf("\n");

    //测试清除数据函数
    printf("[...测试清除数据函数...]\n");
    clearList(&L);
    printf("清空数据后：L.data=%u L.length=%d L.listSize=%d\n",L.data,L.length,L.listSize);
    status=listEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",status);
    printf("\n");
    
    //测试插入函数超出范围后是否自动申请空间
    printf("[...测试插入函数超出范围后是否自动申请空间...]\n");
    for(j=1;j<=10;j++)
        listInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：*L.data=");
    for(j=1;j<=10;j++)
        printf("%d ",L.data[j-1]);
    printf("\n");
    printf("插入表尾数据后：L.data=%u L.length=%d L.listSize=%d\n",L.data,L.length,L.listSize);
    listInsert(&L,1,0);
    printf("在L的表头插入0后：*L.data=");
    for(j=1;j<=listLength(L);j++)
        printf("%d ",L.data[j-1]);
    printf("\n");
    printf("L.data=%u(有可能改变) L.length=%d(改变) L.listsize=%d(改变)\n",L.data,L.length,L.listSize);
    printf("\n");
    
    //测试删除元素函数
    printf("[...测试删除元素函数(删除第三个)...]\n");
    listDelete(&L,3,&e);
    printf("删除后，L.data=");
    for(int j=1;j<=L.length;j++)
        printf("%d ",L.data[j-1]);
    printf("\n");
    printf("删除数据为%d\n",e);
    printf("删除数据后：L.data=%u L.length=%d L.listSize=%d\n",L.data,L.length,L.listSize);
    printf("\n");
    
    //测试获取元素函数
    printf("[...测试获取元素函数...]\n");
    getElem(L,5,&e);
    printf("第5个元素的值为%d\n",e);
    printf("\n");

    //测试前驱函数(头两个数据)
    printf("[...测试前驱函数...]\n");
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
    
    //测试listTraverse函数调用print
    printf("[...测试listTraverse函数调用print...]\n");
    listTraverse(L,print); // 依次对元素调用print1()，输出元素的值
    printf("\n");
    printf("\n");

    //测试locateElem函数调用equal
    printf("[...测试locateElem函数equal...]\n");
    for(j=10;j<=11;j++)
    {
        k=locateElem(L,j,equal);
        if(k) // k不为0，表明有符合条件的元素，且其位序为k
            printf("第%d个元素的值为%d\n",k,j);
        else
            printf("没有值为%d的元素\n",j);
    }
    printf("\n");
    
    //测试销毁函数
    printf("[...测试销毁函数...]\n");
    destroyList(&L);
    printf("销毁数据后：L.data=%u L.length=%d L.listSize=%d\n",L.data,L.length,L.listSize);
    printf("\n");
}



/*************************************************************************************
 * description: 主函数
 *************************************************************************************/
int main(int argc, char const *argv[])
{
    /* code */
    sqListTest(); //测试函数
    return 0;
}
