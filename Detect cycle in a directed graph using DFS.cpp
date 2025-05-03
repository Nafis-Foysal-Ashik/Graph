#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isCycle(int node , vector<vector<int>>&adj , vector<int>&vis , vector<int>&parent)
    {
        vis[node]=1;
        parent[node]=1;
        for(auto adj_node : adj[node])
        {
            if(vis[adj_node]==0)
            {
                bool dfs_call = isCycle(adj_node , adj , vis , parent);
                if(dfs_call)
                {
                    return true;
                }
            }
            else if(parent[adj_node])
            {
                return true;
            }
        }
        parent[node]=0;
        return false;
    }
};

int main()
{

    int n;
    bool hasCycle=false;
    cin>>n;
    vector<int>vis(n+1,0);
    vector<int>parent(n+1,0);
    vector<vector<int>>adj(n+1);
    
    // adj[0]={};
    // adj[1]={2};
    // adj[2]={3};
    // adj[3]={4,7};
    // adj[4]={5};
    // adj[5]={6};
    // adj[6]={};
    // adj[7]={5};
    // adj[8]={2,9};
    // adj[9]={10};
    // adj[10]={2};

    adj[0]={};
    adj[1]={2};
    adj[2]={3};
    adj[3]={4,7};
    adj[4]={5};
    adj[5]={6};
    adj[6]={};
    adj[7]={5};
    adj[8]={2,9};
    adj[9]={10};
    adj[10]={8};

    Solution sol;
    for(int i=0 ; i<=n ; i++)
    {
        if(vis[i]==0)
        {
            hasCycle = sol.isCycle(i , adj , vis , parent);
            if(hasCycle)
            {
                break;
            }
        }
    }
    cout<<(hasCycle ? "Cycle Exits" : "Cycle does not Exits");
}