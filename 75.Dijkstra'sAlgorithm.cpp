#include<bits/stdc++.h>

using namespace std;

class Graph
{
private :
    vector<vector<pair<int,int>>> adjL;
    int vertices;
public :
    Graph(int v)
    {
        vertices = v+1;
        adjL.resize(vertices);
    }
    void addEdge(int x,int y,int w)
    {
        adjL[x].push_back(make_pair(y,w));
    }
    int dijkstra(int source,int destination)
    {
        set<pair<int,int>> S;
        vector<int> distance(vertices,INT_MAX);

        S.insert(make_pair(0,source));
        distance[source] = 0;

        while(!S.empty())
        {
            pair<int,int> P = *S.begin();
            S.erase(S.begin());

            int x = P.second;

            for(int i=0;i<adjL[x].size();++i)
            {
                int v = adjL[x][i].first;
                int w = adjL[x][i].second;

                if(distance[v]>distance[x]+w)
                {
                    if(distance[v]!=INT_MAX)
                    {
                        S.erase(S.find(make_pair(distance[v],v)));
                    }
                    distance[v] = distance[x]+w;
                    S.insert(make_pair(distance[v],v));
                }
            }
        }
        if(distance[destination]==INT_MAX)
            return -1;
        else
            return distance[destination];
    }
};

int main()
{
    int n,m,x,y,w;
    cin >> n >> m;
    Graph G(n);
    for(int i=0;i<m;i++)
    {
        cin >> x >> y >> w;
        G.addEdge(x,y,w);
    }
    cin >> x >> y;
    cout << G.dijkstra(x,y) << endl;
}
