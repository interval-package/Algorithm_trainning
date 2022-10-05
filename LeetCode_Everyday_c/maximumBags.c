//
// Created by Zza on 2022/9/11.
//

#include "stdlib.h"

int cmp(const void* i, const void * j){
    return *(int*)i - *(int*)j;
}

int maximumBags(int* capacity, int capacitySize, const int* rocks, int rocksSize, int additionalRocks){
    int total=0, j;
    for (int i = 0; i < capacitySize; ++i) {
        capacity[i] -= rocks[i];
        total += capacity[i];
    }
    if(total<=additionalRocks)return capacitySize;
    qsort(capacity,capacitySize, sizeof(int), cmp);
    for (j = 0; additionalRocks>=0 || j < capacitySize; ++j) {
        additionalRocks -= capacity[j];
    }
    return j;
}