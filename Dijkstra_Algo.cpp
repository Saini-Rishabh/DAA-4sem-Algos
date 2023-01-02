#include<bits/stdc++.h>
using namespace std;
//Dijkstra's Algorithm checks all the possible scenerios
//it works for both directed and undirected
//it does not works for negative cycles ..
int main()
{
    int n,e,src;
    cout<<"Please Enter the Number of Nodes:";
    cin>>n;
    cout<<"Please Enter the Number of Edges:";
    cin>>e;
    vector<pair<int ,int>> A[n+1];
    for(int i=0;i<e;i++)//stores all the nodes in graph with their weights
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        A[u].push_back(make_pair(v,wt));
        A[v].push_back(make_pair(u,wt));
    }
    cout<<"Enter The Source Node:";
    cin>>src;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//min heap transform it helps in choosing optimal steps by steps..
    vector<int>dist_to(n+1,INT_MAX);//initialising distance to largest int value possible

    dist_to[src]=0;//initializing source from itself as >0.
    pq.push(make_pair(0,src));//stores in form of (distance ,source)
    while(!pq.empty())
    {
        int dist=pq.top().first;
        int prev=pq.top().second;//check for present position
        pq.pop();

        vector<pair<int,int>>::iterator it;
        for(it=A[prev].begin();it!=A[prev].end();it++)//for loop only pushes elements in queue..
        {
            int next=it->first;
            int nextDist=it->second;//if undirected it check the condition more than once if it encounters the situation
            if(dist_to[next]>dist_to[prev]+nextDist)//greedy approach applies here..
            {
                dist_to[next]=dist_to[prev]+nextDist;
                pq.push(make_pair(dist_to[next],next));//elements pushed here are called at while loop
            }
        }
    }
    cout<<"Distance From Source "<<src<<"are:\n";
    for(int i=1;i<=n;i++)
        cout<<"Distance from "<<src<<" to "<<i<<" are "<<dist_to[i]<<"\n";
    cout<<"\n";
    return 0;

}