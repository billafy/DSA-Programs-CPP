#include<bits/stdc++.h>

using namespace std;

void insertVal(stack<int>& S,int top)
{
    if(S.empty())
    {
        S.push(top);
        return;
    }
    int temp = S.top();
    if(temp>top)
    {
        S.pop();
        insertVal(S,top);
        S.push(temp);
    }
    else
    {
        S.push(top);
        return;
    }
}

void sortStack(stack<int>& S)
{
    if(S.empty())
        return;
    int top = S.top();
    S.pop();
    sortStack(S);
    insertVal(S,top);
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
    stack<int> D = S;
    cout << "\nUnsorted Stack : ";
    while(!D.empty())
    {
        cout << D.top() << " ";
        D.pop();
    }
    sortStack(S);
    cout << "\n\nSorted Stack : ";
    while(!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
    cout << endl;
}
