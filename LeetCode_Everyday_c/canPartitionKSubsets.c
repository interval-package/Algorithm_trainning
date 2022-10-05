//
// Created by Zza on 2022/9/20.
//

#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

int per, *arr, bound;
bool *dp;

int cmp(const void*,const void*);

bool dfs(int,int,int);

bool canPartitionKSubsets(int* nums, int numsSize, int k){
    arr = nums; bound = numsSize;
    int sum = 0, set=0;
    bool res;
    for(int i=0;i<numsSize;i++)sum += nums[i];
    if(sum % k)return false;
    per = sum/k;
    // 进行排序
    qsort(nums,numsSize,sizeof(nums),cmp);

    if(nums[numsSize-1] > per)return false;

    dp = malloc(sizeof(bool)*(1<<numsSize)); // 设置dp数组
    memset(dp,true,sizeof(bool)*(1<<numsSize)); // 填充
    res = dfs((1<<numsSize)-1,0,per);
    free(dp);
    return res;
}

int cmp(const void* a, const void* b){
    return *(int*)a - *(int*)b; // 递增
}

//static inline int cmp(const void *pa, const void *pb) {
//    return *(int *)pa - *(int *)pb;
//}

//static bool dfs(int s, int p, int per, int* nums, int numsSize, bool* dp) {
//    if (s == 0) {
//        return true;
//    }
//    if (!dp[s]) {
//        return dp[s];
//    }
//    dp[s] = false;
//    for (int i = 0; i < numsSize; i++) {
//        if (nums[i] + p > per) {
//            break;
//        }
//        if ((s >> i) & 1) {
//            if (dfs(s ^ (1 << i), (p + nums[i]) % per, per, nums, numsSize, dp)) {
//                return true;
//            }
//        }
//    }
//    return false;
//}

//bool canPartitionKSubsets(int* nums, int numsSize, int k) {
//    int all = 0;
//    for (int i = 0; i < numsSize; i++) {
//        all += nums[i];
//    }
//    if (all % k > 0) {
//        return false;
//    }
//    int per = all / k;
//    qsort(nums, numsSize, sizeof(int), cmp);
//    if (nums[numsSize - 1] > per) {
//        return false;
//    }
//    bool *dp = (bool *)malloc(sizeof(bool) * (1 << numsSize));
//    memset(dp, true, sizeof(bool) * (1 << numsSize));
//    return dfs((1 << numsSize) - 1, 0, per, nums, numsSize, dp);
//}
