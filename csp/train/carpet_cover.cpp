//
// Created by Zza on 2022/10/15.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://blog.csdn.net/ACkingdom/article/details/107168158

int arr[1005][1005];
signed main()
{
    int n,m,x1,y1,x2,y2;
    cin>>n>>m;
    for(int j=0;j<m;j++)
    {
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1;i<=x2;i++)
        {
            arr[i][y1]++;
            arr[i][y2+1]--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            arr[i][j]+=arr[i][j-1];
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
 * cao 这里这个差分的思维我是真的没有想到
 * 首先就是这里面的，地毯遇到边界的时候时候会++or--
 * 那么我们只要记录边界的差分变化就好了
 *
 * 也就是只要记录导数就好了
 * */


typedef struct tul{
    int x1,y1,x2,y2;
} tul;

int main_1(){
    int n,m;
    cin>>n>>m;
    vector<tul> arr(m);
    for(auto &i : arr){
        cin>>i.x1>>i.y1>>i.x2>>i.y2;
    }
    int val;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            val=0;
            for(auto &cmp:arr){
                if (i >= cmp.x1 && i <= cmp.x2 && j >= cmp.y1 && j <= cmp.y2){
                    val++;
                }
            }
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}

int main_2(){
    int n,m;
    cin>>n>>m;
    vector<tul> arr(m);
    vector<int> buffer(n);
    for(auto &i : arr){
        cin>>i.x1>>i.y1>>i.x2>>i.y2;
    }
    for (int i = 1; i <= n; ++i) {
        fill(buffer.begin(), buffer.end(), 0);
        for(auto &cmp:arr){
            if (i >= cmp.x1 && i <= cmp.x2){
                for (int j = 1; j <= n; ++j) {
                    if (j >= cmp.y1 && j <= cmp.y2){
                        buffer[j-1]++;
                    }
                }
            }
        }
        for(auto item:buffer)cout<<item<<" ";
        cout<<endl;
    }
    return 0;
}


