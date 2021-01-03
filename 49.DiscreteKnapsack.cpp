#include<bits/stdc++.h>

using namespace std;

int maxGold(int W,int n,vector<int> gold)
{
    int value[W+1][n+1];
    for(int i=0;i<=W;i++)
    {
        value[i][0] = 0;
    }
    for(int i=0;i<=n;i++)
    {
        value[0][i] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=W;w++)
        {
            int previous = value[w][i-1];
            int current = gold[i]+value[w-gold[i]][i-1];
            if(current > w)
            {
                value[w][i] = previous;
            }
            else
            {
                value[w][i] = max(previous,current);
            }
        }
    }
    return value[W][n];
}

int main()
{
    int W,n;
    cin >> W >> n;
    vector<int> gold(n+1);
    gold[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> gold[i];
    }
    cout << maxGold(W,n,gold) << endl;
}
