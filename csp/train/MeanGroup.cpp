//
// Created by Zza on 2022/10/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int w, n;
    cin>>w>>n;
    vector<int> data(n);
    for(auto &i: data)cin>>i;

    int res = 0;
    sort(data.begin(), data.end());
    for (auto forward= data.begin(), back = data.end()-1; forward <= back ;) {
        if(*forward + *back <= w){
            res++;
            forward++;
            back--;
        } else{
            res++;
            back--;
        }
    }

    cout<<res;
    return 0;
}

/*
 * dp 对于第一个一定有dp[0] = 1
 *
 * when s[i+1] + min(s) > w : dp[i+1] = dp[i]+1
 * when s[i+1] +
 *
 * */