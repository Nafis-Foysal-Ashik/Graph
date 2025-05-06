#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs_call(int node, int &nodes, int &edge, vector<vector<int>> &adj, vector<int> &vis)
    {
        nodes++;
        vis[node] = 1;
        for (auto adj_node : adj[node])
        {
            edge++;
            if (vis[adj_node] == 0)
            {
                dfs_call(adj_node, nodes, edge, adj, vis);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        int nodes, edge, count = 0;

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++)
        {
            nodes = 0;
            edge = 0;
            if (vis[i] == 0)
            {
                dfs_call(i, nodes, edge, adj, vis);
                edge = edge / 2;
                if (edge == nodes * (nodes - 1) / 2)
                {
                    count++;
                }
            }
        }
        return count;
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
    int components = sol.countCompleteComponents(n, edges);

    cout << components << endl;
}