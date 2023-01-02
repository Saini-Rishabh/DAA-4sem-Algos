#include<bits/stdc++.h>
using namespace std;//by the method of adjacency matrix.
const int INF=1e9+10;

const int N=510;
 int dp[N][N];
int main()
{
    int n,m;
    cout<<"Enter the Number Of Nodes And Edges:";
    cin>>n>>m; 
   
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(i==j)dp[i][j]==0;//distance of a node from itself will be 0
        else 
        dp[i][j]=INF;//if no connection distance will be infinity
    }
    cout<<"Store the Graph Info";
    for(int i=0;i<m;i++)//info is stored on he basis of no. of edges.. 
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        dp[x][y]=wt;
    }
    for(int k=1;k<=n;k++)//to implement principle of Dynamic Programming..
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);//main implementation line of Algo..
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[i][j]==INF)
                cout<<"I"<<" ";
            else
                cout<<dp[i][j]<<" ";
        }
        cout<<endl;    
    }
    return 0;
}