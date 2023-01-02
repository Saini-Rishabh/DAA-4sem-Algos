#include<bits/stdc++.h>
using namespace std;

bool BipartiteDfs(int node,vector<int>adj[],int color[])
{
    for(auto it:adj[node])
    {
        if(color[it]==-1)
        color[it]=1-color[node];
        if(!BipartiteDfs(it,adj,color))//checks for all the recursive ways
            return false;
        else if(color[it]==color[node])//check for odd cycle..
            return false;
    }
    return true;
}
bool checkBipartite(vector<int>adj[],int n)
{
    int color[n];
    memset(color,-1,sizeof color);//it assigns same color to all
    for(int i=0;i<n;i++)
    {  
        if(color[i]==-1)
        {
            color[i]=1;
            if(!BipartiteDfs(i,adj,color))
                return false;
        }
    }
    return true;
}
int main()
{
    int n,e;
    cout<<"Enter the Number of Nodes And Edges:"<<endl;
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
