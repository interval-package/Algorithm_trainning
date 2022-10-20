//
// Created by Zza on 2022/10/14.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int len;
    cin>>len;
    vector<int> tar(len);
    for(auto i=tar.begin(); i!=tar.end();i++)cin>>*i;

    sort(tar.begin(),tar.end());
    tar.erase(unique(tar.begin(),tar.end()),tar.end());

    cout<<tar.size()<<endl;
    for(auto i:tar)cout<<i<<' ';
}