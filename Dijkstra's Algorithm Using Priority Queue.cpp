#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int src, int n, int m, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        pq.push({dist[src], src});
        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto adj_node : adj[node])
            {
                int next_node = adj_node.first;
                int weight = adj_node.second;
                if (dist[next_node] > dist[node] + weight)
                {
                    dist[next_node] = dist[node] + weight;
                    pq.push({dist[next_node], next_node});
                }
            }
        }
        return dist;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    Solution sol;
    vector<int> distance_arr = sol.dijkstra(0, n, m, edges);
    for (int i = 0; i < n; i++)
    {
        cout << distance_arr[i] << " ";
    }
}