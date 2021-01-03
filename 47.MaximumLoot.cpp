#include<bits/stdc++.h>

using namespace std;

bool valuePerKg(pair<double,double> P1,pair<double,double> P2)
{
    return (double)P1.first/P1.second > (double)P2.first/P2.second ? 1 : 0;
}

void knapsack(vector<pair<double,double>> valWt,double capacity)
{
    double cur_wt = 0;
    double cur_value = 0;
    for(int i=0;i<valWt.size();i++)
    {
        if(cur_wt+valWt[i].second <= capacity)
        {
            cur_wt += valWt[i].second;
            cur_value += valWt[i].first;
        }
        else
        {
            cur_value += (valWt[i].first*(capacity-cur_wt))/valWt[i].second;
            break;
        }
    }
    cout << fixed << setprecision(4) << cur_value << endl;
}

int main()
{
    int n;
    double capacity,v,w;
    cin >> n;
    cin >> capacity;
    vector<pair<double,double>> valWt;
    for(int i=0;i<n;i++)
    {
        cin >> v >> w;
        valWt.push_back(make_pair(v,w));
    }
    sort(valWt.begin(),valWt.end(),valuePerKg);
    knapsack(valWt,capacity);
}
