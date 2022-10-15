//
// Created by Zza on 2022/10/14.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string multiply(string num1, string num2) {
    vector<int> arr(num1.length() + num2.length());
    for (int i = 0; i < num1.length(); ++i) {
        for (int j = 0; j < num2.length(); ++j) {
            arr[i+j] += (num1[num1.length()-i-1] - '0') * (num2[num2.length()-j-1] - '0');
        }
    }

    int flow = 0;
    for (int & i : arr) {
        i += flow;
        flow = i / 10;
        i %= 10;
    }

    if (flow){arr.emplace_back(flow);}
    auto i = arr.rbegin();
    while (i != arr.rend() && *i == 0)i++;

    string res;
    for (; i != arr.rend(); ++i) {
        res += to_string(*i);
    }
    if(res.length() == 0) return "0";
    return res;
}

string add(string a, string b){
    vector<int> res(max(a.length(), b.length()),0);
    int flow = 0;
    for (int i = 0; i < res.size(); ++i) {
        res[i] += flow;
        if(i<a.length())res[i] += a[a.length()-i-1]-'0';
        if(i<b.length())res[i] += b[b.length()-i-1]-'0';
        flow = res[i] /10;
        res[i] %= 10;
    }
    if (flow) res.emplace_back(flow);
    string rt;
    auto i = res.rbegin();
    while (i != res.rend() && *i == 0)i++;
    for(; i!=res.rend(); i++){
        rt += to_string(*i);
    }
    return rt;
}

string fact(int n){
    string res("0");
    while (n){
        res = multiply(res, to_string(n));
        res = add(res, to_string(n));
        n--;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
//    scanf("%d",&n);
    cout<< fact(n);
    return 0;
}