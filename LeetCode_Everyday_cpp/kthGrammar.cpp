//
// Created by Zza on 2022/10/20.
//

// a_{n} = a_{n-1} cat not a_{n-1}
#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k){
    if(n == 1 || k == 1)return 0;
    int len = 1<<(n-2);
    if(k > len){
        return !kthGrammar(n-1,k-len);
    }
    else if(k<len){
        return kthGrammar(n-1,k);
    } else{
        return n%2;
    }
    return 0;
}

int main(){
    return 0;
}