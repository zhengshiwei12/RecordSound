// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int sum=0;
        for(int i:nums)
        {
            sum+=i;
        }
        int l=0;
        int r=0;
        if(sum<s)
        {
            return 0;
        }
        if(sum==s)
        {
            return nums.size();
        }
        int tmp=0;
        int minlen=nums.size();
        while(l<nums.size())
        {
            while(tmp<s&&l<nums.size())
            {
                tmp+=nums[l];
                l++;
            }
            l--;
            while(r<=l&&tmp>=s)
            {
                tmp-=nums[r];
                r++;
            }
            r--;
            tmp+=nums[r];
            if(tmp>=s){
                minlen=(minlen>(l-r+1)?l-r+1:minlen);
            }
           
            tmp-=nums[r];
            r++;
            l++;
        }
        return minlen;
    }
};
// @lc code=end

