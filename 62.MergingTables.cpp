#include<bits/stdc++.h>

using namespace std;

class DisjointSets
{
private :
    vector<int> rowSize;
    int sizeS;

public :
    DisjointSets(int n,int nRows[])
    {
        sizeS = n;
        for(int i=0;i<sizeS;i++)
        {
            rowSize.push_back(nRows[i]);
        }
    }
    int findID(vector<int> parent,int i)
    {
        if(i!=parent[i])
        {
            parent[i] = findID(parent,parent[i]);
        }
        return parent[i];
    }
    vector<int> mergeTables(vector<int> parent,int i,int j)
    {
        int i_id = findID(parent,i);
        int j_id = findID(parent,j);
        if(i_id==j_id)
            return parent;
        if(rowSize[i_id]>rowSize[j_id])
        {
            rowSize[i_id] = rowSize[i_id] + rowSize[j_id];
            rowSize[j_id] = 0;
            parent[j_id] = i_id;
        }
        else if(rowSize[i_id]<rowSize[j_id] || rowSize[i_id]==rowSize[j_id])
        {
            rowSize[j_id] = rowSize[j_id] + rowSize[i_id];
            rowSize[i_id] = 0;
            parent[i_id] = j_id;
        }
        return parent;
    }
    int maxRowSize()
    {
        int maxV = 0;
        for(int i=1;i<sizeS;i++)
        {
            if(rowSize[i]>maxV)
            {
                maxV = rowSize[i];
            }
        }
        return maxV;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n,m; // n : number of tables, m : number of merge queries to perform
    cin >> n >> m;
    int nRows[n+1];
    nRows[0] = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> nRows[i];
    }
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
    }
    DisjointSets DS(n+1,nRows);
    int x,y;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        parent = DS.mergeTables(parent,x,y);
        cout << "\n"<< DS.maxRowSize() << endl;
    }
}
