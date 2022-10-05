//
// Created by Zza on 2022/10/1.
//

#include "cstdio"
#include "iostream"
#include <cmath>
using namespace std;

int isPrime(int x) {
    int ret = 1;
    int i;
    if (x == 1||
        (x%2==0&&x!=2)) ret = 0;
    for (i = 3;i < sqrt(x);i+=2) {
        if (x % i == 0) {
            ret = 0;
            break;
        }
    }
    return ret;
}

int get_sum(int n){
    if(n<3) return 1;
    if(n%2==0) return 2;
    else if(isPrime(n)) return 1;
    else return 3;
}

int main(){
    int n;
    scanf("%d",&n);

    printf("%d", get_sum(n));
    return 0;
}