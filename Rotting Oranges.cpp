#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();

            int visited[n][m];
            queue<pair<pair<int,int>,int>>q;

            for(int i=0 ; i<n ; i++)
            {
                for(int j=0 ; j<m ; j++)
                {
                    if(grid[i][j]==2)
                    {
                        q.push({{i,j},0});
                        visited[i][j]=2;
                    }
                    else
                    {
                        visited[i][j]=0;
                    }
                }
            }

            int time=0;
            int delta_row[]={-1 , 0 , 1 , 0};
            int delta_col[]={0 , 1 , 0 , -1}; 

            while(!q.empty())
            {
                int current_row = q.front().first.first;
                int current_col = q.front().first.second;
                int t = q.front().second;

                time=max(time , t);
                q.pop();

                for(int i=0 ; i<4 ; i++)
                {
                    int new_row = current_row + delta_row[i];
                    int new_col = current_col + delta_col[i];
                    if(new_row>=0 && new_row<n && new_col>=0 && new_col<n && grid[new_row][new_col]==1 && visited[new_row][new_col]==0)
                    {
                        q.push({{new_row,new_col} , time+1});
                        visited[new_row][new_col] = 2;
                        grid[new_row][new_col]=2;
                    }
                }
            }

            for(int i=0 ; i<n ; i++)
            {
                for(int j=0 ; j<m ; j++)
                {
                    if(visited[i][j]!=2 && grid[i][j]==1)
                    {
                        return -1;
                    }
                }
            }

            return time;

        }
    };

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>v(n , vector<int>(n));
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            cin>>v[i][j];
        }
    }
    Solution sol;
    int res = sol.orangesRotting(v);
    cout<<res<<endl;
}