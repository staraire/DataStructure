/*************************************************************************************
 * Description  : 
 * Author       : star-air
 * Date         : 2022-12-03 19:09:58
 * LastEditTime : 2022-12-03 19:26:45
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/


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
