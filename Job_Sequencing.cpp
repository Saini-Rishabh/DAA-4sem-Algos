#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.first;
}
int main()
{
    vector<pair<int,int>>job;
    int n,profit,deadline;
    cout<<"Please Enter The Number of Jobs";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>profit>>deadline;
        job.push_back(make_pair(profit,deadline));
    }
    sort(job.begin(),job.end(),compare);//reverse sorted..
    int maxEndTime=0;
    for(int i=0;i<n;i++)
    {
        if(job[i].second>maxEndTime)
        maxEndTime=job[i].second;
    }
    int fill[maxEndTime];
    int count=0,maxProfit=0;
    for(int i=0;i<maxEndTime;i++)
        fill[i]=-1;
    for(int i=0;i<n;i++)
    {
        int j=job[i].second-1;
        while(j>=0 && fill[j]!=-1)//finds time for job
            j--;
        
        if(j>=0 && fill[j]==-1)
        {
            fill[j]=i;
            count++;   
            maxProfit+=job[i].first;
        }
    }
    cout<<"No .of Job:"<<count<<endl;
    cout<<"Maximum Profit:"<<maxProfit;

    return 0;
}