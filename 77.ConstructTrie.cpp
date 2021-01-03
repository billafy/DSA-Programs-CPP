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
        edges.resize(10000);
        p_count = 0;
    }
    void addEdge(int x,int y,char l)
    {
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
    void constructTrie(vector<string> texts,int n)
    {
        for(int i=0;i<texts.size();i++)
        {
            int root = 0;
            for(int j=0;j<texts[i].length();j++)
            {
                char next = texts[i][j];
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
    void displayTrie()
    {
        list<pair<int,char>> :: iterator itr;
        for(int i=0;i<edges.size();i++)
        {
            for(itr=edges[i].begin();itr!=edges[i].end();++itr)
            {
                cout << i << "->" << (*itr).first << ":" << (*itr).second <<endl;
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> texts(n);
    for(int i=0;i<n;i++)
    {
        cin >> texts[i];
    }
    Trie T;
    T.constructTrie(texts,n);
    T.displayTrie();
}
