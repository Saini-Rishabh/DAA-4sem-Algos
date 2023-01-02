#include<bits/stdc++.h>
using namespace std;

int LCS(string X,string Y,int m,int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    for(int j=0;j<=n;j++)
    {
        if(i==0 || j==0)
            dp[i][j]=0;
        else if(X[i-1]==Y[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
        else 
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[m][n];
}
int main()
{
    string X,Y;
    cout<<"Enter The First String:";
    cin>>X;
    cout<<"Enter The Second String:";
    cin>>Y;
    int m=X.size();
    int n=Y.size();
    int ans=LCS(X,Y,m,n);
    cout<<"Longest Common Subsequence is:"<<ans;
    return 0;
}