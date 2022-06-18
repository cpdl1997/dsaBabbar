#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int doUnion(int a[], int n, int b[], int m)  {
        sort(a, a+n); //O(nlogn) TC
        cout<<"Array A:"<<endl;
        for(int t=0; t<n; t++)
            cout<<a[t]<<" ";
        cout<<endl;
        sort(b, b+m); //O(mlogm) TC
        cout<<"Array B:"<<endl;
        for(int t=0; t<m; t++)
            cout<<b[t]<<" ";
        cout<<endl;
        //int* p=&n;
        //int* q=&m;
        removeDuplicates(a, &n);
        cout<<"Array A after duplicates removed and n=:"<<n<<endl;
        for(int t=0; t<n; t++)
            cout<<a[t]<<" ";
        cout<<endl;
        removeDuplicates(b, &m);
        cout<<"Array B after duplicates removedand m=:"<<m<<endl;
        for(int t=0; t<m; t++)
            cout<<b[t]<<" ";
        cout<<endl;
        
        int i=0, j=0, k=0;
        int c[m+n]; //O(m+n) SC
        //Following sequence of loops takes O(m+n) time for traversing
        while(i<n && j<m)
        {
            /*cout<<"a[i]="<<a[i]<<" for i="<<i<<endl;
            cout<<"b[j]="<<b[j]<<" for j="<<j<<endl;
            cout<<"c[k]="<<c[k]<<" for j="<<k<<endl;*/
            if(a[i]<b[j])
                 c[k++]=a[i++];
            else if(a[i]>b[j])
                 c[k++]=b[j++];
            else
            {
                c[k++]=a[i++];
                j++;
            }
        }
        while(i<n)
            c[k++]=a[i++];
        while(j<m)
            c[k++]=b[j++];
        /*for(int t=0; t<k; t++)
            cout<<c[t]<<" ";
        cout<<endl;*/
        return k;
    }
    void removeDuplicates(int a[], int* n)
    {
        int i=0;
        while(i<*n)
        {
            while(i<(*n)-1 && a[i]==a[i+1])
                swap(a[i++], a[--(*n)]);
            i++;
        }
    }
};

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}