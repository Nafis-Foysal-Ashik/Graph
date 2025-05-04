#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs_call(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& s) {
        vis[node] = 1;
        for (auto& adj_node : adj[node]) {
            int neighbour = adj_node.first;
            if (!vis[neighbour]) {
                dfs_call(neighbour, adj, vis, s);
            }
        }
        s.push(node);
    }

public:
    void shortestPath(int src, int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(n, 0);
        vector<int> dist(n, INT_MAX);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs_call(i, adj, vis, s);
            }
        }

        dist[src] = 0;

        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (dist[node] != INT_MAX) {
                for (auto& adj_node : adj[node]) {
                    int v = adj_node.first;
                    int wt = adj_node.second;
                    if (dist[v] > dist[node] + wt) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution sol;
    sol.shortestPath(0, n, m, edges);

    return 0;
}

/*
Sample Input:
7 8
6 4 2
6 5 3
4 0 3
4 2 1
0 1 2
1 3 1
2 3 3
5 4 1

6 7
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 5 1
4 5 2

*/
