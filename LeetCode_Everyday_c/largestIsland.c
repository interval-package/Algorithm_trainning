//
// Created by Zza on 2022/9/18.
//
#include "stdlib.h"
// 设计扫描方式，遍历然后更新扫描结果

int **mat, bound, info_list_top, max_size;
int *calc_tab;

int search(int,int);

int cat_max(int,int);

int largestIsland(int** grid, int gridSize, int* gridColSize){
    mat = grid; bound=gridSize; info_list_top=0;
    calc_tab = calloc(max_size=gridSize*gridSize/2,sizeof(int));
    int max = 0, temp;

//    0 号元素用于标记
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (mat[i][j]){
                if(mat[i][j] == 1){
                    info_list_top++; // 更新为当前岛的标号
                    if(info_list_top >= max_size)exit(-1);
                    search(i,j);
                }
                continue;
            }
            temp = cat_max(i,j);
            max = temp>max?temp:max;
        }
    }

    free(calc_tab);
}

int search(int x,int y){
// 这个函数，实现向下的对遇到点的遍历
// 从左边搜素，逆时针搜索，使用递归简单点
// 搜索到的点，就标记上这个岛的信息，同时给这个岛的面积数量+1
// =========================================
    mat[x][y] = -info_list_top;
    calc_tab[info_list_top]++;
//    遍历过的内容用负数来表示，只有1会被判别到
    if (x-1 > 0 && mat[x-1][y] == 1){
        search(x-1,y);
    }
    if (y+1 < bound && mat[x][y + 1] == 1){
        search(x,y+1);
    }
    if (x+1 <bound && mat[x+1][y] == 1){
        search(x+1,y);
    }
    if (y-1 > 0 && mat[x][y-1] == 1){
        search(x,y-1);
    }
    return calc_tab[info_list_top];
}


int cat_max(int x,int y){
//    先对自身四周为1的进行搜索
    if (x-1 > 0 && mat[x-1][y] == 1){
        search(x-1,y);
    }
    if (y+1 < bound && mat[x][y + 1] == 1){
        search(x,y+1);
    }
    if (x+1 <bound && mat[x+1][y] == 1){
        search(x+1,y);
    }
    if (y-1 > 0 && mat[x][y-1] == 1){
        search(x,y-1);
    }

}

