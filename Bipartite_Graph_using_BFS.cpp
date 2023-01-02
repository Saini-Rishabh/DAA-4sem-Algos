#include<bits/stdc++.h>
using namespace std;
bool BipartiteBfs(int sr,vector<int>adj[],int color[])
{
    queue<int>q;
    q.push(sr);
    color[sr]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                q.push(it);
            }
             else if(color[it]==color[node])
                return false;
        }
    }
    return true;
}
bool checkBipartite(vector<int>adj[],int n)
{
    int color[n];
    memset(color,-1,sizeof color);  //store the colour of each nodes 
    for(int i=0;i<n;i++)
    {
        if(color[i]==-1)
        {
            if(!BipartiteBfs(i,adj,color))
            return false;
        }
    }
    return true;
}
int main()
{
    int n,e;
    cout<<"Enter the Number of Nodes And Edges:/n";
    cin>>n>>e;

    vector<int>adj[n];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(checkBipartite(adj,n))
        cout<<"Haan";
    else 
        cout<<"Naa";
    return 0;
}

