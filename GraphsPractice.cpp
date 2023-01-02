/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N]; vis[N];

void dfs(int vertex)
{
    if(vis[vertex]) return ;
    vis[vertex]=true;
    for(int child:g[vertex])
    {
        dfs(child);
    }
    return isLoopExists:
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> graph[n];
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<graph[i].<<endl;
    }    
    return 0;
}
int main()
{
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
    for(int i=0; i<n+1; i++)
        {
            cout<<i<< " ";
            for(int j=0; j<adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout<< endl;
        }
        return 0;
}*/
#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(checkBipartite(adj, n)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}
