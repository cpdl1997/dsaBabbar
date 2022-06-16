#include<iostream>

using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallestM1(int arr[], int l, int r, int k) { //Method 1: Use bubble sort k times and shift smallest element to right
        int kmin=arr[l];
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<r-i; j++)
            {
                if(arr[j]<arr[j+1])
                    swap(arr[j], arr[j+1]);
            }
        }
        return arr[r-k+1];
    } // TC: O(kn) -> WC TC is O(n^2)

    int kthSmallestM2(int arr[], int l, int r, int k) { //Method 2: Find smallest k times
        for(int i=l; i<k; i++)
        {
            int min=l;
            for(int j=0; j<=r-i; j++)
            {
                if(arr[j]<arr[min])
                    min=j;
            }
            swap(arr[i], arr[r-i]);
        }
        return arr[r-k+1];
    } // TC: O(kn) -> WC TC is O(n^2)

    int partition(int arr[], int l, int r, int pivot)
    {
        int n=r-l;
        int i=l, j=r+1;
        while(i<j)
        {
            do{
                i++;
            }while(arr[i]<arr[pivot]);
            do{
                j--;
            }while(arr[j]>arr[pivot]);
            swap(arr[i], arr[j]);
        }
        swap(arr[pivot], arr[j]);
        return j;
    }
    int kthSmallestM3(int arr[], int l, int r, int k) { //Method 3: Using partition method
        int pivot=l, ele=arr[l];
        int x=partition(arr, l, r, pivot);
        if(k==x)
            return ele;
        if(k<x)
            return kthSmallestM3(arr, l, x-1, k);
        return kthSmallestM3(arr, x+1, r, k);
    } // TC: O(kn) -> WC TC is O(n^2)

};
int main()
{
    Solution obj;
    int n, k, kthsmallest;
    cin>>n;
    int a[n];
    for(int i=0 ;i<n; i++)
        cin>>a[i];
    cin>>k;
    kthsmallest=obj.kthSmallestM3(a, 0, n, k);
    cout<<"Kth smallest = "<<kthsmallest<<endl;
}