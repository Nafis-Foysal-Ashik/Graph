#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void matrix_to_list(vector<vector<int>>graph)
    {
        int n=graph.size();
        vector<vector<int>>adj_list(n);
        for(int i=0 ; i<n ; i++)
        {
            int len = graph[i].size();
            for(int j=0 ; j<len ; j++)
            {
                adj_list[i].push_back(graph[i][j]);
            }
        }
        for(int i=0 ; i<n ; i++)
        {
            cout<<"Printing adj_list "<<i<<" : ";
            int len = adj_list[i].size();
            for(int j=0 ; j<len ; j++)
            {
                cout<<adj_list[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


int main()
{
    int n;
    cin>>n;
    vector<vector<int>>graph(n,vector<int>(n));

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin>>graph[i][j];
        }
    }
    Solution sol;
    sol.matrix_to_list(graph);
}