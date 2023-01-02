#include<bits/stdc++.h>
using namespace std;
//dynamic progrraming assimilates all the posssible cases and make a expanded decision tree
//top down approach 
int knapsack(int wt[],int val[],int n,int k)
{
    if(n==0 || k==0)
        return 0;
    if(wt[n-1]>k)
        return knapsack(wt,val,n-1,k);
    else 
    {
        return max( knapsack(wt,val,n-1,k),val[n-1]+ knapsack(wt,val,n-1,k-wt[n-1]));
    }
}
//bottom up approach
int knap_sack(int wt[],int val[],int n,int k)
{
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++)
    for(int j=0;j<=k;j++)
    {
        if(i==0|| j==0)
            dp[i][j]=0;
        else if(wt[i-1]>j)
            dp[i][j]=dp[i-1][j];
        else 
            dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
    }
    return dp[n][k];
}

int main()
{
    int n,k;
    cout<<"Enter the Number Of Items:";
    cin>>n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
        cin>>val[i];
    }
    cout<<"Enter the Limit of Knapsack:";
    cin>>k;
    int ans;
    //ans=knapsack(wt,val,n,k);
    ans=knap_sack(wt,val,n,k);
    cout<<"Maximum Profit is:"<<ans;
    return 0;
}