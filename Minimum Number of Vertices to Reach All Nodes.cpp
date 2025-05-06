#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<int> degree(n, 0);
        vector<int> res;
        for (auto edge : edges)
        {
            degree[edge[1]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};
    Solution sol;
    vector<int> nodes = sol.findSmallestSetOfVertices(n, edges);
    for (int i=0 ; i < nodes.size(); i++)
    {
        cout << nodes[i] << " ";
    }
    return 0;
}
