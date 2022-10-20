//
// Created by Zza on 2022/10/19.
//
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
const int INF = 1e6;
struct uinfo{
    int d, u, r;
    bool in = false;
} u_list[MAXN];

struct gap{
  int start = -INF;
  int len = 0;
} region_states[MAXN];

int update_gap(int r, int d);
int judge(int ud, int ur);

int main(){
    int n; scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int r, m; scanf("%d %d", &r, &m);
        int dr;
        for (int j = 0; j < r; ++j) {
            cin >> dr;
            update_gap(dr, i);
        }
        int ud, u ,ur;
        for (int j = 0; j < m; ++j) {
            cin>>ud>>u>>ur;

        }
    }

    for (int i = 0; i < n; ++i) {
        cout<<i<<" ";
    }
    return 0;
}