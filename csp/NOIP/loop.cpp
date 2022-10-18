//
// Created by Zza on 2022/10/11.
//

#include "string.h"
#include "stdio.h"
#define MAXN 1024
int LEN = 100;
//const int MAXN = 1024;
// 首位打表
int first[] = {1, 1, 4,4,2,1,1,4,4,2};
char buffer[MAXN];
typedef struct BI{
    int d[MAXN];
    int len;
} BI, *pbi;
BI raw, ans, var, temp, factor;
// raw 指的是原始的数据，不能被改动，ans是我们的结果
// var 变化变量，迭代时的临时结果存在这里面
// temp 用于运算时的临时变量
// factor 是我们的因数，我们会发生改变，自乘的因数
// ans 结果，表示我们的循环节

int equal(pbi a, pbi b, int n); // 只有再brute force下使用，我们后面不要使用
int mul(pbi a, pbi res, int n); // res = a*n
int mul_2(pbi a, pbi b, pbi res); // res = a*b
int _pow(pbi a, pbi res, int n); // res = a^n

void disp(pbi tar);

void brute_force();

int get_loop(int n);
void calc_loop();

int main(){
//    FILE *fp;
//    fp = freopen(R"(D:\Coding\CppProjects\Algorithm_trainning\csp\NOIP\in.txt)", "r", stdin);

    calc_loop();
//    brute_force();
//    fclose(fp);
    return 0;
}
void calc_loop(){
    int last_n;
//    读入数据
    scanf("%s %d",buffer, &last_n);
    raw.len = strlen(buffer);
    LEN = last_n;
//    截取数据，并且低位在下。
    for (int i = 0; i < last_n; ++i) raw.d[i] = buffer[raw.len - i - 1] - '0';
    raw.len = last_n;
//    开始循环
    ans.d[0] = first[raw.d[0]]; ans.len = 1; // 第一位
    _pow(&raw, &factor, ans.d[0]);
//    disp(&ans);
    for (int i = 1; i < raw.len; ++i) {
        if(get_loop(i+1) == 0){ printf("-1"); return;}
    }

//    计算结束，输出结果
    disp(&ans);

    return;
}

int get_loop(int n){
    int i;
    var.len = n;
    memcpy(var.d,raw.d,sizeof(int)*(n+1));
    for (i = 0; i < 10; ++i) {
        mul_2(&var, &factor, &var);
        if(raw.d[n-1] == var.d[n-1]){
            _pow(&factor, &var, i+1);
//            mul_2(&factor, &var, &factor);
            memcpy(&factor,&var,sizeof(BI));
            mul(&ans,&ans,i+1);
            return 1;
        }
    }
    return 0;
}

void brute_force(){
    int last_n;
//    读入数据
    scanf("%s %d",buffer, &last_n);
    raw.len = strlen(buffer);
    LEN = last_n + 2;
//    截取数据，并且低位在下。
    for (int i = 0; i < last_n; ++i) raw.d[i] = buffer[raw.len - i - 1] - '0';
    raw.len = last_n;
    memcpy(var.d,raw.d,sizeof(int)*MAXN);
    var.len = raw.len;
    for (int i = 1; i < 1000; ++i) {
        mul_2(&var, &raw, &var);
        if(equal(&var,&raw,raw.len)){
            printf("%d\n",i);
            return;
        }
    }
    printf("-1\n");
}

int equal(pbi a, pbi b, int n){
    for (int i = 0; i < n; ++i) {
        if(a->d[i] != b->d[i]) return 0;
    }
    return 1;
}

int mul(pbi a, pbi res, int n){
//    n <= 10
    int next = 0, l = a->len < LEN ? a->len : LEN;
    for (int i = 0; i < l; ++i) {
        temp.d[i] = a->d[i]*n;
        temp.d[i] += next;
        next = temp.d[i]/10;
        temp.d[i] %= 10;
    }
    temp.len = l;
    while (next){
        if(temp.len >= LEN)break;
        temp.d[temp.len] = next%10;
        next /= 10;
        temp.len++;
    }
    if(res){
        for (int i = 0; i < temp.len; ++i) {
            res->d[i] = temp.d[i];
        }
        res->len = temp.len;
    }
    return 1;
}

int mul_2(pbi a, pbi b, pbi res){
    int next = 0;
    memset(temp.d,0, sizeof(int)*MAXN);
    for (int i = 0; i < a->len; ++i) {
        for (int j = 0; j < b->len; ++j) {
            temp.d[i+j] += a->d[i]*b->d[j];
        }
    }
    temp.len = a->len+b->len-1 < LEN ? a->len+b->len-1 : LEN;
    for (int i = 0; i < temp.len; ++i) {
        temp.d[i] += next;
        next = temp.d[i]/10;
        temp.d[i] %= 10;
    }
    while (next){
        if(temp.len >= LEN)break;
        temp.d[temp.len] = next%10;
        next /= 10;
        temp.len++;
    }
    if(res){
        for (int i = 0; i < temp.len; ++i) {
            res->d[i] = temp.d[i];
        }
        res->len = temp.len;
    }
    return 1;
}

int _pow(pbi a, pbi res, int n){
    res->d[0] = 1;
    res->len = 1;
    for (int i = 0; i < n; ++i) {
        mul_2(res, a, res);
        if(res->len > LEN) res->len = LEN;
    }
    return 1;
}

void disp(pbi tar){
    for (int i = 0; i < tar->len; ++i) {
        printf("%d", tar->d[tar->len - 1 - i]);
    }
    printf("\n");
}

