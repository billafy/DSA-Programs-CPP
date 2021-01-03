#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void sort(int a[],int l,int m,int r);
void print(int a[],int n);
int merge(int a[], int l, int r)
{
   while(l<r)
   {
     int m = (l+r)/2;

     merge(a,l,m);  // recursion
     merge(a,m+1,r); // keeps splitting the array into two parts until only one array element is left

     sort(a,l,m,r); // function call for the sorting
   }
   return a[];
}

void sort(int a[],int l,int m,int r)
{
    int i=l,j=m+1,k=l;
    int temp[100];
    while(i<=m && j<=r)
    {
        if(a[i]>a[j])
        {
            temp[k] = a[j];
            j++;
            k++;
        }
        else
        {
            temp[k] = a[i];
            i++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=r)
    {
        temp[k]=a[j];
        k++;
        j++;
    }
    for(int o=0;o<r;o++)
    {
        a[o] = temp[o];
    }
}

void print(int a[],int n)
{
    cout << "\nSorted Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout << ""<<a[i]<<" ";
    }
    cout << "\n";
}

int main()
{
   cout << "Merge Sort"<<endl;
   int n,l,r;
   int* a;
   cout << "\nEnter size of the array : ";
   cin >> n;
   l = 0;
   r = n-1;
   a = new int(n);
   cout << "\nEnter the elements of the array : "<<endl;
   for(int i=0;i<n;i++)
   {
       cin >> a[i];
   }
   merge(a,l,r);
   print(a,n);
}
