#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&storeDfs)
    {
        storeDfs.push_back(node);
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,vis,adj,storeDfs);
            }
        }
    }
    vector<int>dfsofgraph(int v,vector<int>adj[])
    {
        vector<int>storeDfs;
        vector<int>vis(v+1,0);
        for(int i=1;i<=v;i++)//condition used to handle undirected graphs
        {
            if(!vis[i])
            {
                dfs(i,vis,adj,storeDfs);
            }
        }
        return storeDfs;
    }

};
int main()
{
    Solution s;
    int n,m;
    cin>>n>>m;

    vector<int>adj[n+1];//size will be taken as no. of nodes+1 so tha t all will be shown with correct numbers
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>res=s.dfsofgraph(n,adj);
    for(auto it=res.begin();it!=res.end();it++)
    {
        cout<<*it<<" ";
    }
}
