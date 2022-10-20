//
// Created by Zza on 2022/10/19.
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, temp = 0, buffer; scanf("%lld %lld",&n,&m);
    ll cur = 1, fac;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &fac);
        buffer = m % (cur*fac);
        printf("%d ", (buffer - temp)/cur);
        temp = buffer;
        cur *= fac;
    }
    return 0;
}