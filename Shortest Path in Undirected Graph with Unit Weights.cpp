#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortestPath(int src, int n, int m, vector<vector<int>> &edges)
    {
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        vector<int> vis(n, 0);
        vector<vector<int>>adj(n);

        for(int i=0 ; i<m ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        dist[src]=0;

        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto adj_node : adj[node])
            {
                if (vis[adj_node] == 0)
                {
                    q.push(adj_node);
                    vis[adj_node] = 1;
                    dist[adj_node] = min(dist[adj_node], dist[node] + 1);
                }
            }
        }
        for(int i=0 ; i<n ; i++)
        {
            cout<<dist[i]<<" ";
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution sol;
    sol.shortestPath(0, n, m, edges);
}