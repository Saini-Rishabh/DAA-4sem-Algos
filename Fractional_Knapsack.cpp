#include<bits/stdc++.h>
using namespace std;

 struct Item{
    int value;
    int weight;
};
 bool comp(Item a,Item b)
    {
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        return r1>r2;
        
    }
int main()
{
    int n,W;
    cout<<"Enter The Number Of Items:";
    cin>>n;
    cout<<"Enter The Weight of Knapsack:";
    cin>>W;

    Item arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i].value>>arr[i].weight;

    sort(arr,arr+n,comp);
    int curWeight=0;
    double finalValue=0.0;
    for(int i=0;i<n;i++)
    {
        if(curWeight+arr[i].weight<=W)
        {
            curWeight+=arr[i].weight;
            finalValue+=arr[i].value;
        }
        else
        {
            int remain=W-curWeight;
            finalValue+=(arr[i].value / (double)arr[i].weight)*(double)remain;
            break;
        }
    }
    cout<<"Final Value in Knapsack:"<<finalValue;
    return 0;
}
