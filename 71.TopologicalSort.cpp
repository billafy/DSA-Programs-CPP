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
    void explore(int v,vector<bool>& visited,stack<int>& S)
    {
        visited[v] = true;
        list<int> :: iterator itr;
        for(itr=adjL[v].begin();itr!=adjL[v].end();++itr)
        {
            if(visited[*itr]==false)
            {
                explore(*itr,visited,S);
            }
        }
        S.push(v);
    }
    void topologicalSort()
    {
        vector<bool> visited(vertices+1);
        stack<int> S;
        for(int i=1;i<=vertices;i++)
        {
            visited[i] = false;
        }
        for(int i=1;i<=vertices;i++)
        {
            if(visited[i]==false)
            {
                explore(i,visited,S);
            }
        }
        while(!S.empty())
        {
            cout << S.top() << " ";
            S.pop();
        }
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
    G.topologicalSort();
}
