//
// Created by Zza on 2022/9/8.
//

#include "stdlib.h"
#include "stdio.h"
#include "strings.h"

#define loc(i,j) mat[(2*len-(i))*((i)+1)/2+(j)-(i)]

char res[1001];

char * longestPalindrome(char * s){
    int x=0, y=0;
    int len=0;

    for (char* p = s; *p; p++)len++;
    int *mat = calloc(len*(len+1)/2+10, sizeof(int));
    loc(0,0) = 1;
//    预分配全部为0
    for (int i = len-1; i > 0; --i) {
//        两个特殊情况先处理了
        loc(i,i) = 1;
        if(s[i] == s[i+1]){
            loc(i,i+1) = 2;
            if(2>loc(x,y)){x=i; y=i+1;}
        }
        for (int j = i+2; j < len; ++j) {
            if(s[i] == s[j] && loc(i+1,j-1)){
                loc(i,j) = loc(i+1,j-1)+2;
                if(loc(i,j)>loc(x,y)){x=i; y=j;}
            }
        }
    }
    strncpy(res, &s[x], loc(x,y));
//    res[loc(x,y)] = '\0';
    free(mat);
    return res;
}

int main(){
    char *p = longestPalindrome("c");
    printf(p);
    return 0;
}

