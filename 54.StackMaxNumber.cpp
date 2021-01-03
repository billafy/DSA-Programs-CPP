#include<bits/stdc++.h>

using namespace std;

class Stack
{
private :
    vector<int> V;
    multiset<int,greater<int>> MS;

public :
    void push(int v)
    {
        V.push_back(v);
        MS.insert(v);
    }
    void pop()
    {
        multiset<int,greater<int>>  :: iterator itr;
        itr = MS.find(*(V.rbegin()));
        MS.erase(itr);
        V.pop_back();
    }
    void maxNum()
    {
        if(V.empty())
            return;
        cout << *(MS.begin()) << endl;
    }
};

int main()
{
    Stack ST;
    int n,v;
    cin >> n;
    string query;
    for(int i=0;i<n;i++)
    {
        cin >> query;
        if(query=="push")
        {
            cin >> v;
            ST.push(v);
        }
        else if(query=="pop")
        {
            ST.pop();
        }
        else if(query=="max")
        {
            ST.maxNum();
        }
    }
}
