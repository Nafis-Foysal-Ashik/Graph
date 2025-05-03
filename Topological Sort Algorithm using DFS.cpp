#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool topological_sort(int node , vector<vector<int>>&adj , vector<int>&vis , stack<int>&s)
    {
        vis[node]=1;
        for(auto it : adj[node])
        {
            if(vis[it]==0)
            {
                //s.push(it);
                topological_sort(it , adj , vis , s);
            }
        }
        s.push(node);
        return true;
    }
};

int main()
{
    int n;
    stack<int>s;
    cin>>n;
    vector<int>vis(n+1 , 0);
    vector<vector<int>>adj(n+1);

    adj[0]={};
    adj[1]={};
    adj[2]={3};
    adj[3]={1};
    adj[4]={0,1};
    adj[5]={0,2};

    Solution sol;

    for(int i=0 ; i<=n ; i++)
    {
        if(vis[i]==0)
        {
            bool res = sol.topological_sort(i , adj , vis , s);
        }
    }
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        cout<<x<<" ";
    }
}