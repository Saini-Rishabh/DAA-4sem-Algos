#include<bits/stdc++.h>
using namespace std;

class Solve
{
    public:
    bool Checkforcycle(int s,int v,vector<int>adj[],vector<int>&visited)
    {
        queue<pair<int,int>>q;

        visited[s]=true;//s is here will be the node which is passed by the is_check func
        q.push({s,-1});//assigns only for node which does not have any parent node

        while(!q.empty())
        {
            int node=q.front().first;
            int par=q.front().second;
            q.pop();

            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    q.push({it,node});
                }
                else if(par!=it)
                    return true;
            }
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
                if( Checkforcycle(i,v,adj,vis))
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
