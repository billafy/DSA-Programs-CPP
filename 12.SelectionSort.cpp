#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void selectionSort(int a[], int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            swap(a[i],a[min]);
        }
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
   cout << "Selection Sort"<<endl;
   int n;
   int* a;
   cout << "\nEnter size of the array : ";
   cin >> n;
   a = new int(n);
   cout << "\nEnter the elements of the array : "<<endl;
   for(int i=0;i<n;i++)
   {
       cin >> a[i];
   }
   selectionSort(a,n);
   print(a,n);
}
