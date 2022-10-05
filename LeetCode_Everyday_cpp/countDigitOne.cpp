//
// Created by Zza on 2022/10/1.
//

#include "vector"
#include <math.h>
#include <iostream>
using namespace std;

class Solution {
public:

    static vector<int> tolist(int n);

    int countDigitOne(int n) {
        if(n == 0)return 0;
        vector<int> body = tolist(n);
        int head=0, pos = body.size()-1, res=0;
        for(auto iter=body.rbegin(); iter != body.rend(); iter++, pos--){
            if(*iter == 1){
                res += head*pow(10,pos);
                res += n%(int)pow(10,pos)+1;
            }else if(*iter > 1){
                res += (head+1)*pow(10,pos);
            }else{
                res += head*pow(10,pos);
            }
            head*=10; head += *iter;
        }

        return res;
    }
};

vector<int> Solution::tolist(int n){
    vector<int> res;
    while(n){
        res.push_back(n%10);
        n/=10;
    }
    return res;
}

int main(){
    Solution obj;
    obj.countDigitOne(13);
    return 1;
}