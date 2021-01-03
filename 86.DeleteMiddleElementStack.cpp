#include<bits/stdc++.h>

using namespace std;

void deleteMid(stack<int>& S,int n,int csize)
{
    if(csize==n/2)
    {
        S.pop();
        return;
    }
    int temp = S.top();
    S.pop();
    deleteMid(S,n,csize+1);
    S.push(temp);
}

int main()
{
    int n,v;
    cin >> n;
    stack<int> S;
    for(int i=0;i<n;++i)
    {
        cin >> v;
        S.push(v);
    }
    deleteMid(S,n,0);
    while(!S.empty())
    {
        cout << S.top() << ' ';
        S.pop();
    }
}
