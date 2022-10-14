
#include <iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>
using namespace std;

void print(int a[],int n)
{
    cout << "\nSorted Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout << ""<<a[i]<<" ";
    }
    cout << "\n";
}
//my soln
   void swap(int a[], int f, int s) {
        int temp = a[f];
        a[f] = a[s];
        a[s] = temp;
    }
    // To get the maximum value's index at every iteration
    int maxindex(int a[], int start, int end) {
        int max = start;
        for (int i = start; i <= end; i++) {
            if (a[max] < a[i])
                max = i;
        }
        return max;
    }
   void selectionSort(int a[],int n) {                                              // T--> O(N^2)
        for (int i = 0; i < n; i++) {
            int last = n - i - 1; // because of 0 indexing.
            int getmaxInd = maxindex(a, 0, last);  
            swap(a, getmaxInd, last);
        }
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