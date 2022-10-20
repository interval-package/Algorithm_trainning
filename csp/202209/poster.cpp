//
// Created by Zza on 2022/10/19.
//

//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//// 背包问题
//const int INF = 3e5 + 5;
//const int MAXN = 35;
//int bag[MAXN];
//int dp[INF];
//int f[MAXN][INF];

//
// Created by Zza on 2022/10/19.
//

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e5 + 5;
const int MAXN = 35;
int bag[MAXN];
int f[MAXN][INF];

int main(){
    int n, x, sum = 0; scanf("%d %d",&n, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &bag[i]);
        sum += bag[i];
    }
    memset(f,0,sizeof(f));
    int res = sum - x; // 完全变成01背包问题
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= res; ++j) {
            if(bag[i] <= j){
                f[i][j] = max(f[i-1][j],f[i-1][j-bag[i]] + bag[i]);
            }else{
                f[i][j] = f[i-1][j];
            }
        }
    }
    printf("%d",sum - f[n][res]);

    return 0;
}


//int main_1(){
//    int n, x, sum = 0; scanf("%d %d",&n, &x);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &bag[i]);
//        sum += bag[i];
//    }
//    memset(dp,0,sizeof(dp));
//    int res = sum - x; // 完全变成01背包问题
//    if(res){
//        for (int i = 1; i <= n; ++i) {
//            for (int j = res; j >= bag[i]; --j) {
//                dp[j] = max(dp[j],dp[j-bag[i]] + bag[i]);
//            }
//        }
//        printf("%d",sum - dp[res]);
//    } else{
//        printf("%d",sum);
//    }
//
//    return 0;
//}

//int main(){
//    int n, x, sum = 0; scanf("%d %d",&n, &x);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &bag[i]);
//        sum += bag[i];
//    }
//    memset(f,0,sizeof(f));
//    int res = sum - x; // 完全变成01背包问题
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= res; ++j) {
//            if(bag[i] <= j){
//                f[i][j] = max(f[i-1][j],f[i][j-bag[i]] + bag[i]);
//            }else{
//                f[i][j] = f[i-1][j];
//            }
//        }
//    }
//    printf("%d",sum - f[n][res]);
//
//    return 0;
//}


//int main(){
//    FILE *fp;
//    fp = freopen(R"(D:\Coding\CppProjects\Algorithm_trainning\csp\NOIP\202209\in.txt)", "r", stdin);
//
//    poster_2();
//    fclose(fp);
//    return 0;
//}