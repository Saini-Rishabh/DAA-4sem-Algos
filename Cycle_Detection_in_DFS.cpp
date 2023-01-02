#include<bits/stdc++.h>
using namespace std;

class Solve
{
    public:
    bool Checkforcycle(int node,int parent,vector<int>&vis,vector<int>adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(Checkforcycle(it,node,vis,adj)) //Stack principle in dfs is applied through this recursion..
                return true;
            }
            else if(it!=parent)
                return true; //if traversal is one way then this condition is not true..
        }
        return false;
    }
  
    bool is_cycle(int v,vector<int>adj[])
    {
        vector<int>vis(v+1,0);
        for(int i=1;i<=v;i++)
        {
            if(!vis[i])
            {
                if( Checkforcycle(i,-1,vis,adj))//called for disconnected components for graph..
                return true;
            }
        }
        return false;
    }
};
int main()
{
    Solve  s;
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
    int num=s.is_cycle(n,adj);
    if(num==1)
        cout<<"Cycle Exists";
    else
        cout<<"Cycle Does Not Exists";
    return 0;

}