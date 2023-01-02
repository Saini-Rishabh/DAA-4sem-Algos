#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void CountSort(int A[],int C[],int n)
{
    int m;
    m=*max_element(A,A+n)+1;// find  the  Maximum element of array..
    int B[m];
    for(int i=0;i<m;i++)
        B[i]=0;
    for(int i=0;i<n;i++)
        B[A[i]]++;
    for(int i=1;i<m;i++)
        B[i]=B[i]+B[i-1];
    for(int j=n-1;j>=0;j--)
    {
        C[B[A[j]]-1]=A[j];
        B[A[j]]--;
    }
    for(int i=0;i<n;i++)
        A[i]=C[i];
     for(int i=0;i<n;i++)
        cout<<A[i];
}
int main()
{
    int n;
    cout<<"Enter the Number of Elements";
    cin>>n;
    int A[n];
    int B[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    CountSort(A,B,n);
    return 0;
}
