#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool detectCycle(int node , vector<vector<int>>&adj , vector<int>&vis , vector<int>&parent)
    {
        vis[node]=1;
        for(auto adj_node : adj[node])
        {
            if(vis[adj_node]==0)
            {
                parent[adj_node]=node;
                if(detectCycle(adj_node , adj , vis , parent))
                {
                    return true;
                }
            }
            else if(parent[node] != adj_node)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int n;
    bool res=false;
    cin>>n;
    vector<int>vis(n+1 , 0);
    vector<int>parent(n+1 , -1);
    vector<vector<int>> adj(n+1);
    adj[0]={};
    adj[1] = {2, 3};
    adj[2] = {1, 5};
    adj[3] = {4, 6};
    adj[4] = {3};
    adj[5] = {2, 7};
    adj[6] = {3, 7};
    adj[7] = {5, 6};
    Solution sol;
    for(int i=1 ; i<=n ; i++)
    {
       res = sol.detectCycle(i , adj , vis , parent);
       if(res)
       {
            break;
       }
    }

    cout<<(res ? "Cycle Exists" : "Cycle does not exists");
}