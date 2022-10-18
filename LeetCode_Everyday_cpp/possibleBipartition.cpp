//
// Created by Zza on 2022/10/16.
//
# include <bits/stdc++.h>
char color[2000];
// 二分图的话就是使用
int pos[2000];

int cmp(const void *a, const void *b){
    return ((int*)a)[1] - ((int*)b)[1];
}

// 要么深度，要么bfs
// 还可以使用并查集

bool possibleBipartition(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
//    实际上就是一个二分图的判别，这里题目给的就是邻接表的样式
    qsort(dislikes,dislikesSize,sizeof(int*),cmp);
    memset(color,0,n);
    memset(pos,0,n * sizeof(int));
    for (int i = 0, j = 1; i < dislikesSize; ++i) {
        if(dislikes[i][0] == j){
            pos[j] = i+1;
            j++;
        }
    }
    char cur_col = 1;
    for (int i = 0, j; i < n; ++i) {
        if(color[i])continue;
        color[i] = cur_col;
        j = pos[i];
        if(j){
            for (int k = 0; dislikes[j+k-1][0] == i; ++k) {

            }
        }
    }

    return true;
}



int search_set[2000];

bool possibleBipartition_search(int n, int** dislikes, int dislikesSize, int* dislikesColSize){
    // 使用并查集
    qsort(dislikes,dislikesSize,sizeof(int*),cmp);


    return true;
}