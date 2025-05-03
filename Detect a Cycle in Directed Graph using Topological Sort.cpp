#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void degree_count(int n , vector<vector<int>>&adj , vector<int>&degree)
    {
        for(int i=0 ; i<=n ; i++)
        {
            for(auto adj_node : adj[i])
            {
                degree[adj_node]++;
            }
        }
        queue<int>q;
        int count=0;
        for(int i=0 ; i<=n ; i++)
        {
            if(degree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            count++;
            int node = q.front();
            q.pop();
            for(auto adj_node : adj[node])
            {
                degree[adj_node]--;
                if(degree[adj_node]==0)
                {
                    q.push(adj_node);
                }
            }
        }
        if(count==n)
        {
            cout<<"Cycle Exits"<<endl;
        }
        else
        {
            cout<<"Cycle does not exits"<<endl;
        }
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int>degree(n+1,0);
    vector<vector<int>> adj(n+1);

    adj[0]={};
    adj[1]={};
    adj[2]={3};
    adj[3]={1};
    adj[4]={0,1};
    adj[5]={0,2};

    Solution sol;
    sol.degree_count(n , adj , degree);
}