// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1051.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution {
public:
//桶排序思想
    int heightChecker(vector<int>& heights) {
        
        int arr[101];
        memset(arr,0,sizeof(int)*101);
        for(int& i:heights)
        {
            arr[i]++;
        }
        int count=0;
        int j=0;
        for(int i=1;i<101;i++)
        {
            while(arr[i]-->0)
            {
                if(heights[j++]!=i)
                {
                    count++;
                }
            }
        }
        return count;


    }
};
// @lc code=end

