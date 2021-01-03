#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>
#include<thread>

#define MAX 1000

using namespace std;

bool has[MAX+1][2]; // initialize the boolean 2D array globally, it will take up 0(false) value as default

void search(int x)
{
    if(x>0)
    {
        if(has[x][0]==1) // if x is positive and hash[a[i]][0] = 1, the element is present
        {
            cout << "\nPresent"<<endl;
        }
        else
        {
            cout << "\nNot Present"<<endl;
        }
    }
    else
    {
       x = abs(x); // convert x to its absolute value as it is negative
       if(has[x][1]==1) // if hash[a[i]][1] = 1, the element is present
       {
           cout << "\nPresent"<<endl;
       }
       else
       {
           cout << "\nNot Present"<<endl;
       }
    }
}

void insert(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]>0) // if element is positive assign hash[a[i]][0] = 1
        {
            has[a[i]][0] = 1;
        }
        else // if element is negative or 0, convert a[i] to its absolute value and assign hash[a[i]][1] = 1
        {
            has[abs(a[i])][1] = 1;
        }
    }
}

int main()
{
    cout << "Hashing\n"<<endl;
    int* a = new int();
    int n;
    cout << "\nHow many elements to add in the hashing table : ";
    cin >> n;
    cout << "\nEnter elements : \n"; // elements will be inputted in an array and later inserted in the 2D arrays
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    insert(a,n); // insert in the hash table
    int x;
    cout << "Which element to search : ";
    cin >> x;
    search(x); // search in the hash table
}
