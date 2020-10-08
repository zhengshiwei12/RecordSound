/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] 棒球比赛
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {

        stack<int> ss;//记录每一轮的有效得分
        int ans=0;//总分数
        int num;//cur
        for(int i=0;i<ops.size();i++)
        {
            //数字
            if(ops[i].size()>1)
            {
                num=atoi(ops[i].c_str());
                ans+=num;
                ss.push(num);
            }
            else{
                if(ops[i][0]>='0'&&ops[i][0]<='9')
                {
                    num=atoi(ops[i].c_str());
                    ans+=num;
                    ss.push(num);
                }else if(ops[i][0]=='+'){
                    int a=ss.top();
                    ss.pop();
                    int b=ss.top();
                    ss.push(a);
                    ss.push(a+b);
                    ans+=(a+b);
                }else if(ops[i][0]=='C')
                {
                    int a=ss.top();
                    ss.pop();
                    ans-=a;
                }else if(ops[i][0]=='D')
                {
                    int a=ss.top();
                    ans+=a*2;
                    ss.push(a*2);
                }
            }

        }
        return ans;


    }
};
// @lc code=end

