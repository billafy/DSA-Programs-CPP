#include<bits/stdc++.h>

using namespace std;

int mergeSort(int A[],int temp[],int left,int mid,int right)
{
    int i = left,j = mid,k= left,inv=0;
    while(i<=mid-1 && j<=right)
    {
        if(A[i]<=A[j])
        {
            temp[k] = A[i];
            k++,i++;
        }
        else
        {
            temp[k] = A[j];
            k++,j++;
            inv += (mid-i);
        }
    }
    while(i<=mid-1)
    {
        temp[k] = A[i];
        k++,i++;
    }
    while(j<=right)
    {
        temp[k] = A[j];
        k++,j++;
    }
    for(int i=left;i<=right;i++)
    {
        A[i] = temp[i];
    }
    return inv;
}

int Merge(int A[],int temp[],int left,int right)
{
    int mid,inv=0;
    if(right>left)
    {
        mid = (left+right)/2;
        inv += Merge(A,temp,left,mid);
        inv += Merge(A,temp,mid+1,right);
        inv += mergeSort(A,temp,left,mid+1,right);
    }
    return inv;
}

int _Merge(int A[],int n)
{
    int temp[n];
    return Merge(A,temp,0,n-1);
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    int result = _Merge(A,n);
    cout << "\n"<<result<<endl;
}
