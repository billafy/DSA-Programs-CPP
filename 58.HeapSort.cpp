#include<bits/stdc++.h>

using namespace std;

void heapify(int V[],int i,int n)
{
    int maxIndex = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left<n && V[left]>V[maxIndex])
    {
        maxIndex = left;
    }
    if(right<n && V[right]>V[maxIndex])
    {
        maxIndex = right;
    }
    if(i!=maxIndex)
    {
        swap(V[i],V[maxIndex]);
        heapify(V,maxIndex,n);
    }
}

void heapSort(int V[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(V,i,n);
    }
    for(int i=n-1;i>=1;i--)
    {
        swap(V[i],V[0]);
        heapify(V,0,i);
    }
}

void displayV(int V[], int n)
{
    cout << endl;
    for(int i=0;i<n;i++)
    {
        cout << V[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Number of elements : ";
    cin >> n;
    int V[n];
    cout << "\nEnter elements : \n";
    for(int i=0;i<n;i++)
    {
        cin >> V[i];
    }
    heapSort(V,n);
    displayV(V,n);
}

