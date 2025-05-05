#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    vector<int>bellman(int src , int n , int m , vector<vector<int>>&edges)
    {
        vector<int>dist(n , INT_MAX);
        dist[src]=0;
        vector<vector<pair<int,int>>>adj(n);

        // for(auto adj_node : adj[])

        for(int i=0 ; i<n-1 ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];


                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        return dist;
    }
};


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m , vector<int>(3));
    for(int i=0 ; i<m ; i++)
    {
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    Solution sol;
    vector<int>distance = sol.bellman(0 , n , m , edges);

    for(int i=0 ; i<n ; i++)
    {
        cout<<distance[i]<<" ";
    }
}

/*
6 7
3 2 6
5 3 1
0 1 5
1 5 -3
1 2 -2
3 4 -2
2 4 3
*/