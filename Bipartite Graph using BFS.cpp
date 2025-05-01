#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool checkBipartite(int start , vector<vector<int>>&adj , vector<int>&vis)
    {
        queue<int>q;
        q.push(start);
        vis[start]=0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto adj_node : adj[node])
            {
                if(vis[adj_node]==-1)
                {
                    q.push(adj_node);
                    vis[adj_node]=1-vis[node];
                }
                else if(vis[adj_node] == vis[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
};


int main()
{
    int n,start;
    bool isBipartite=false;
    cin>>n>>start;
    vector<vector<int>> adj(n+1);
    vector<int>vis(n+1,-1);
    // adj[1]={2};
    // adj[2]={1,3,5};
    // adj[3]={2,4};
    // adj[4]={5,6};
    // adj[5]={2,4};
    // adj[6]={4};
    adj[1]={2};
    adj[2]={3,6};
    adj[3]={2,4};
    adj[4]={3,5,7};
    adj[5]={4,6};
    adj[6]={2,5};
    adj[7]={4,8};
    adj[8]={7};

    Solution sol;
    isBipartite = sol.checkBipartite(start , adj , vis);
    cout<<(isBipartite ? "The graph is Bipartite" : "The graph is not Bipartite");
}