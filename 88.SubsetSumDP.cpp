#include<bits/stdc++.h>

using namespace std;

bool subsetSumC(vector<int> nums,int target,int N)
{
    bool DP[N+1][target+1];
    for(int i=0;i<=N;++i)
        DP[i][0] = true;
    for(int i=1;i<=target;++i)
        DP[0][i] = false;
    for(int j=1;j<=target;++j)
    {
        for(int i=1;i<=N;++i)
        {
            if(nums[i-1]<=j)
            {
                DP[i][j] = DP[i-1][j-nums[i-1]] || DP[i-1][j];
            }
            else
            {
                DP[i][j] = DP[i-1][j];
            }
        }
    }
    for(int i=0;i<=N;++i)
    {
        for(int j=0;j<=target;++j)
            cout << DP[i][j] << " ";
        cout << endl;
    }
    return DP[N][target];
}

int main()
{
    int N,target;
    cin >> N >> target;
    vector<int> nums(N);
    for(int i=0;i<N;++i)
        cin >> nums[i];
    cout << subsetSumC(nums,target,N);
}
