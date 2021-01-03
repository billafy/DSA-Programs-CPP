#include<bits/stdc++.h>

using namespace std;

class Graph
{
private :
    vector<vector<int>> adjL;
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
    void explore(int x,vector<bool>& visited)
    {
        visited[x] = true;
        cout << x << endl;
        for(int i=0;i<adjL[x].size();++i)
        {
            int y = adjL[x][i];
            if(!visited[y])
            {
                explore(y,visited);
            }
        }
    }
    void dfs(int x)
    {
        vector<bool> visited(vertices+1,false);
        explore(x,visited);
    }
};

int main()
{
    Graph G(5);
    G.addEdge(1,2);
    G.addEdge(1,3);
    G.addEdge(2,3);
    G.addEdge(3,1);
    G.addEdge(3,4);
    G.addEdge(4,4);
    G.dfs(3);
}
