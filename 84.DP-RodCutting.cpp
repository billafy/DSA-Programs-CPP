#include <bits/stdc++.h>

using namespace std;

int maxRodPrice(int N,vector<int> price,int length,vector<vector<int>>& DP)
{
    if(length==0 || N==0)
    {
        DP[N][length]=0;
        return 0;
    }
    if(DP[N][length]!=0)
        return DP[N][length];
    if(length<=N)
    {
        DP[N][length] = max(price[length]+maxRodPrice(N-length,price,length,DP),maxRodPrice(N,price,length-1,DP));
        return DP[N][length];
    }
    else
    {
        DP[N][length] = maxRodPrice(N,price,length-1,DP);
        return DP[N][length];
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> price(N+1);
    price[0] = 0;
    vector<vector<int>> DP(N+1);
    for(int i=0;i<=N;++i)
    {
        DP[i].resize(N+1);
    }
    for(int i=1;i<=N;++i)
        cin >> price[i];
    cout << maxRodPrice(N,price,N,DP);
}
