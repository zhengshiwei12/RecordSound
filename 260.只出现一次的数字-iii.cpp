// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem260.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask=0;
        for(int i:nums)
        {
            mask^=i;
        }
        int diff=mask&(-mask);
        vector<int> v;
        int res1=0;
        for(int i:nums)
        {
            if(i&diff)
            {
                res1^=i;
            }
        }
        v.push_back(res1);
        v.push_back(res1^mask);
        return v;
    }
};
// @lc code=end

