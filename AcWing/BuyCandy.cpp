//
// Created by Zza on 2022/10/1.
//

#include "cstdio"
#include <vector>
using namespace std;

int main(){
    int n, temp, res=0, min=1e9+1;
    long long T, sum=0;
    vector<int> obj;
    scanf("%d %d", &n, &T);
    for(int i=0; i<n; i++){
        scanf("%d",&temp);
        obj.push_back(temp);
        sum += temp;
        if(temp<min)min=temp;
    }
    res += (T/sum)*n;
    T %= sum;
    for(int i=0; T>=min; i=(i+1)%n){
        if(T>=obj[i]){
            res++;
            T-=obj[i];
            continue;
        }
    }
    printf("%d",res);
}