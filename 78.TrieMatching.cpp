#include<bits/stdc++.h>

using namespace std;

class Trie
{
private :
    vector<list<pair<int,char>>> edges;
    int p_count;
public :
    Trie()
    {
        edges.resize(1);
        p_count = 0;
    }
    void addEdge(int x,int y,char l)
    {
        edges.resize(p_count+1);
        edges[x].push_back(make_pair(y,l));
    }
    int searchLetter(int x,char l)
    {
        list<pair<int,char>> :: iterator itr;
        for(itr=edges[x].begin();itr!=edges[x].end();++itr)
        {
            pair<int,char> P = *itr;
            if(P.second==l)
            {
                return P.first;
            }
        }
        return -1;
    }
    void constructTrie(vector<string> patterns,int n)
    {
        for(int i=0;i<patterns.size();i++)
        {
            int root = 0;
            for(int j=0;j<patterns[i].length();j++)
            {
                char next = patterns[i][j];
                if(searchLetter(root,next)!=-1)
                {
                    root = searchLetter(root,next);
                }
                else
                {
                    addEdge(root,++p_count,next);
                    root = p_count;
                }
            }
        }
    }
    bool isLeaf(int node)
    {
        if(edges[node].begin()==edges[node].end())
        {
            return true;
        }
        return false;
    }
    void stringMatch(string text,int start)
    {
        int root = 0;
        for(int i=0;i<text.length();i++)
        {
            char next = text[i];
            if(searchLetter(root,next)!=-1)
            {
                root = searchLetter(root,next);
                if(isLeaf(root))
                {
                    cout << start << " ";
                }
            }
            else
            {
                break;
            }
        }
    }
    void utility(string text)
    {
        int i = 0;
        while(text.length()>0)
        {
            stringMatch(text,i);
            i++;
            text.erase(text.begin());
        }
    }
};

int main()
{
    string text;
    cin >> text;
    int n;
    cin >> n;
    vector<string> patterns(n);
    for(int i=0;i<n;i++)
    {
        cin >> patterns[i];
    }
    Trie T;
    T.constructTrie(patterns,n);
    T.utility(text);
}

