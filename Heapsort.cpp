#include<bits/stdc++.h>
using namespace std;

void Heapify(int A[],int n,int i)
{
    int c1=2*i+1;
    int c2=2*i+2;
    int maximum=i;
    if(c1<n && A[c1]>A[maximum])
    {
        maximum=c1;
    }
    if(c2<n && A[c2]>A[maximum])
    {
        maximum=c2;
    }
    if(maximum!=i)
    {
        swap(A[i],A[maximum]);
        Heapify(A,n,maximum);
    }
}
void Buildheap(int A[],int n)
{
    for(int i=n/2-1;i>=0;i--)
    Heapify(A,n,i);

    for(int i=n-1;i>=0;i--)
    {
        swap(A[0],A[i]);
        Heapify(A,i,0);
    }
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    cin>>A[i];
    Buildheap(A,n);
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
    return 0;
}