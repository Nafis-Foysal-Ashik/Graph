#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findCenter(vector<vector<int>>& edges) {
            
            if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1])
            {
                return edges[0][0];
            }
            else
            {
                return edges[0][1];
            }

        }
    };

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m , vector<int>(2));
    for(int i=0 ; i<m ; i++)
    {
        cin>>edges[i][0]>>edges[i][1];
    }
    Solution sol;

    int node = sol.findCenter(edges);

    cout<<node;
}