#include<iostream>
#include<vector>
using namespace std;

int partition(int A[],int l,int r)
{
    int x=(rand()%(r-l+1))+l;  //This two line of code makes it the code of Randomized quick
    swap(A[x],A[r]);
    int pivot=A[r]; //in this sorting last element is chosen as pivot but quicksort can have any element as its pivot..
    int i=(l-1);
    for(int j=l;j<r;j++)
    {
        if(A[j]<pivot)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return(i+1);
}
void quicksort(int A[],int l,int r)
{
    if(l<r)
    {
        int p=partition(A,l,r);
        quicksort(A,l,p-1);
        quicksort(A,p+1,r);
    }
}
int main()
{
    int n;
    cout<<"PLease enter Number of Elements in the Array"<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter the Elements"<<endl;
    for(int i=0;i<n;i++)
        cin>>A[i];
    quicksort(A,0,n-1);
    cout<<"Elements after sorting is:";
    for(int i=0;i<n;i++)
        cout<<A[i]<<endl;
    return 0;
}

