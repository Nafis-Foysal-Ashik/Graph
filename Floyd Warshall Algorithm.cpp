#include<bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>>&matrix)
{
    for(int i=0 ; i<matrix.size() ; i++)
    {
        for(int j=0 ; j<matrix.size() ; j++)
        {
            if(matrix[i][j]==-1 && i!=j)
            {
                matrix[i][j]=1e9;
            }
            else if(i==j)
            {
                matrix[i][j]=0;
            }
        }
    }


    for(int via=0 ; via<matrix.size() ; via++)
    {
        for(int i=0 ; i<matrix.size() ; i++)
        {
            for(int j=0 ; j<matrix.size() ; j++)
            {
                matrix[i][j]=min(matrix[i][j] , matrix[i][via]+matrix[via][j]);
            }
        }
    }
    
    for(int i=0 ; i<matrix.size() ; i++)
    {
        for(int j=0 ; j<matrix.size() ; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>>matrix;
    for(int i=0 ; i<n ; i++)
    {
        vector<int>v(n);
        for(int j=0 ; j<n ; j++)
        {
            cin>>v[j];
        }
        matrix.push_back(v);
    }

    floyd_warshall(matrix);
}