#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

int partition(int a[],int s, int e)
{
   int pivot = e;
   int pIndex = s;
   for(int i=s;i<=e-1;i++)
   {
       if(a[i]<=a[pivot])
       {
           swap(a[pIndex],a[i]);
           pIndex++;
       }
   }
   swap(a[pivot],a[pIndex]);
   return pIndex;
}

void quickSort(int a[],int s,int e)
{
    if(s<e)
    {
      int p = partition(a,s,e);
      quickSort(a,s,p-1);
      quickSort(a,p+1,e);
    }
}

int main()
{
    cout << "Quick Sort"<<endl;
    int n,s=0,e;
    int* a;
    cout << "\nEnter the size of array : ";
    cin >> n;
    a = new int(n);
    e = n-1;
    cout << "\nEnter the array elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    quickSort(a,s,e);
    cout << "\nQuick Sorted Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout << ""<<a[i]<<" ";
    }
    cout <<endl;
}
