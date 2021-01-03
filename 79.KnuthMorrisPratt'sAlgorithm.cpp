#include<bits/stdc++.h>

using namespace std;

vector<int> prefixFunc(string text)
{
    vector<int> border(text.length()-1);
    int cur_b = 0;
    border.push_back(0);
    for(int i=1;i<border.size();i++)
    {
       while(cur_b>0 && text[i]!=text[cur_b])
       {
           cur_b = border[cur_b-1];
       }
       if(text[i]==text[cur_b])
       {
           cur_b++;
       }
       else
       {
           cur_b = 0;
       }
       border[i] = cur_b;
    }
    return border;
}

void patternMatch(string P,string T)
{
    string kmp = P+'$'+T;
    vector<int> kmpB = prefixFunc(kmp);
    for(int i=P.length()+1;i<kmp.length();i++)
    {
        if(kmpB[i]==P.length())
        {
            cout << i - 2 * P.length() << ' ';
        }
    }
}

int main()
{
    string pattern,text;
    cin >> pattern >> text;
    patternMatch(pattern,text);
}
