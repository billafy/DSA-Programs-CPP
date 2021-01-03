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
    int BFS(int source,int destination)
    {
        vector<int> distance(vertices+1);
        for(int i=1;i<=vertices;i++)
        {
            distance[i] = -1;
        }
        distance[source] = 0;
        queue<int> Q;
        Q.push(source);
        while(!Q.empty())
        {
            int v = Q.front();
            Q.pop();
            list<int> :: iterator itr;
            for(itr=adjL[v].begin();itr!=adjL[v].end();++itr)
            {
                if(distance[*itr]==-1)
                {
                    Q.push(*itr);
                    distance[*itr] = distance[v] + 1;
                }
            }
        }
        return distance[destination];
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
    cin >> x >> y;
    cout << G.BFS(x,y) << endl;
}
