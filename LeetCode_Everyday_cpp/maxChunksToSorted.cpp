
// here we talk about the subproblem
/*
    that we aim to get [0,a0]...[am-1,am]
    however it could be restruct as [0,a1]...[0,am]

    because if [0,a1] is fit and [0,am] is fit
    then [a1,am] must be fit

    for [0,ai] if the max of interval eq the i, the intveral fit the condi

    then we have the algor below

*/

#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            m = max(m, arr[i]);
            if (m == i) {
                res++;
            }
        }
        return res;
    }
};