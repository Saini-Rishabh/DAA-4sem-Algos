#include<iostream>
#include<vector>
using namespace std;

void Bubblesort(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        int f=0;
        int j;
        for(j=0;j<n-(i+1);j++)
        {
            if(A[j]>A[j+1])
            {
               swap(A[j],A[j+1]);
               f++;
            }
        }
       if(f==0)  //flag optimize the bubble sort by flaging the step where swapping stops and array maintains a sorted position..
        break;
    }
}
void SelectionSort(int A[],int n)
{
    int min_ind;
    for(i=0;i<n;i++)
    {
         min_ind=i;        //Here Minimum index is taken as a pointer to carry out swapping operation
        for(j=i+1;j<n;j++)  //Selection sort works on marking the indices..
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
    Bubblesort(A,n);
    cout<<"Array After Buuble Sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<"\n";
    }
    return 0;

}
