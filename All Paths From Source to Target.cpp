#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void dfs_call(int node , vector<vector<int>>adj , vector<int>&path , vector<vector<int>>&ans)
        {
            path.push_back(node);
            if(node==adj.size()-1)
            {
                ans.push_back(path);
            }
           for(auto adj_node : adj[node])
           {
                dfs_call(adj_node , adj , path , ans);
           }
           path.pop_back();
        }
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
            int src = 0;
            int target = graph.size()-1;
            vector<int>path;
            vector<vector<int>>ans;
            path.push_back(src);
            for(auto adj_node : graph[src])
            {
                dfs_call(adj_node , graph , path , ans);
            }
            return ans;
        }
    };

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    adj[0]={1,3,4};
    adj[1]={2,3,4};
    adj[2]={3};
    adj[3]={4};
    adj[4]={};
    Solution sol;
    vector<vector<int>> path = sol.allPathsSourceTarget(adj);
    for (const auto& p : path) {
        for (int node : p) {
            cout << node << " ";
        }
        cout << endl;
    }
}