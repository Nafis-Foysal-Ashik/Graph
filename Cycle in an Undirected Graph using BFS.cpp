#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool checkCycle(int n , vector<vector<int>>&adj , vector<int> &vis)
    {
        queue<pair<int,int>>q;
        for(int i=0 ; i<n ; i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                q.push({i,-1});
                while(!q.empty())
                {
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    for(auto neighbour_node : adj[node])
                    {
                        if(vis[neighbour_node]==0)
                        {
                            vis[neighbour_node]=1;
                            q.push({neighbour_node , node});
                        }
                        else if(vis[neighbour_node]==1 && neighbour_node != parent)
                        {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int>vis(n,0);
    vector<vector<int>>adj(n);
    adj[0]={1};
    adj[1]={0,2,4};
    adj[2]={1,5};
    adj[3]={4};
    adj[4]={1,3};
    adj[5]={2};
    Solution sol;
    bool res = sol.checkCycle(n,adj,vis);
    cout<<res<<endl;
}