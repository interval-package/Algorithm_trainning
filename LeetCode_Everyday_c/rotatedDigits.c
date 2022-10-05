//
// Created by Zza on 2022/9/25.
//

// 2 5 6 9 must 1
// 3 4 7 none

#include "math.h"
#include "stdio.h"

int tar[6];
const int proj_1[] = {1,2,3,3,3,4,5,5,6,7};

const int proj_2[] = {1,2,2,2,2,2,2,2,3,3};

int full(int pos, int ok);

int rotatedDigits(int n){
    int temp = n, len=0, res=0, i;
    while(temp){
        tar[len] = temp%10;
        len++;
        temp/=10;
    }

    temp = 0;

    for(i = len-1; i >= 0; i--){
        res += full(i, temp);
        if(tar[i] == 3 || tar[i] == 4 ||tar[i] == 7){
            temp = -1;
            break;
        }
        if(tar[i] == 2 || tar[i] == 5 || tar[i] == 6 || tar[i] == 9)temp=1;
    }
    if(temp > -1){
        if(tar[0] == 2 || tar[0] == 5 || tar[0] == 6 || tar[0] == 9)res++;
        if(temp && (tar[0]==0 || tar[0] == 1 || tar[0] == 8))res++;
    }
    return res;
}

int full(int pos, int ok){
    int head = tar[pos] -1;

    if(ok){
        return head>=0?proj_1[head]*pow(7,pos):0;
    }

    if (head >= 0){
        head = proj_1[head]*pow(7,pos) - proj_2[head]*pow(3, pos);
        return head;
    } else{
        return 0;
    }
}

// 每一位数字为k，则能支持k-2 * 8 ^ n - (k-?*4^n)



int main(){
    printf("%d", rotatedDigits(300));
}
