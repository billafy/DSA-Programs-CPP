#include<bits/stdc++.h>

using namespace std;

void insertStack(stack<int>& S,int top)
{
    if(S.empty())
    {
        S.push(top);
        return;
    }
    int temp = S.top();
    S.pop();
    insertStack(S,top);
    S.push(temp);
}

void reverseStack(stack<int>& S)
{
    if(S.empty())
        return;
    int top = S.top();
    S.pop();
    reverseStack(S);
    insertStack(S,top);
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
    cout << "\nStack : ";
    while(!D.empty())
    {
        cout << D.top() << ' ';
        D.pop();
    }
    cout << endl;
    reverseStack(S);
    cout << "\nReversed Stack : ";
    while(!S.empty())
    {
        cout << S.top() << ' ';
        S.pop();
    }
}
