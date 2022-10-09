//
// Created by Zza on 2022/10/8.
//

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ids =
                [nums1]()->vector<int> {
                    std::vector<int> v; v.resize(2*nums1.size());
                    for (int i = 0; i < nums1.size(); ++i){
                        v[i] = i+1; v[i+nums1.size()] = -(i+1);
                    }
                    return v;
                }();    // 这里后面要有个括号表示调用

        vector<int> ans = nums1;
        sort(ids.begin(),ids.end(),[nums1, nums2](int n1, int n2)->int {
            if (n1<0)n1 = nums1[abs(n1)-1];
            else n1 = nums2[n1-1];
            if (n2<0)n2 = nums1[abs(n2)-1];
            else n2 = nums2[n2-1];
            return n1 - n2;
        });

        for(int i=0, pos=0; i<ids.size(); i++){
            while (pos<ids.size() && ids[pos]<0) pos++;
            if (ids[i] <0){
                ans[ids[pos]-1] = nums1[abs(ids[i])-1];
                pos++;
            }
        }

        return ans;
    }
};

class _Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int i, int j) { return nums1[i] < nums1[j]; });
        sort(idx2.begin(), idx2.end(), [&](int i, int j) { return nums2[i] < nums2[j]; });

        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (nums1[idx1[i]] > nums2[idx2[left]]) {
                ans[idx2[left]] = nums1[idx1[i]];
                ++left;
            }
            else {
                ans[idx2[right]] = nums1[idx1[i]];
                --right;
            }
        }
        return ans;
    }
};


int main(){
//    [2,0,4,1,2]
//    [1,3,0,0,2]
    vector<int> n1= {2,0,4,1,2};
    vector<int> n2= {1,3,0,0,2};

    Solution obj;
    vector<int> res = obj.advantageCount(n1,n2);

    return 0;
}
