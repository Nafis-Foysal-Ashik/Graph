#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    bool checkBipartite(int node , vector<vector<int>>&adj , vector<int>&vis)
    {
        for(auto adj_node : adj[node])
        {
            if(vis[adj_node]==-1)
            {
                vis[adj_node]=1-vis[node];
                checkBipartite(adj_node , adj , vis);
                if (!checkBipartite(adj_node, adj, vis)) {
                    return false;
                }
            }
            else if(vis[adj_node]==vis[node])
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    int n;
    bool res = false;
    cin>>n;
    vector<vector<int>>adj(n+1);
    vector<int>vis(n+1 , -1);

    vis[1]=0;  

    // adj[1]={2};
    // adj[2]={3,6};
    // adj[3]={2,4};
    // adj[4]={3,5,7};
    // adj[5]={4,6};
    // adj[6]={2,5};
    // adj[7]={4,8};
    // adj[8]={7};

    adj[1]={2};
    adj[2]={1,3,5};
    adj[3]={2,4};
    adj[4]={5,6};
    adj[5]={2,4};
    adj[6]={4};

    Solution sol;
    res = sol.checkBipartite(1 , adj , vis);
    cout<<(res ? "This is a Bipartite Graph" : "This is not a Bipartite Graph");
}