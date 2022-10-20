//
// Created by Zza on 2022/10/19.
//
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

const int MAX = 3e3;
unordered_map<ll,bool> mm;
ll sm_map_in[MAX];
ll sm_map_not[MAX];

void disp(ll tar){
    printf("{%d-%d}",(unsigned int)(tar>>32),(unsigned int)tar);
}


int main(){
    int n;
    ll l, s; scanf("%d %lld %lld", &n, &l, &s);
    ll s_up = (s<<32), l_up = (l<<32);
    ll x, y;
    vector<ll> pois(n);
    for(auto &i : pois){
        cin >> x >> y;
        i = (x<<32) + y;
        mm[i] = true;
    }
    int len_in = 0, len_not = 0, cur;
    for (ll i = s; i < 51; --i) {
//        这个地方要注意不能使用到负的，因为我们的
        for (ll j = 0; j <= s; ++j) {
            cin>>cur;
            if(cur){
                sm_map_in[len_in++] = (i << 32) + j;
            } else{
                sm_map_not[len_not++] = (i << 32) + j;
            }
        }
    }
    ll res = 0, temp;
    bool flag = true;
    for(auto iter:pois){
        if((iter>>32) + s > l || (iter<<32) + s_up > l_up) continue;
        for (int j = 0; j < len_in; ++j) {
            if(!mm.count(iter + sm_map_in[j])){
                flag = false; break;
            }
        }
        if(flag){
            for (int i = 0; i < len_not; ++i) {
                if(mm.count(iter + sm_map_not[i])){
                    flag = false; break;
                }
            }
        }
        if(flag) {
//            disp(iter);
            res++;
        }
        flag = true;
    }
    cout<<res;
}
