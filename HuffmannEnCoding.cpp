#include<bits/stdc++.h>
using namespace std;

struct minHeapElement
{
    char c;
    int frq;
    string s;
    minHeapElement *left,*right;
};
void Heapify(minHeapElement* arr[],int i,int n)
{
    int c1=2*i+1,c2=2*i+2;
    int minElement=i;
    if(c1<n && arr[c1]->frq < arr[minElement]->frq)
        minElement=c1;
    else if(c2<n && arr[c2]->frq <arr[minElement]->frq)
        minElement=c2;
    
    if(minElement!=i)
    {
        swap(arr[i],arr[minElement]);
        Heapify(arr,minElement,n);
    }
}
void MinHeapify(minHeapElement* arr[],int n)
{
    for(int i=n/2;i>=0;i--)
        Heapify(arr,i,n);
}
minHeapElement* extract_min(minHeapElement* arr[],int &n)
{
   swap(arr[0],arr[n-1]);
   minHeapElement* ret=arr[n-1];
   n--;
   Heapify(arr,0,n);
   return ret;
}
void perlocate_up(minHeapElement* arr[],int i,int n)
{
    int parent=(i-1)/2;
    if(i==0 ||arr[parent]->frq >arr[i]->frq)
    return ;
    swap(arr[i],arr[parent]);
    perlocate_up(arr,parent,n);
}
void insert(minHeapElement* arr[],int &n,minHeapElement* he3)
{
    arr[n]=he3;
    n++;
    perlocate_up(arr,n-1,n);
}
void print(minHeapElement* root,string str)
{
    if(root->c!='$')
    {
        cout<<root->c << " "<<str<<endl;
        return ;
    }
    print(root->left,str+'0');
    print(root->right,str+'1');
}
int main()
{
    int n;
    cout<<"Please ENter the Number of Elements:";
    cin>>n;
    minHeapElement* arr[n];
    char c;
    int freq;
    for(int i=0;i<n;i++)
    {
        cin>>c>>freq;
        arr[i]=new minHeapElement();
        arr[i]->c=c;
        arr[i]->frq=freq;
        arr[i]->left=arr[i]->right=NULL;
    }
    MinHeapify(arr,n);
    while(n!=1)
    {
        minHeapElement* he1=extract_min(arr,n),*he2=extract_min(arr,n),*he3;
        he3=new minHeapElement();
        he3->c='$';
        he3->frq=he1->frq+he2->frq;
        he3->left=he1;
        he3->right=he2;
        insert(arr,n,he3);
    }
    print(arr[0]," ");
    return 0;
}
