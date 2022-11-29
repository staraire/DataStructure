/*************************************************************************************
 * Description  : 01-复杂度2 Maximum Subsequence Sum (25 分)
 * Author       : star-air
 * Date         : 2021-05-06 19:29:40
 * LastEditTime : 2021-05-07 15:59:33
 * LastEditors  : star-air
 * Reference    : 
 * notice       : 如果输出最大子列和小于0，则输出0，且输出第一个和最后一个
 *************************************************************************************/


#include <stdio.h>

int main(void)
{
    int n=5;
    int a[5]={1,2,3,4,5};

    // int n; //PTA提交测试
    // scanf("%d",&n);
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     scanf("%d",&a[i]);
    int thisSum=0,maxSum=-1; 
    int tempLeft=0,left=0,right=n-1;
    for(int i=0;i<n;i++)
    {
        thisSum+=a[i];
        if(thisSum>maxSum)
        {
            maxSum=thisSum;
            left=tempLeft;
            right=i;//最大子列和出现，前后下标更新
        }
        else if(thisSum<0)
        {
            thisSum=0;
            tempLeft=i+1;//之前的被抛弃
        }
    }
    if(maxSum<0) //如果最大为负数
		printf("0 %d %d",a[0],a[n-1]);
	else
		printf("%d %d %d",maxSum,a[left],a[right]);
    return 0;
}