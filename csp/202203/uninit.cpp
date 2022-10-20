//
// Created by Zza on 2022/10/20.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 5;
int vars[MAX];

int main(){
    int n, k; scanf("%d %d", &n, &k);
    memset(vars, 0, sizeof(int)*(n+1));
    vars[0] = 1;
    int l_var, r_var, res = 0;
    for (int i = 0; i < k; ++i) {
        cin>>l_var>>r_var;
        if(!vars[r_var]) res++;
        vars[l_var] = 1;

    }
    printf("%d",res);
}