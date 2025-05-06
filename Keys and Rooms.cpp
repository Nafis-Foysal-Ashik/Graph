#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n = rooms.size(); 
            vector<int>vis(n,0);
            queue<int>q;
            q.push(0);
            vis[0]=1;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(auto adj_node : rooms[node])
                {
                    if(vis[adj_node]==0)
                    {
                        vis[adj_node]=1;
                        q.push(adj_node);
                    }
                }
            }
            for(int i=0 ; i<n ; i++)
            {
                if(vis[i]==0)
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
    cin>>n;
    vector<vector<int>>adj(n);
    adj[0]={1};
    adj[1]={2};
    adj[2]={3};
    adj[3]={};
    Solution sol;
    bool res = sol.canVisitAllRooms(adj);
    cout<<(res ? "true" : "false");
}