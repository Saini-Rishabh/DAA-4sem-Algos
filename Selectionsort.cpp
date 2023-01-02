#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(int A[],int n)
{
    int min_ind;
    for(int i=0;i<n;i++)
    {
        min_ind=i;        //Here Minimum index is taken as a pointer to carry out swapping operation
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min_ind])
            min_ind=j;
        }
        swap(A[min_ind],A[i]);
    }
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
    SelectionSort(A,n);
    cout<<"Array After Selection Sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<"\n";
    }
    return 0;

}
