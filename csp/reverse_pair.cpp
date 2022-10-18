//
// Created by Zza on 2022/10/15.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> raw, var;

#define data long long

//合并有序数列，并在合并时计算逆序对
data mergeCountInversions(int left, int mid, int right)
{
    data count = 0;
    //归并到临时数组中
    int i = left, j = mid + 1;
    for (int k = left; k <= right; k++) {
        if ((j > right) || (i <= mid) && (raw[i] <= raw[j]))
            var[k] = raw[i++];
        else {
            var[k] = raw[j++];
            count += mid - i + 1;		//计算逆序对数
        }
    }

    //拷贝回数组a
    for (int i = left; i <= right; i++)
        raw[i] = var[i];

    return count;
}

//通过归并排序计算逆序对
data countInversions_mergeSort(int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        //当前数组内的逆序对数等于两个子数组的逆序对数加上归并时计算出的逆序对数
        return countInversions_mergeSort(left, mid)
               + countInversions_mergeSort(mid + 1, right)
               + mergeCountInversions(left, mid, right);
    }
    else
        return 0;
}


int main(){
    int n;  cin>>n;
    raw.resize(n); var.resize(n);
    for(auto &i:raw)cin >> i;
    cout<<countInversions_mergeSort(0, raw.size() - 1);
    return 0;
}
