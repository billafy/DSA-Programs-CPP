#include <bits/stdc++.h>

using namespace std;

void maxSlider(int n,int m,queue<int> Q)
{
    queue<int> window;
    multiset<int,greater<int>> MS;
    while(!Q.empty())
    {
        while(window.size()!=m)
        {
            int x = Q.front();
            MS.insert(x);
            window.push(x);
            Q.pop();
        }
        cout << *(MS.begin()) << " ";
        int y = window.front();
        MS.erase(MS.find(y));
        window.pop();
    }
}

int main()
{
    int n,m; // n for the number of elements, m for the window size
    cin >> n;
    queue<int> Q;
    for(int i=0;i<n;i++)
    {
        int v;
        cin >> v;
        Q.push(v);
    }
    cin >> m;
    maxSlider(n,m,Q);
}
