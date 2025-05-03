#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>>adj(numCourses);
            vector<int>degree(numCourses,0);
            
            for(auto &pre : prerequisites)
            {
                adj[pre[1]].push_back(pre[0]);
                degree[pre[0]]++;
            }

        queue<int>q;
        vector<int>node_list;
        for(int i=0 ; i<numCourses ; i++)
        {
            if(degree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            node_list.push_back(node);
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
        if(q.size()==numCourses)
        {
            return node_list;
        }
        return {};
        }
    };

    int main()
{
    int n;
    cin>>n;
    vector<vector<int>>pre_req(n);
    Solution sol;
    vector<int>res;
    res = sol.findOrder(n ,pre_req);
    for(auto x : res)
    {
        cout<<x<<" ";
    }
}