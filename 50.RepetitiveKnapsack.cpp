#include<bits/stdc++.h>

using namespace std;

int repKnapSack(int W,int n,vector<int> wt_items,vector<int> val_items)
{
    vector<int> maxValue(W+1);
    maxValue[0] = 0;
    for(int w=1;w<=W+1;w++)
    {
        maxValue[w] = 0;
        for(int i=0;i<n;i++)
        {
            if(wt_items[i]<=w)
            {
                int val = maxValue[w-wt_items[i]]+val_items[i];
                if(val > maxValue[w])
                {
                    maxValue[w] = val;
                }
            }
        }
    }
    return maxValue[W];
}

int main()
{
    int W,n;
    cout << "Knapsack capacity : ";
    cin >> W;
    cout << "\nNumber of items : ";
    cin >> n;
    vector<int> wt_items(n);
    vector<int> val_items(n);
    cout << "\nItems - Weight and Value : \n";
    for(int i=0;i<n;i++)
    {
        cin >> wt_items[i] >> val_items[i];
    }
    cout << "\nMaximum value which can be obtained : "<<repKnapSack(W,n,wt_items,val_items)<<endl;
}
