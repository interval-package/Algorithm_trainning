//
// Created by Zza on 2022/10/14.
//
#include <cstdio>
#include <iostream>
using namespace std;

#define MAX 10000

typedef struct BigInt{
//    BigInt():len(0),flag(true){}

    void input(){
        char temp;
        len = 0;
        temp = cin.get();
        if (temp == '-') flag = temp;
        else {
            flag = '+';
            body[len++] = temp;
        }
        do {
            temp = cin.get();
            body[len++] = temp;
        }while (temp && temp != '\n' && temp != EOF);
        body[--len] = '0';
    }
    char body[MAX];
    char flag;
    int len;
} BigInt;

void disp(BigInt &a){
    if (a.flag == '-')printf("%c",a.flag);
    for (int i = 0; i < a.len; ++i) {
        printf("%c",a.body[i]);
    }
}
void mul(BigInt& a, BigInt&b, BigInt& res);

int main(){
    BigInt a, b, res;
    a.input(); b.input();
    mul(a,b,res);
    disp(res);
    return 0;
}

void mul(BigInt& a, BigInt&b, BigInt& res){
    int temp[MAX]={0}, len = a.len+b.len-1, flow=0;
    for (int i = 0; i < a.len ; ++i) {
        for (int j = 0; j < b.len; ++j) {
            temp[i+j] += (a.body[a.len-i-1]-'0') * (b.body[b.len-j-1]-'0');
        }
    }

    for (int i = 0; i < len; ++i) {
        temp[i] += flow;
        flow = temp[i] / 10;
        temp[i] %= 10;
    }

    if (flow){
        temp[len] = flow;
        ++len;
    }

    for (int i = 0; i < len; ++i) {
        res.body[i] = temp[len-i-1] + '0';
    }
    res.len = len;
    res.flag = a.flag==b.flag?'+':'-';
    res.body[res.len] = '\0';
}