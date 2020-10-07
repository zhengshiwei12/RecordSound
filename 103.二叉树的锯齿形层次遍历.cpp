// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem103.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ret;
        if(!root)
        {
            return ret;
        }
        queue<TreeNode* > q;
        q.push(root);
        bool flag=false;
        while(!q.empty())
        {
            int size=q.size();
            vector<int> tmp(size,0);
            //ret.push_back(tmp);
            for(int i=1;i<=size;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                if(!flag)//从左至右
                {
                    tmp[i-1]=t->val;
                }else{
                    tmp[size-i]=t->val;
                }
                //tmp[flag?size-i:0+i-1]=root->val;
                if(t->left)
                {
                    q.push(t->left);
                }
                if(t->right)
                {
                    q.push(t->right);
                }
            }
            ret.push_back(tmp);
            flag=!flag;
        }
        return ret;
        
    }
};
// @lc code=end

