#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> dfs_traversal(int node , vector<vector<int>> &adj , vector<int>&visited , vector<int>&dfs_vec)
    {
        cout<<node<<" ";
        dfs_vec.push_back(node);
        visited[node]=1;
        for(auto it : adj[node])
        {
            if(visited[it]==0)
            {
                dfs_traversal(it , adj , visited , dfs_vec);
            }
        }
        //return {0 , 1 ,2};
    }
};


int main()
{
    int n,start;
    cin>>n>>start;
    vector<vector<int>> adj(n+1);
    vector<int>visited(n+1 , 0);
    vector<int>dfs_vec;
    adj[1]={2,3};
    adj[2]={5,6};
    adj[3]={1,4,7};
    adj[4]={3,8};
    adj[5]={2};
    adj[6]={2};
    adj[7]={3,8};
    adj[8]={4,7};
    Solution sol;
    vector<int>dfs = sol.dfs_traversal(start , adj , visited , dfs_vec);
}