#include<bits/stdc++.h>

using namespace std;

int helper(vector<int>& A,int i,int j,vector<vector<int>>& DP)
{
    if(i>=j)
        return 0;
    if(DP[i][j]!=-1)
        return DP[i][j];
    int minV = INT_MAX;
    for(int k=i;k<j;++k)
    {
        int temp = helper(A,i,k,DP) + helper(A,k+1,j,DP) + (A[i-1]*A[k]*A[j]);
        minV = min(minV,temp);
    }
    DP[i][j] = minV;
    return minV;
}

int matrixChainMultiplication(vector<int>& A)
{
    vector<vector<int>> DP(A.size()+1,vector<int>(A.size()+1,-1));
    return helper(A,1,A.size()-1,DP);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0;i<n;++i)
        cin >> A[i];
    cout << matrixChainMultiplication(A) << endl;
}
