#include<bits/stdc++.h>
using namespace std;

vector<int>lookup(10,-1);
//top down approach..
int fib_td(int n)
{
    if(lookup[n]==-1)
    {
        if(n<=1)
            lookup[n]=n;
        else
            lookup[n]=fib_td(n-1)+fib_td(n-2);
    }
    return lookup[n];
}
//bottomup approach...
int fib_bu(int n)
{
    int f[n+1];
    int i;
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    return f[n];
}
int main()
{
    int n,ans;
    cout<<"Please Enter the Number:";
    cin>>n;
    //ans=fib_td(n);
   ans=fib_bu(n);
    cout<<"Answer Is:"<<ans;

}