#include<iostream>

using namespace std;

void sort012(int a[], int n)
{
    int count0=0, count1=0, i=0;
    for(i=0; i<n; i++)
    {
        if(a[i]==0)
        count0++;
        else if(a[i]==1)
        count1++;
    }
    i=0;
    while(count0-->0)
        a[i++]=0;
    while(count1-->0)
        a[i++]=1;
    while(i<n)
        a[i++]=2;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ;i<n; i++)
        cin>>a[i];
    sort012(a, n);
    cout<<"Sorted array: "<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}