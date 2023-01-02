#include<bits/stdc++.h>
using namespace std;

class Solve
{
    public:
    vector<int>bfsofgraph(int v,vector<int>adj[])
    {
        vector<int>bfs;
        vector<int>vis(v+1,0);//initializing all with zeros

        for(int i=1;i<=v;i++)//iterates so that it makes sure that every node is visited
        {
            if(!vis[i])
            {
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(!q.empty())//bfs starts from here
                {
                    int node=q.front();
                    q.pop();
                    bfs.push_back(node);

                    for(auto it:adj[node])
                    {
                        if(!vis[it])
                        {
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
            }
        }
        return bfs;
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
       // adj[v].push_back(u);
    }
    vector<int>res=s.bfsofgraph(n,adj);
    for(auto it=res.begin();it!=res.end();it++)
    {
        cout<<*it<<" ";
    }
}
