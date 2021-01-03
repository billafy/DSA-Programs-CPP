#include<bits/stdc++.h>

using namespace std;

class Point
{
public :
    int x;
    int y;
    Point()
    {
        x = y = 0;
    }
    Point(int X,int Y)
    {
        x = X;
        y = Y;
    }
};
class Edge
{
public :
    Point P1,P2;
    double edgeL;
    Edge(Point p1,Point p2)
    {
        P1 = p1;
        P2 = p2;
        edgeL = sqrt( (P1.x-P2.x)*(P1.x-P2.x) + (P1.y-P2.y)*(P1.y-P2.y) );
    }
};

bool Compare(Edge E1,Edge E2)
{
    if(E1.edgeL==E2.edgeL)
    {
        if(E1.P1.x==E1.P2.x)
        {
            return E1.P1.y < E1.P2.y;
        }
        return E1.P1.x < E1.P1.y;
    }
    return E1.edgeL < E2.edgeL;
}

class DisjointSets
{
private :
    vector<Point> points;
    vector<int> parent;
    vector<Edge> edges;
    int capacity;
    int csize;
public :
    DisjointSets(int c)
    {
        capacity = c;
        parent.resize(capacity);
        points.resize(capacity);
        csize=0;
    }
    void makeSet(Point P)
    {
        points[csize] = P;
        parent[csize] = csize;
        ++csize;
    }
    int findParent(Point P)
    {
       int a = 0;
       for(int i=0;i<capacity;i++)
       {
           if(points[i].x==P.x && points[i].y==P.y)
           {
               a = i;
               break;
           }
       }
       return parent[a];
    }
    bool unionSet(Edge E)
    {
        int P_id = findParent(E.P1);
        int Q_id = findParent(E.P2);
        if(P_id==Q_id)
        {
            return false;
        }
        parent[Q_id] = P_id;
        for(int i=0;i<capacity;i++)
        {
            if(parent[i]==Q_id)
                parent[i] = P_id;
        }
        return true;
    }
    double connectPoints()
    {
        double length = 0;
        for(int i=0;i<capacity;i++)
        {
            for(int j=i+1;j<capacity;j++)
            {
                if(i==j)
                {
                    continue;
                }
                Edge E(points[i],points[j]);
                edges.push_back(E);
            }
        }
        sort(edges.begin(),edges.end(),Compare);
        for(int i=0;i<edges.size();i++)
        {
            if(unionSet(edges[i]))
            {
                length += edges[i].edgeL;
            }
        }
        return length;
    }
};

int main()
{
    int n,x,y;
    cin >> n;
    DisjointSets DS(n);
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        Point P(x,y);
        DS.makeSet(P);
    }
    cout << setprecision(11) << DS.connectPoints() << endl;
}
