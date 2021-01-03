#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void sort(int a[], int l, int m, int r,int n)
{
    int i=l,j=m+1,k=l;
    int* temp;
    temp = new int(n);
    while(i<=m && j<=r)
    {
        if(a[j]>=a[i])
        {
            temp[k] = a[i];
            i++, k++;
        }
        else
        {
            temp[k] = a[j];
            j++, k++;
        }
    }
    while(i<=m)
    {
        temp[k] = a[i];
        i++, k++;
    }
    while(j<=r)
    {
        temp[k] = a[j];
        j++, k++;
    }
    for(int o=l;o<=r;o++)
    {
       a[o] = temp[o];
    }
}

void merge(int a[], int l, int r,int n)
{
    if(l<r)
    {
        int m = (l+r)/2;
        merge(a,l,m,n);
        merge(a,m+1,r,n);
        sort(a,l,m,r,n);
    }
}

int main()
{
    cout << "Merge Sort"<<endl;
    int* a;
    int n,l,r;
    cout << "\nEnter array size : ";
    cin >> n;
    l = 0;
    r = n-1;
    a = new int(n);
    cout << "\nEnter array elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    merge(a,l,r,n);
    cout<<"\nSorted Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout << ""<<a[i]<<" ";
    }
}
