//
// Created by Zza on 2022/10/15.
//

#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 99999999

typedef struct point{
    int x,y;
} poi;

int var[10000];

vector<poi> arr;

int cmpY(int a, int b){
    return arr[a].y - arr[b].y;
}

int cmp(poi& a, poi& b){
    if (a.x == b.x)return a.y-b.y;
    return a.x - b.x;
}

inline int dist(poi a, poi b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

inline int dist(int a, int b){
    return (arr[a].x-arr[b].x)*(arr[a].x-arr[b].x) + (arr[a].y-arr[b].y)*(arr[a].y-arr[b].y);
}


// 高贵的分治法

//最近点对算法，输出left点到right点之间最近两点对的距离
int divide(int left,int right){
    int d = INF;
    if(left>=right)
        return d;
    if(left + 1 == right)
        return dist(left, right);

    int mid = (left+right)/2;

    int d1 = divide(left,mid), d2 = divide(mid+1,right);
    d = min(d1, d2);

    double _d = sqrt(d);

    int k=0;
    for(int i=left;i<=right;i++)
        if(fabs(arr[i].x-arr[mid].x)<=_d)
            var[k++]=i;
    sort(var, var + k, cmpY);
    for(int i=0;i<k;i++)
        for(int j=i+1;j<k&& arr[var[j]].y - arr[var[i]].y < _d; j++)
            d=min(d,dist(var[i], var[j]));

    return d;
}

int main(){
    int n; cin>>n;
    arr.resize(n);
    for(auto &i:arr) cin>>i.x>>i.y;
    sort(arr.begin(), arr.end(), cmp);

    printf("%.4lf\n",sqrt(divide(0,n-1)));
    return 0;
}