#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void shellSort(int a[],int n)
{
    for(int gap=n/2;gap>0;gap=gap/2)
    {
        for(int i=gap;i<n;i++)
        {
            int temp = a[i];
            int j;
            for(j=i; j >= gap && a[j-gap] > temp;j-=gap)
            {
                a[j]=a[j-gap];
            }
            a[j]=temp;
        }
    }
}

int main()
{
    cout << "Shell Sort"<<endl;
    int n;
    int* a;
    cout << "\nEnter the size of array : ";
    cin >> n;
    a = new int(n);
    cout << "\nEnter the array elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    shellSort(a,n);
    cout << "\nShell Sorted Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout << ""<<a[i]<<" ";
    }
    cout <<endl;

}
