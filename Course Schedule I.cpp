#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
        {
            vector<vector<int>>adj(numCourses);
            vector<int>degree(numCourses,0);
            
            for(auto &pre : prerequisites)
            {
                adj[pre[1]].push_back(pre[0]);
                degree[pre[0]]++;
            }

        queue<int>q;
        int count=0;
        for(int i=0 ; i<numCourses ; i++)
        {
            if(degree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            count++;
            int node = q.front();
            q.pop();
            for(auto adj_node : adj[node])
            {
                degree[adj_node]--;
                if(degree[adj_node]==0)
                {
                    q.push(adj_node);
                }
            }
        }
        if(count==numCourses)
        {
            return true;
        }
        else
        {
            return false;
        }   
        }
    };

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>pre_req(n);
    Solution sol;
    bool res = false;
    res = sol.canFinish(n ,pre_req);
    cout<<(res ? "Passed all the courses" : "Failed at least one of the courses")<<endl;
}