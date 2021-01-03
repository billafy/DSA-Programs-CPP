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
    }
    bool explore(int v,vector<bool> visited,vector<bool> recStack)
    {
        if(visited[v]==false)
        {
            visited[v] = true;
            recStack[v] = true;
            list<int> :: iterator itr;
            for(itr=adjL[v].begin();itr!=adjL[v].end();++itr)
            {
                if(visited[*itr]==false && explore(*itr,visited,recStack))
                {
                   return true;
                }
                else if(recStack[*itr])
                {
                    return true;
                }
            }
        }
        recStack[v] = false;
        return false;
    }
    bool isCyclic()
    {
        vector<bool> visited(vertices+1);
        vector<bool> recStack(vertices+1);
        for(int i=1;i<=vertices;i++)
        {
            visited[i] = false;
            recStack[i] = false;
        }
        for(int i=1;i<=vertices;i++)
            if(explore(i,visited,recStack))
                return true;
        return false;
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
    if(G.isCyclic())
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
