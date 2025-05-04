#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void findOrder(string dict[] , int n , int k)
    {
        vector<int>adj[k];
        for(int i=0 ; i<n-1 ; i++)
        {
            //cout<<"a"<<endl;
            string str1=dict[i];
            string str2=dict[i+1];
            int len = min(str1.length() , str2.length());
            for(int i=0 ; i<len ; i++)
            {
                if(str1[i]!=str2[i])
                {
                    adj[str1[i]-'a'].push_back(str2[i]-'a');
                    break;
                }
            }
        }
        vector<int>degree(k,0);
        queue<int>q;
        string list="";
        for(int i=0 ; i<k ; i++)
        {
            for(auto adj_node : adj[i])
            {
                degree[adj_node]++;
            }
        }
        // for(int i=0 ; i<k ; i++)
        // {
        //     cout<<degree[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0 ; i<k ; i++)
        {
            if(degree[i]==0)
            {
                q.push(i);
            }
        }
        // cout<<q.front()<<endl;
        while(!q.empty())
        {
            int node = q.front();
            // cout<<node;
            q.pop();
            list+=(node);
            for(auto adj_node : adj[node])
            {
                degree[adj_node]--;
                if(degree[adj_node]==0)
                {
                    q.push(adj_node);
                }
            }
        }
        for(int i=0 ; i<list.length() ; i++)
        {
            list[i]+='a';
            cout<<list[i];
        }
    }

};

int main()
{
    int n,k;
    cin>>n>>k;
    string str[n];
    str[0]="baa";
    str[1]="abcd";
    str[2]="abca";
    str[3]="cab";
    str[4]="cad";
    Solution sol;
    sol.findOrder(str , n , k);
}