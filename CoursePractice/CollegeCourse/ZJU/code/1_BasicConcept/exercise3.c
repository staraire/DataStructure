/*************************************************************************************
 * Description  : 01-复杂度3 二分查找 (20 分)
 * Author       : star-air
 * Date         : 2021-05-06 19:29:40
 * LastEditTime : 2021-05-07 15:59:52
 * LastEditors  : star-air
 * Reference    : 实现函数
 *************************************************************************************/



Position BinarySearch( List L, ElementType X ){
    int left = 1;
    int right = L->Last; //最后一个元素的位置
    while(left<=right){  // 考虑一下这为什么要取等？
        int center = (left+right)/2;  //先找中间值 
        if(L->Data[center] < X)
        {     //比中间值大，X 在右半边 
            left = center+1;
        }
        else if(X < L->Data[center])
        {   //比中间值小，X 在左半边 
            right = center-1;
        }
        else  //找到了，直接返回 
            return center;
  }
  return NotFound;
} 