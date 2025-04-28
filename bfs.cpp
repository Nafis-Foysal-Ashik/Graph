#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> bfs_traversal(int start , vector<vector<int>> adj , int n)
    {
        vector<int> visited(n+1,0);
        vector<int>bfs_vec;
        queue<int>q;
        q.push(start);
        visited[start]=1;
        int i=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs_vec.push_back(node);
            for(auto it : adj[node])
            {
                if(visited[it]==0)
                {
                    visited[it]=1;
                    q.push(it);
                }

            }
        }
        return bfs_vec;
    }
};

int main()
{
    int n,x;
    cin>>n>>x;
    vector<vector<int>>adj(n+1);
    // adj[0]={};
    adj[1]={2,6};
    adj[2]={1,3,4};
    adj[3]={2};
    adj[4]={2,5};
    adj[5]={4,8};
    adj[6]={1,7,9};
    adj[7]={6,8};
    adj[8]={5,7};
    adj[9]={6};

    Solution sol;
    vector<int>bfs =sol.bfs_traversal(x , adj , n); 
    for(int i=0 ; i<bfs.size() ; i++)
    {
        cout<<bfs[i]<<" ";
    }
}