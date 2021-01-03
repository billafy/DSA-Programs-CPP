#include<bits/stdc++.h>

using namespace std;

class Graph
{
private :
    vector<list<int>> adjL;
    int vertices;
public :
    Graph(int v)
    {
        vertices = v;
        adjL.resize(vertices+1);
    }
    void addEdge(int x,int y)
    {
        adjL[x].push_back(y);
        adjL[y].push_back(x);
    }
    bool bipartite()
    {
        vector<int> BW(vertices+1);
        for(int i=1;i<=vertices;i++)
        {
            BW[i] = 3;
        }
        BW[1] = 1;
        queue<int> Q;
        Q.push(1);
        while(!Q.empty())
        {
            int v = Q.front();
            Q.pop();
            list<int> :: iterator itr;
            for(itr=adjL[v].begin();itr!=adjL[v].end();++itr)
            {
                if(BW[v]==1 && BW[*itr]==1 || BW[v]==2 && BW[*itr]==2)
                {
                    return false;
                }
                if(BW[*itr]==3)
                {
                    Q.push(*itr);
                    if(BW[v]==1)
                    {
                       BW[*itr] = 2;
                    }
                    else
                    {
                        BW[*itr] = 1;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    int n,m,x,y;
    cin >> n >> m;
    Graph G(n);
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        G.addEdge(x,y);
    }
    cout << G.bipartite() << endl;
}
