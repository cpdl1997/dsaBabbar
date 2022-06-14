#include<iostream>

using namespace std;

void revStArr(int a[], int n)
{
    int lim=n/2;
    if(n%2==1)
        for(int i=0; i<lim; i++)
            swap(a[i], a[n-i-1]);
    else
        for(int i=0; i<lim-1; i++)
            swap(a[i], a[n-i-1]);
}
void revRecArr(int a[], int i, int n)
{
    if((n%2==1 && i==n/2)||(n%2==0 && i==n/2-1))
        return;
    swap(a[i], a[n-i-1]);
    revRecArr(a, i+1, n);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    revStArr(a, n);
    cout<<"Reversed array revStArray"<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    revRecArr(a,0, n);
    cout<<"Reversed reversed array revRecArray"<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

