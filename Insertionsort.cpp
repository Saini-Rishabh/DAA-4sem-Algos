#include<iostream>
#include<vector>
using namespace std;

void Insertionsort(int A[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=A[i];
        j=i-1;
        while(j>=0 && A[j]>temp)
        {
            A[j+1]=A[j];
            j--;//take a jump from loop if the temp value is more than the largest element of sorted array...
        }
        A[j+1]=temp;
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
    Insertionsort(A,n);
    cout<<"Array After Insertion Sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<"\n";
    }
    return 0;

}
