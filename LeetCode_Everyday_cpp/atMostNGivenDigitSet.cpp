//
// Created by Zza on 2022/10/18.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    int atMostNGivenDigitSet_1(vector<string>& digits, int n) {
        int in[11] = {0}, head[11] = {0}; for(auto i : digits) head[i[0] - '0'] = in[i[0] - '0'] = 1;
        in[10] = 1; for(int i=1; i<10; i++) head[i] += head[i-1];
        len = 0; while (n) { raw[len++] = n % 10; n /= 10; }
        if(in[raw[0]])eq[0] = 1; else in[10] = 0;
        dp[0] = head[0];
        int cur, temp;
        for (int i = 1; i < len; ++i) {
            cur = raw[i];
            if(in[10] && in[cur]) eq[i] = 1; else in[10] = 0;
            temp = (head[cur] - in[cur]);
            dp[i] = temp * (int)pow(digits.size(),i);
            dp[i] += dp[i-1];
        }
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            ans += dp[i];
        }
        return ans;
    }

    static const int MAXN = 32;
    int len;
    int raw[MAXN], dp[MAXN], eq[MAXN];

    char s[MAXN];
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        sprintf(s,"%d",n);
        int len = strlen(s), m = digits.size();
        memset(dp, 0, sizeof(dp));
        memset(eq, 0, sizeof(eq));
        eq[0] = 1; dp[0] = -1;
        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < m; ++j) {
                if(s[i] == digits[j][0]){
                    eq[i] = eq[i-1];
                } else if(s[i] < digits[j][0]){
                    dp[i] += eq[i-1];
                } else{
                    break;
                }
            }
            if (i > 1) {
                dp[i] += m + dp[i-1] * m;
//                这里的m是为了，当高位全部为0的时候使用的
            }
//            高位可能性保持，低位还有m种可能
        }

        return dp[len-1] + eq[len-1];
    }
};