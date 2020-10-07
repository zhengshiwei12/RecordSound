/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=5)
        {
            if(n==1)
            {
                return 1;
            }else if(n==2){
                return 2;
            }else if(n==3)
            {
                return 3;
            }else if(n==4)
            {
                return 4;
            }else if(n==5)
            {
                return 5;
            }else{
                return 0;
            }
        }

        int num2=2;
        int num3=1;
        int num5=1;
        int F[n];
        memset(F,0,sizeof(int)*n);
        F[0]=1;
        F[1]=2;
        F[2]=3;
        F[3]=4;
        F[4]=5;
        
        for(int i=5;i<n;i++)
        {
            F[i]=min(min(F[num2]*2,F[num3]*3),F[num5]*5);
            if(F[i]==(F[num2]*2))
            {
                num2++;
            }
            if(F[i]==(F[num3]*3))
            {
                num3++;
            }
            if(F[i]==(F[num5]*5))
            {
                num5++;
            }
        }
        return F[n-1];

    }
};
// @lc code=end

