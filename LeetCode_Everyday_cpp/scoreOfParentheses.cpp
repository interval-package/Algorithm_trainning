//
// Created by Zza on 2022/10/9.
//
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int temp;
        int rec;
        for(auto iter: s){
            if(iter == ')'){
                temp = 0;
                while (true){
                    rec = stk.top();
                    if (rec == '('){
                        stk.pop();
                        stk.push(temp?2*temp:-1);
                        break;
                    } else{
                        temp += rec;
                        stk.pop();
                    }
                }
            } else{
                stk.push(iter);
            }
        }
        rec=0;
        while (!stk.empty()){
            rec += stk.top();
            stk.pop();
        }
        return -rec;
    }
};

int main(){
    Solution obj;
    int res = obj.scoreOfParentheses("((((((())))()())))");
    cout<<res<<endl;
    return 0;
}