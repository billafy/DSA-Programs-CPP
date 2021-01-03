#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;



int binarySearch(int a[],int left,int right)
{
    int mid,x,temp=0;
    cout << "\nEnter element you want to search : ";
    cin >> x;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(a[mid]==x)
        {
            cout << "\nThe position of "<<x<<" is "<<mid<<endl;
            temp++;
            break;
        }
        else if(a[mid]<x)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
    if(temp==0)
    {
        cout << "\nElement does not exist"<<endl;
    }
}

int main()
{
   cout << "Binary Search"<<endl;
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
   bubbleSort(a,n,l,r);
   binarySearch(a,l,r);
}

