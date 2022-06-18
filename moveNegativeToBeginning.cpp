#include<iostream>

using namespace std;

class moveNegativeToBeginning{
    public:
    int moveNegToBeg(int a[], int n)
    {
        int i=0, j=n-1;
        while(i<j)
        {
            while(a[i]<0) 
                i++;
            while(a[j]>0)
                j--;
            //cout<<"Swap a[i]="<<a[i]<<" at index i="<<i<<" with a[j]="<<a[j]<<" at index j="<<j<<" \n";
            if(i<j)
                swap(a[i], a[j]);
            
            /*for(int i=0; i<n; i++)
                cout<<a[i]<<' ';
            cout<<endl;*/
        }
        
        /*if(a[n/2]<0)
        swap(a[n/2], a[n/2-1]);*/
    }
};

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    moveNegativeToBeginning obj;
    obj.moveNegToBeg(a, n);
    cout<<"Modified array is: "<<endl;
    for(int i=0; i<n; i++)
        cout<<a[i]<<' ';
    cout<<endl;
}