#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    int n,e;
    cout<<"Please Enter the Number Of Nodes and Edges:";
    cin>>n>>e;
    vector<node>edges(n+1);
    for(int i=0;i<n;i++)
    {
        int a,b,wt;
        cin>>a>>b>>wt;
        edges.push_back(node(a,b,wt));
    }
    int src;
    cout<<"Enter The Source Node:";
    cin>>src;
    int inf = 10000000; 
    vector<int> dist(n, inf); 
    dist[src] = 0; 
    for(int i = 1;i<n;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << -1; 
            fl = 1; 
            break; 
        }
    }
    
    if(!fl) {
        for(int i = 0;i<n;i++) {
            cout << dist[i]<<" ";
        }
    }
    return 0;
}