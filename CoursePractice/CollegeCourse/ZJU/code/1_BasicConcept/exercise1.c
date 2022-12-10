/*************************************************************************************
 * Description  : 复杂度1 最大子列和问题 (20 分)
 * Author       : star-air
 * Date         : 2021-05-06 19:29:40
 * LastEditTime : 2021-05-07 16:42:52
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/


#include <stdio.h>


/*************************************************************************************
 * description: 算法1:暴力求解法 复杂度N^3(最直接的思路，通过左边和右边界限两层循环来遍历所有的子列。)
 * param {int} A 数组列
 * param {int} N 元素数量
 * return {int} 返回最大子列和
 *************************************************************************************/
int MaxSubSum1(int A[],int N)
{
    int thisSum,maxSum=0;
    for(int i=0;i<N;i++){ //子列左端位置
        for(int j=i;j<N;j++) //子列右端位置
        {
            thisSum=0;
            for(int k=i;k<=j;k++) //开始计算从左到右边子列的和
            {
                thisSum+=A[k];
            }
            if(thisSum>maxSum) //更新最大子列和
                maxSum=thisSum;
        }
    }
    return maxSum;
}


/*************************************************************************************
 * description: 算法2:暴力改进法 复杂度N^2 (对上面算法两层循环内的遍历进行改进。)
 * param {int} A 数组列
 * param {int} N 元素数量
 * return {int} 返回最大子列和
 *************************************************************************************/
int MaxSubSum2(int A[],int N)
{
    int thisSum,maxSum=0;
    for(int i=0;i<N;i++){ //定位子列左端
        thisSum=0;
        for(int j=i;j<N;j++) //定位子列右端
        {
            thisSum+=A[j];
            if(thisSum>maxSum)
                maxSum=thisSum;
        }
    }
    return maxSum;
}


/*************************************************************************************
 * description: 算法3递归程序
 * param {int} A 
 * param {int} left
 * param {int} right
 *************************************************************************************/
int DivideAndConquer(int A[],int left,int right)
{
    /*若子列只有一个返回子列本身*/
    if(left==right)
    {
        return A[left];
    }
    /*递归处理*/
    int center=(left+right)/2;
    int maxLeftSum = DivideAndConquer(A,left,center);
    int maxRightSum = DivideAndConquer(A,center+1,right);

    /*再分别找左右跨界最大子列和*/
    int maxLeftBoaderSum=0;//左边界最大和
    int leftBoaderSum=0;
    for(int i=center;i>=left;i--)
    {
        leftBoaderSum+=A[i];
        if(leftBoaderSum>maxLeftBoaderSum)
            maxLeftBoaderSum=leftBoaderSum;
    }

    int maxRightBoaderSum=0;//左边界最大和
    int rightBoaderSum=0;
    for(int i=center+1;i<=right;i++)
    {
        rightBoaderSum+=A[i];
        if(rightBoaderSum>maxRightBoaderSum)
            maxRightBoaderSum=rightBoaderSum;
    }
    int sum=maxLeftBoaderSum+maxRightBoaderSum;
    return (maxLeftSum>maxRightSum)?((maxLeftSum>sum)?maxLeftSum:sum):((maxRightSum>sum)?maxRightSum:sum);
}


/*************************************************************************************
 * description: 算法3:分而治之 复杂度NlogN
 * param {int} A 数组列
 * param {int} N 元素数量
 * return {int} 返回最大子列和
 *************************************************************************************/
int MaxSubSum3(int A[],int N)
{
    int ans;
    ans=DivideAndConquer(A,0,N-1);
    if(ans>=0)
        return ans;
    else
        return 0;
}


/*************************************************************************************
 * description: 算法4:贪心法在线处理 复杂度N
 * param {int} A 数组列
 * param {int} N 元素数量
 * return {int} 返回最大子列和
 *************************************************************************************/
int MaxSubSum4(int A[],int N)
{
    int thisSum=0,maxSum=0;
    for(int i=0;i<N;i++)
    {
        thisSum+=A[i]; //向右累加
        if(thisSum>maxSum)
            maxSum=thisSum; //发现更大则更新当前结果
        else if(thisSum<0)//对于结果不利的去掉
            thisSum=0; //不可能使后面的部分和增大，抛弃
    }
    return maxSum;
}

//主函数
int main()
{
    int n=5;
    int a[5]={1,2,3,4,5};
    int ans; 
    // int n; //PTA提交测试
    // scanf("%d",&n);
    // int a[n];
    // for (int i = 0; i < n; i++)
    //     scanf("%d",&a[i]);
    ans=MaxSubSum4(a,n);
    printf("%d",ans);
    return 0;
}
