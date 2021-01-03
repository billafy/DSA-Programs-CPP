#include<bits/stdc++.h>

using namespace std;

int knapsack(vector<int> val,vector<int> wt,int W,int n)
{
    int DP[n+1][W+1];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=W;++j)
        {
            if(i==0 || j==0)
            {
                DP[i][j] = 0;
            }
            else if(wt[i-1]<=j)
            {
                DP[i][j] = max(val[i-1]+DP[i-1][j-wt[i-1]],DP[i-1][j]);
            }
            else
            {
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    return DP[n][W];
}

int main()
{
    int n,W;
    cin >> n >> W;
    vector<int> val(n),wt(n);
    for(int i=0;i<n;++i)
        cin >> wt[i] >> val[i];
    cout << knapsack(val,wt,W,n) << endl;
}
