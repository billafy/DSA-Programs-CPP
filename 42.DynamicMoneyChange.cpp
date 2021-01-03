#include<bits/stdc++.h>

using namespace std;

int moneyChange(int money,vector<int> coins)
{
    vector<int> minCoins(money+1);
    minCoins[0] = 0;
    for(int m=1;m<=money;m++)
    {
        minCoins[m] = 10000;
        for(int i=1;i<4;i++)
        {
            if(m >= coins[i])
            {
                int numCoins = minCoins[m-coins[i]] + 1;
                if(numCoins < minCoins[m])
                {
                    minCoins[m] = numCoins;
                }
            }
        }
    }
    return minCoins[money];
}

int main()
{
    int money;
    cin >> money;
    vector<int> coins = {0,1,3,4};
    cout << moneyChange(money,coins) <<endl;
}
