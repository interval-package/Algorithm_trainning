//
// Created by Zza on 2022/9/10.
//

#include "stdlib.h"

// O(n^2)的时空复杂度真的没有办法支持，会炸内存的
//#define loc(i,j) mat[(2*len-(i))*((i)+1)/2+(j)-(i)]

// 换一个dp的思路走，不要被对角矩阵给麻痹了
// 用一个数组表示，m[i]为以nums[i]结尾的最长上升子序列长度

int maxSubArray(const int * nums, const int numsSize){
    int max, *arr = malloc(sizeof(int)*numsSize);
    max = arr[0] = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        arr[i] = arr[i-1]+nums[i] > nums[i] ? arr[i-1]+ nums[i] : nums[i];
        max = arr[i] > max ? arr[i] : max;
    }
    return max;
}