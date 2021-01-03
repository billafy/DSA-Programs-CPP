#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void countingSort(int a[],int n)
{
    int range = 10,i;
    int* output;
    int* count;
    output = new int(n);
    count = new int(range);
    for(i=0;i<range;i++)
    {
        count[i]=0;
    }
    for(i=0;i<n;i++)
    {
        ++count[a[i]];
    }
    for(i=1;i<range;i++)
    {
        count[i] = count[i]+count[i-1];
    }
    for(i=0;i<n;i++)
    {
        output[--count[a[i]]]=a[i];
    }
    for(i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}

int main()
{
    cout << "Counting Sort"<<endl;
    int n;
    int* a;
    cout<<"\nRange : 0 to 9";
    cout << "\nEnter the size of array : ";
    cin >> n;
    a = new int(n);
    cout << "\nEnter the array elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    countingSort(a,n);
    cout << "\nCount Sorted Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout << ""<<a[i]<<" ";
    }
    cout <<endl;
}
