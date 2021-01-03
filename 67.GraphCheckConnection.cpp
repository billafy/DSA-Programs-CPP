#include<bits/stdc++.h>

using namespace std;

class DisjointSets
{
private :
    int sizeS;
    vector<int> paths;
public :
    DisjointSets(int s)
    {
        sizeS = s;
        paths.resize(sizeS+1);
        for(int i=1;i<=sizeS;i++)
        {
            paths[i] = i;
        }
    }
    int parent(int z)
    {
        if(z!=paths[z])
        {
            paths[z] = parent(paths[z]);
        }
        return paths[z];
    }
    void addEdge(int x,int y)
    {
        int x_p = parent(x);
        int y_p = parent(y);
        if(x_p==y_p)
        {
            return;
        }
        else
        {
            paths[x_p] = y_p;
        }
    }
    void checkPath(int x,int y)
    {
        int x_p = parent(x);
        int y_p = parent(y);
        if(x_p==y_p)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
};

int main()
{
    int n,m,u,v; // n : number of vertices , m : number of edges
    cin >> n >> m;
    DisjointSets DS(n);
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        DS.addEdge(u,v);
    }
    cin >> u >> v;
    DS.checkPath(u,v);
}
