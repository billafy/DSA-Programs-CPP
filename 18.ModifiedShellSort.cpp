#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void modifiedShellSort(int a[],int n)
{
    for(int gap=n/2;gap>0;gap=gap/2)
    {
        for(int i=0;i<n;i++)
        {
            if(i+gap<n)
            {
                if(a[i]>a[i+gap])
                {
                    swap(a[i],a[i+gap]);
                }
            }
            if(i-gap>=0)
            {
                if(a[i-gap]>a[i])
                {
                    swap(a[i],a[i-gap]);
                }
            }
        }
    }
}

int main()
{
    cout << "Modified Shell Sort"<<endl;
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
    cout << "\nModified Shell Sorted Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout << ""<<a[i]<<" ";
    }
    cout <<endl;

}
