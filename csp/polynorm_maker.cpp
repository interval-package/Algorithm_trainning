//
// Created by Zza on 2022/10/14.
//

#include <iostream>
#include "stdio.h"
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int len, coef;
    scanf("%d", &len);

    scanf("%d",&coef);
    printf("%d", coef);
    if(len == 0)return 0;
    printf("x^%d",len);

    for (int i = len-1; i > 1; --i) {
        scanf("%d",&coef);
        if(coef > 1 || coef < -1){
            printf("%+dx^%d",coef,i);
        }else if(coef){
            printf("%sx^%d",coef>0?"+":"-",i);
        }
    }

    scanf("%d",&coef);
    if(coef){
        printf("%+dx",coef);
    }

    scanf("%d",&coef);
    if(coef){
        printf("%+d\n",coef);
    }

    return 0;
}