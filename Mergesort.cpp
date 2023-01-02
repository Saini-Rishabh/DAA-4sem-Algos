 #include<iostream>
#include<vector>
using namespace std;

void Merge(int A[],int l,int q,int r)
{
    int n1=(q-l)+1;
    int n2=(r-q);

    int L[n1],R[n2];

    for(int i=0;i<n1;i++)
        L[i]=A[l+i];
    for(int j=0;j<n2;j++)
        R[j]=A[q+1+j];

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        A[k++]=L[i++];
        else
        A[k++]=R[j++];
    }
    while(i<n1)
    A[k++]=L[i++];
    while(j<n2)
    A[k++]=R[j++];
}
void Mergesort(int A[],int l,int r)
{
    if(l<r)
    {
        int q;
        q=(l+(r-l)/2);
        Mergesort(A,l,q);
        Mergesort(A,q+1,r);
        Merge(A,l,q,r);
    }
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
        cout<<A[i]<<endl;
}

int main()
{
    int n;
    cout<<"Please enter the Number of Elements"<<endl;
    cin>>n;
    int A[n];
    cout<<"PLease enter the Elements in array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    Mergesort(A,0,n-1);
    cout<<"Array After Sorting "<<endl;
    printArray(A,n);
    return 0;
}