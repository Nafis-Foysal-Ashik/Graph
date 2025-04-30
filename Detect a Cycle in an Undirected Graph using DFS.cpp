#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool detectCycle(int node, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto adj_node : adj[node]) { 
            if (vis[adj_node] == 0) {
                if (detectCycle(adj_node, node, adj, vis)) {
                    return true;
                }
            } else if (adj_node != parent) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> vis(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    adj[1] = {2, 3};
    adj[2] = {1, 5};
    adj[3] = {4, 6};
    adj[4] = {3};
    adj[5] = {2, 7};
    adj[6] = {3, 7};
    adj[7] = {5, 6};

    Solution sol;
    bool hasCycle = false;

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (sol.detectCycle(i, -1, adj, vis)) {
                hasCycle = true;
                break;
            }
        }
    }

    cout << (hasCycle ? "Cycle detected" : "No cycle detected") << endl;
    return 0;
}