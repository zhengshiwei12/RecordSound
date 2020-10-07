// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem213.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int maxmoney=0;
        vector<vector<int>> maxlocal(n,vector<int>(n));
        
        if(n<=0)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
        if(nums[0]!=0)
        {
            maxmoney=max(nums[0]+helper0(nums,2,nums.size()-2,maxlocal),helper0(nums,1,nums.size()-1,maxlocal));
        }else{
            maxmoney=helper0(nums,1,nums.size()-1,maxlocal);
        }
        return maxmoney;
    }
    int helper0(vector<int>& nums,int start,int end,vector<vector<int>>& maxlocal)
    {
        
        if(start>end)
        {
            return 0;
        }
        if(maxlocal[start][end]!=0)
        {
            return maxlocal[start][end];
        }
        if(start==end)
        {
            maxlocal[start][end]=nums[start];
            return nums[start];
        }
        if(nums[start]==0)
        {
            maxlocal[start][end]=helper0(nums,start+1,end,maxlocal);
        }else{
        maxlocal[start][end]=max(nums[start]+helper0(nums,start+2,end,maxlocal),helper0(nums,start+1,end,maxlocal));
        }
        return maxlocal[start][end];
    }
};
// @lc code=end

