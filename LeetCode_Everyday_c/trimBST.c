//
// Created by Zza on 2022/9/10.
//

#include "stdlib.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 还是把空指针交给子情况吧
// 很傻逼，二叉搜索树的性质都忘记了，左边的小于节点，右边的一定大于
// 这个内容上课是肯定讲过的

void right_spin(struct TreeNode*);
// right_spin 不会修改根的地址，修改根的数值

struct TreeNode* trimBST(struct TreeNode* root, int low, int high){
//    先判断根节点有效性，否则右旋
    while (root->val<low){
        right_spin(root);
    }
}

void right_spin(struct TreeNode* root){
    if
}