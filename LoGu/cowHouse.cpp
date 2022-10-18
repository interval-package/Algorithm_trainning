//
// Created by Zza on 2022/10/16.
//

#include<cstdio>
#include<cstdlib>
const int N=5e3+5,K=1e6+5;
int raw[N],vis[K],n;

// 这题就是暴力搜索了，基本上是在数域常态查找了

// 首先a,b在mod k 意义下同余，当且仅当 k|(raw-var) 即k是(raw-var)的一个因子。
// 这个证明可以考虑mod运算的意义。也可以a%k=var%k 等价于 raw-var=0(mod k)。
// 只要搜索到了这个值就不能用了

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&raw[i]);
    }

//    做差打表
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            int cur=abs(raw[i] - raw[j]);
            vis[cur]=1;
        }
    }

//    搜索当前i的k次是否在差值里面
    for(int i=n;i<K;++i){
        if(!vis[i]){
            int f=1;
            for(int j=i;j<K;j+=i)if(vis[j]){f=0;break;}
            if(f){
                printf("%d\n",i);
                return 0;
            }
        }
    }
    return 0;
}