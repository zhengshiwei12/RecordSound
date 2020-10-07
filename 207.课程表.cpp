// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem207.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start

class Solution {
public:
    //[1,0]想学课程1时必须先学课程0
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

    bool isAllStudy(bool* isstudy,int num)
    {
        for(int i=0;i<num;i++)
        {
            if(!isstudy[i])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

