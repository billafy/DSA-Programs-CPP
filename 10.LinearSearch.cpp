#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void linearsearch(int a[],int x, int n)
{
    int temp = 5;
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            cout << "\nPosition : "<<i<<endl;
            temp++;
            break;
        }
    }
    if(temp==5)
    {
        cout << "\nElement doesn't exist"<<endl;
    }
}

int main()
{
    cout << "Linear Search"<<endl;
    int n,x;
    int* a;
    cout << "\nEnter size of the array : ";
    cin >> n;
    a = new int(n);
    cout << "\nEnter elements of the array : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cout << "\nEnter the element of which the position you want to search : ";
    cin >> x;
    linearsearch(a,x,n);
}
