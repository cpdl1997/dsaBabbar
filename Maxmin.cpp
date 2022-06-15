#include<iostream>

using namespace std;

pair<int,int> maxMin(int a[], int low, int high, pair<int, int> &res)
{
    if(high-low==1)
    {
        res.first=a[low];
        res.second=a[low];
        return res;
    }
    if(high-low==2)
    {
        if(a[low]<=a[high-1])
        {
            res.first=a[low];
            res.second=a[high-1];
        }
        else
        {
            res.first=a[high-1];
            res.second=a[low];
        }
        return res;
    }
    int mid=(low+high)/2;
    pair<int,int> leftRes=maxMin(a, low, mid, res);
    pair<int,int> rightRes=maxMin(a, mid, high, res);
    if(res.first>leftRes.first)
    res.first=leftRes.first;
    if(res.first>rightRes.first)
    res.first=leftRes.first;
    if(res.second<leftRes.second)
    res.second=leftRes.second;
    if(res.second>rightRes.second)
    res.second=leftRes.second;
    return res;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0 ;i<n; i++)
        cin>>a[i];
    pair<int, int> res; // res.first = min, res.second=max
    maxMin(a, 0, n, res);
    cout<<"Min ="<<res.first<<endl;
    cout<<"Max ="<<res.second<<endl;
}