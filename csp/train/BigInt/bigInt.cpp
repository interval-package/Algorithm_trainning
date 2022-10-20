#include<iostream>
#include<cstring>
#include<malloc.h>
#include <vector>
using namespace std;

string mutile1(string s1, string s2)
{
    int sl_len = s1.length();
    int s2_len = s2.length();
    int i = 0; int j = 0;
    //开始申请存储s1,s2的数组
    int *data1 = (int *)malloc(sl_len * sizeof(sl_len));
    int *data2 = (int *)malloc(s2_len * sizeof(s2_len));
    //申请存放结果的数组，两数相乘，位数最多为sl_len + s2_len
    int *result = (int *)malloc((sl_len + s2_len) * sizeof(sl_len + s2_len));
    memset(data1,0, sl_len * sizeof(sl_len)); memset(data2, 0, s2_len * sizeof(s2_len)); memset(result, 0, (sl_len + s2_len) * sizeof(sl_len + s2_len));

    //开始存放s1和s2,注意这里是倒叙存放
    for (i = sl_len - 1, j = 0; i >= 0; i--, j++)
    {
        data1[i] = s1[j] - '0';
    }

    for (i = s2_len - 1, j = 0; i >= 0; i--, j++)
    {
        data2[i] = s2[j] - '0';
    }
    //开始进行相加，结果存放在result中
    for (i = 0; i < sl_len; i++)
        for (j = 0; j < s2_len; j++)
        {
            result[i + j] += data1[i] * data2[j];
        }
    //开始处理进位
    for (i = 0; i < sl_len + s2_len; i++)
    {
        if (result[i] > 9)
        {
            result[i + 1] += result[i] / 10;
        }

        result[i] = result[i] % 10;
    }

    //开始将结果合并 ， 这里要倒叙合并
    int index = 0;
    string re;
    for (i = sl_len + s2_len-1; i >= 0; i--)
    {
        if (result[i] == 0)
            continue;
        else
        {
            index = i;
            break;
        }
    }
    for (i = index; i >= 0; i--)
    {
        re += to_string(result[i]);
    }
    return re;
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


int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    string result = "";
    result = add(s1,s2);
    cout<<result<<endl;
    return 0;
}
