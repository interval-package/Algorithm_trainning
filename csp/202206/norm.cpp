//
// Created by Zza on 2022/10/19.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin>>n;
    double mean = 0, fac = 0;
    vector<int> raw(n);
    vector<double> st(n);
    for(int i=0; i<n; i++){
        cin >> raw[i];
        st[i] = raw[i];
        mean += (raw[i]*1.0)/n;
    }
    for(auto &i : st){
        fac += (i-mean)*(i-mean)/n;
    }
    fac = sqrt(fac);
    for(auto i:raw){
        cout<<(i-mean)/fac<<endl;
    }
    return 0;
}