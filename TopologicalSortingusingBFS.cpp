#include<bits/stdc++.h>
using namespace std;
//topological sorting is applied for Directed Acyclic Graph...
class Solution
{
    public:
    vector<int>toposort(int n,vector<int>adj[])
    {
        queue<int>q;//queue is used to implement Bfs. 
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++)
        for(auto it:adj[i])
            indegree[it]++;//raises the indegree by 1.

            for(int i=0;i<n;i++)
                if(indegree[i]==0)
                q.push(i);

        vector<int>topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])//check all the adjacent nodes
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);//subsequentially pushes in queue
                }
            }
        }
    return topo;
    }
};
int main()
{
   Solution s;
    int n,m;
    cin>>n>>m;

    vector<int>adj[n];//size will be taken as no. of nodes+1 so tha t all will be shown with correct numbers
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>res=s.toposort(n,adj);
    for(auto it=res.begin();it!=res.end();it++)
    {
        cout<<*it<<" ";
    }
}