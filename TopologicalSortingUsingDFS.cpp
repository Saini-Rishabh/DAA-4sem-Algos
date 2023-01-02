#include<bits/stdc++.h>
using namespace std;
//topological sorting is applied for Directed Acyclic Graph...
class Solution
{
    void findtoposort(int node,vector<int>&vis,stack<int>&st,vector<int>adj[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                findtoposort(it,vis,st,adj);
            }
        }
        st.push(node);
    }
    public:
    vector<int>toposort(int n,vector<int>adj[])
    {
        stack<int>st;//stack is specified here specially
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                findtoposort(i,vis,st,adj);
            }
        }
        vector<int>topo;
        while(!st.empty())//transfer the cotents of st to topo in reverse form
        {
            topo.push_back(st.top());
            st.pop();
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