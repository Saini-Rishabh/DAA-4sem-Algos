#include<bits/stdc++.h>
using namespace std;//starts indexing by 0..

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n];
    int a,b,wt;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>wt;
        adj[a].push_back(make_pair(b,wt));
        adj[b].push_back(make_pair(a,wt));
    }
    int parent[n];
    int key[n];
    bool mst[n];

    for(int i=0;i<n;i++)
    key[i]=INT_MAX, mst[i]=false;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;

    key[0]=0;
    parent[0]=-1;
    pq.push({0,0});
    for(int i=0;i<n;i++)
    {
        int u=pq.top().first;
        pq.pop();
    
        mst[u]=true;//condition which becomes true get included in MST..
        for(auto it: adj[u])
        {
            int v=it.first;
            int weight=it.second;
            if(mst[v]==false && weight<key[v])
            {
                parent[v]=u;
                key[v]=weight;
                pq.push({v,key[v]});
            }
        }
    }
    for(int i=1;i<n;i++)
            cout<<parent[i]<<"-"<<i<<"\n";
    return 0;
}