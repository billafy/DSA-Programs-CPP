#include<bits/stdc++.h>
#include<list>
#include<iterator>

using namespace std;

typedef unsigned long long big;

class WordChain
{
private :
    big buckets;
    vector<list<string>> words;
public :
    WordChain(big b)
    {
        buckets = b;
        words.resize(buckets);
    }
    big hashFunc(string word)
    {
        static const big multiplier = 263;
        static const big prime = 1000000007;
        big hashF = 0;
        big xi;
        for(big i=0;i<word.length();i++)
        {
            xi = pow(multiplier,i);
            hashF += word[i]*xi;
        }
        hashF = hashF % prime;
        hashF = ((hashF%buckets)+buckets)%buckets;
        return hashF;
    }
    list<string> :: iterator returnItr(big index,string word)
    {
        list<string> :: iterator itr = find(words[index].begin(),words[index].end(),word);
        return itr;
    }
    void addWord(string word)
    {
        big index = hashFunc(word);
        if(returnItr(index,word)!=words[index].end())
        {
            return;
        }
        words[index].push_front(word);
    }
    void delWord(string word)
    {
        big index = hashFunc(word);
        list<string> :: iterator itr = returnItr(index,word);
        if(itr!=words[index].end())
            words[index].erase(itr);
    }
    string findWord(string word)
    {
        big index  = hashFunc(word);
        if(returnItr(index,word)!=words[index].end())
        {
            return "yes";
        }
        else
        {
            return "no";
        }
    }
    void checkList(big x)
    {
        list<string> :: iterator itr;
        for(itr=words[x].begin();itr!=words[x].end();++itr)
        {
            cout << *itr << " ";
        }
        cout <<endl;
    }
};

int main()
{
    big buckets,m,x;
    string query,word;
    cin >> buckets >> m;
    WordChain WC(buckets);
    for(big i=0;i<m;++i)
    {
        cin >> query;
        if(query=="add")
        {
            cin >> word;
            WC.addWord(word);
        }
        else if(query=="del")
        {
            cin >> word;
            WC.delWord(word);
        }
        else if(query=="find")
        {
            cin >> word;
            cout << WC.findWord(word)<<endl;
        }
        else if(query=="check")
        {
            cin >> x;
            WC.checkList(x);
        }
    }
}
