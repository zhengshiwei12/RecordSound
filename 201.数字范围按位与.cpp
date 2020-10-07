// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem201.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift=0;
        while(m<n)
        {
            m>>=1;
            n>>=1;
            shift++;
        }
        return m<<shift;
        /*
        int res=m;
        while(m<n)
        {
            res=res&(++m);
        }
        return res;
        */
       //BK算法

    }
};
// @lc code=end

