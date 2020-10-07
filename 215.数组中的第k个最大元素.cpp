/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        return helper(nums,0,nums.size()-1,nums.size()-k);
    }
    int helper(vector<int>& nums,int left,int right,int index)
    {
        int q=helper01(nums,left,right);
        if(q==index)
        {
            return nums[q];
        }else{
            return q<index?helper(nums,q+1,right,index):helper(nums,left,q-1,index);
        }
    }
    int helper01(vector<int>& nums,int l,int r)
    {
        int x=nums[r];
        int i=l;
         for (int j = l; j < r; ++j) {
            if (nums[j] <= x) {
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[i],nums[r]);
        return i;

    }
    void swap(int& a,int& b)
    {
        int tmp=a;
        a=b;
        b=tmp;

    }

};
// @lc code=end

