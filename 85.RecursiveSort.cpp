#include<bits/stdc++.h>

using namespace std;

void sortArray(vector<int>& A,int N,int i,int c)
{
    if(i==0 || c==N)
        return;
    if(A[i]<A[i-1])
        swap(A[i],A[i-1]);
    sortArray(A,N,i-1,c);
    sortArray(A,N,N-1,++c);
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;++i)
        cin >> A[i];
    sortArray(A,N,N-1,1);
    for(int i=0;i<N;++i)
        cout << A[i] << " ";
}
