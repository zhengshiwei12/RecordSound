/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        if(canFinish(numCourses,prerequisites))
        {
            return res;

        }else{
            res.clear();
            return res;
        }
    }
private:
    vector<int> res;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        //vector<int> degree(numCourses,0);
        //const int a=numCourses;
        int degree[numCourses];
        memset(degree,0,sizeof(int)*numCourses);
        int row=prerequisites.size();
        
        for(int i=0;i<row;i++)
        {
            degree[prerequisites[i][0]]++;
        }
        queue<int> myqueue;
        int visited_count=0;
        for(int i=0;i<numCourses;i++)
        {
            if(degree[i]==0)
            {
                myqueue.push(i);
                visited_count++;
            }
        }
        while(!myqueue.empty())
        {
            int size_queue=myqueue.size();
            for(int i=0;i<size_queue;i++)
            {
                int pre_study=myqueue.front();
                res.push_back(pre_study);
                myqueue.pop();
                for(int i=0;i<row;i++)
                {
                    if(prerequisites[i][1]==pre_study)
                    {
                        degree[prerequisites[i][0]]--;
                        if(degree[prerequisites[i][0]]==0)
                        {
                            myqueue.push(prerequisites[i][0]);
                            visited_count++;
                        }
                    }
                }
            }
        }
        return visited_count==numCourses?true:false;
    }
};
// @lc code=end

