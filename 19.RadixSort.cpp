#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void countingSort(int a[], int n,int div)
{
    int* output;
    output = new int(n);
    int range=10;
    int* count;
    count = new int(range);
    for(int i=0;i<range;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        count[(a[i]/div)%10]++;
    }
    for(int i=1;i<range;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        output[count[(a[i]/div)%10]-1]=a[i];
    }
    for(int i=0;i<n;i++)
    {
        a[i] = output[i];
    }
}

int getMax(int a[], int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        }
    }
    return max;
}

void radixSort(int a[],int n)
{
    int m=getMax(a,n);
    for(int div=1;(m/div)>0;div*=10)
    {
        countingSort(a,n,div);
    }
}

int main()
{
    cout << "Radix Sort"<<endl;
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
    radixSort(a,n);
    cout << "\nRadix Sorted Array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cout << ""<<a[i]<<" ";
    }
    cout <<endl;

}
