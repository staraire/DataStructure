/*************************************************************************************
 * Description  : 例题2.写程序计算给定多项式在给定点x处的值.f(x)=a0+a1x+a2x^2.....anx^n
 * Author       : star-air
 * Date         : 2021-05-06 19:29:40
 * LastEditTime : 2021-05-07 16:42:36
 * LastEditors  : star-air
 * Reference    : 
 *************************************************************************************/

#include <stdio.h>
#include <time.h>
#include <math.h>
#define POWER 101 //加权系数数量
#define count 1e6 //重复调用次数


/*************************************************************************************
 * description: 直接算
 * param {int} n
 * param {double} a
 * param {double} x
 *************************************************************************************/
double f1(int n,double a[],double x)
{
    int i;
    double p=a[0]; //第一个不需要乘
    for(i=1;i<n;i++)
        p+=(a[i]*pow(x,i));
    return p;
}


/*************************************************************************************
 * description: 秦九韶算法
 * param {int} n
 * param {double} a
 * param {double} x
 *************************************************************************************/
double f2(int n,double a[],double x)
{
    int i;
    double p=a[n-1];
    for(i=n-1;i>0;i--)
        p=a[i-1]+x*p;
    return p;
}

/*************************************************************************************
 * description: 测时间程序
 * param {int} n
 * param {double} a
 * param {double} x
 *************************************************************************************/
void GetTime(double (*f)(int,double*,double),int n,double a[],double x)
{

    double start,stop,duration,y;
    start=clock();
    for(int i=0;i<count;i++) //重复调用，以得到时间数据
        y=(*f)(n,a,x);
    stop=clock();
    duration=((double)(stop-start))/CLK_TCK/count;
    printf("y=%f\n",(double)y);
    printf("ticks=%f\n",(double)(stop-start));
    printf("duration=%6.2e\n",duration);
}

int main()
{
    double a[POWER];
    double (*f)(int,double*,double);
    a[0]=1; //第一个数不需要加权
    for(int i=1;i<POWER;i++) a[i]=(double)1/i; //预置加权系数

    printf("直接算\n");
    f=f1;
    GetTime(f,POWER,a,1.1); 
    printf("秦九韶算法\n");
    f=f2;
    GetTime(f,POWER,a,1.1);
    return 0;
}

