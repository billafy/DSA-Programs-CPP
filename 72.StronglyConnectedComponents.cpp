#include<bits/stdc++.h>

using namespace std;

class Graph
{
private :
    vector<list<int>> adjL;
    vector<list<int>> revL;
    int vertices;
public :
    Graph(int v)
    {
        vertices = v;
        adjL.resize(vertices+1);
        revL.resize(vertices+1);
    }
    void addEdge(int x,int y)
    {
        adjL[x].push_back(y);
        revL[y].push_back(x);
    }
    void explore(int v,vector<bool>& visited,stack<int>& S) // explores the graph and stores every sink in the stack
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
    void revExplore(int v,vector<bool>& visited) // explores the reversed graph
    {
        visited[v] = true;
        list<int> :: iterator itr;
        for(itr=revL[v].begin();itr!=revL[v].end();++itr)
        {
            if(!visited[*itr])
            {
                revExplore(*itr,visited);
            }
        }
    }
    void DFS()
    {
        vector<bool> visited(vertices+1); // boolean array which will check if an vertices is visited or not
        stack<int> S;
        for(int i=1;i<=vertices;i++)
        {
            visited[i] = false; // initialize to false
        }
        for(int i=1;i<=vertices;i++)
        {
            if(visited[i]==false)
                explore(i,visited,S); // explore every vertices one by one if it is unvisited
        }
        for(int i=1;i<=vertices;i++)
        {
            visited[i] = false; // initialize again to false to traverse the reversed graph
        }
        int scc = 0 ; // strongly connected components count
        while(!S.empty())
        {
            int v = S.top();
            S.pop();
            if(visited[v]==false)
            {
                revExplore(v,visited); // explore the top of stack in the reverse graph
                ++scc; // increment scc count
            }
        }
        cout << scc << endl;
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
    G.DFS();
}
