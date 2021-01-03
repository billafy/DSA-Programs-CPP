#include<bits/stdc++.h>

using namespace std;

vector<int> sortCharacters(string S)
{
    vector<int> order(S.length());
    vector<int> aCount(178);
    fill(aCount.begin(),aCount.end(),0);
    for(int i=0;i<S.length();i++)
        ++aCount[S[i]];
    for(int j=1;j<aCount.size();j++)
        aCount[j] = aCount[j] + aCount[j-1];
    for(int i=S.length()-1;i>=0;i--)
    {
        int c = S[i];
        --aCount[c];
        order[aCount[c]] = i;
    }
    return order;
}

vector<int> characterClass(string S,vector<int> order)
{
    vector<int> cClass(S.length());
    cClass[order[0]] = 0;
    for(int i=1;i<S.length();i++)
    {
        if(S[order[i]]!=S[order[i-1]])
        {
            cClass[order[i]] = cClass[order[i-1]]+1;
        }
        else
        {
            cClass[order[i]] = cClass[order[i-1]];
        }
    }
    return cClass;
}

vector<int> sortDouble(string S,int L,vector<int> order,vector<int> cClass)
{
    vector<int> aCount(S.length());
    fill(aCount.begin(),aCount.end(),0);
    vector<int> newOrder(S.length());
    for(int i=0;i<S.length();i++)
        aCount[cClass[i]]++;
    for(int j=1;j<S.length();j++)
        aCount[j] = aCount[j-1] + aCount[j];
    for(int i=S.length()-1;i>=0;i--)
    {
        int start = (order[i]-L+S.length())%S.length();
        int cl = cClass[start];
        --aCount[cl];
        newOrder[aCount[cl]] = start;
    }
    return newOrder;
}

vector<int> doubleClass(vector<int> newOrder,vector<int> cClass,int L)
{
    int n = newOrder.size();
    vector<int> newClass(n);
    newClass[newOrder[0]] = 0;
    for(int i=1;i<n;i++)
    {
        int cur = newOrder[i];
        int prev = newOrder[i-1];
        int mid = cur + L;
        int midprev = (prev+L)%n;
        if(cClass[cur]!=cClass[prev] || cClass[mid]!=cClass[midprev])
        {
            newClass[cur] = newClass[prev] + 1;
        }
        else
        {
            newClass[cur] = newClass[prev];
        }
    }
    return newClass;
}

vector<int> buildSuffixArray(string S)
{
    vector<int> order = sortCharacters(S);
    vector<int> cClass = characterClass(S,order);
    int L = 1;
    while(L<=S.length())
    {
        order = sortDouble(S,L,order,cClass);
        cClass = doubleClass(order,cClass,L);
        L = 2*L;
    }
    return order;
}

int main(int argc,char **argv)
{
    string text;
    cin >> text;
    vector<int> order = buildSuffixArray(text);
    for(int i=0;i<order.size();i++)
        cout << order[i] << ' ';
}
