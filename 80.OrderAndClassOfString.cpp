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

int main(int argc,char **argv)
{
    string text;
    cin >> text;
    vector<int> order = sortCharacters(text);
    vector<int> cClass = characterClass(text,order);
    for(int i=0;i<order.size();i++)
        cout << order[i] << " ";
    cout << "\n";
    for(int i=0;i<cClass.size();i++)
        cout << cClass[i] << ' ';
}
