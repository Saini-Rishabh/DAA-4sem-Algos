#include<bits/stdc++.h>
using namespace std;

int matrix_chain_Order(int p[],int n)
{
    int dp[n][n];
    int i,j,k,l,q;
    for(int i=1;i<n;i++)//making whole diagonal 0..
        dp[i][i]=0;
    for(int l=2;l<n;l++)
    for(int i=1;i<n-l+1;i++)
    {
        j=i+l-1;
        dp[i][j]=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            q=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
            if(q<dp[i][j])
            dp[i][j]=q;
        }
    }
    return dp[1][n-1];
}
int main()
{
    int n;
    cout<<"Enter the Number of Matrices:";
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
        cin>>p[i];
    int ans=matrix_chain_Order(p,n);
    cout<<"Minimum No. of Operation in Which Matrix Multiplication Can Be Done Is:"<<ans;
    return 0;
}