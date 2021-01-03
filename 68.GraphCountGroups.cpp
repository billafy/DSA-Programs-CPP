#include<bits/stdc++.h>

using namespace std;

class DisjointSets
{
private :
    vector<int> paths;
    int vertices;
public :
     DisjointSets(int v)
     {
         vertices = v;
         paths.resize(vertices+1);
         for(int i=1;i<=vertices;i++)
         {
             paths[i] = i;
         }
     }
     int pathID(int z)
     {
         if(z!=paths[z])
         {
             paths[z] = pathID(paths[z]);
         }
         return paths[z];
     }
     void addEdge(int x,int y)
     {
         int x_p = pathID(x);
         int y_p = pathID(y);
         if(x_p==y_p)
         {
             return;
         }
         paths[x_p] = y_p;
         for(int i=1;i<=vertices;i++)
         {
             if(paths[i]==x_p)
             {
                 paths[i] = y_p;
             }
         }
     }
     void numberOfGroups()
     {
        vector<int> Set;
        for(int i=1;i<=vertices;i++)
        {
            if(find(Set.begin(),Set.end(),paths[i])!=Set.end())
            {
                continue;
            }
            Set.push_back(paths[i]);
        }
        cout << Set.size() << endl;
     }
};

int main(int argc,char **argv)
{
    int n,m,x,y;
    cin >> n >> m;
    DisjointSets DS(n);
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        DS.addEdge(x,y);
    }
    DS.numberOfGroups();
}
