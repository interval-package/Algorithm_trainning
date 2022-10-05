#include "stdlib.h"
#include "stdio.h"
#include "strings.h"

// 给出不同面额的硬币以及一个总金额.
// 写一个方法来计算给出的总金额可以换取的最少的硬币数量
// 如果已有硬币的任意组合均无法与总金额面额相等
// 那么返回-1

/**
 * @param coins: a list of integer
 * @param amount: a total amount of money amount
 * @return: the fewest number of coins that you need to make up
 */

int coinsSize=3;

int coin_change(const int* coins, int amount) {
    // write your code here
    
    // make dp arr
    int *dp_arr = malloc(sizeof(int)*(amount+1));
    int cur,  res;
    // pre fill
    for(int i = 1; i<=amount; i++) dp_arr[i] = amount+1;
    dp_arr[0] = 0;

    for (int i = 0; i < amount; i++)
    {
        if(dp_arr[i]>amount)continue;
        for (int j = 0; j < coinsSize; j++)
        {   
            cur = i+coins[j];
            if(cur > amount) break;
            dp_arr[cur] = dp_arr[cur]<(dp_arr[i] + 1)?dp_arr[cur]:(dp_arr[i]+1);
        }
    }
    res = dp_arr[amount]>amount?-1:dp_arr[amount];
    free(dp_arr);
    return res;
}

/*
    首先，这是一道很典型的动态规划题目
    我们先从暴力求解的角度来思考，也就是把所有的可能给打印出来

    ########################################################
    从最大的类别开始搞，如果大于amount，则换小的，否则计数++
    进入子问题
    如果子问题，这个不能解决的话，就返回-1
    判断子问题是否成立，如果不成立，则
    如果大于，则回退，如果小于则继续

    不对这就又感觉是贪心了

    ########################################################3

    将amount做一个长度的short表
    先将所有已知长度，也就是我们硬币类型的赋值为1
    
    然后就是从前往后遍历，如果

*/

int main(){
    int coins[] = {1, 2, 5}, res;
    coinsSize = 3;
    res = coin_change(coins, 11);
    printf("%d", res);
    return 0;
}