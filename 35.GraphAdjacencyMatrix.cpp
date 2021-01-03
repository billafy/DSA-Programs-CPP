#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class GraphMatrix
{
private :
    bool **adjMatrix; // boolean 2D array, it will store 1 if an edge is present and 0 if it is not
    int vertices; // number of total vertices the graph can store

public :
    GraphMatrix(int v)
    {
        vertices = v;
        adjMatrix = new bool*[vertices];
        for(int i=0;i<vertices;i++)
        {
            adjMatrix[i] = new bool[vertices];
            for(int j=0;j<vertices;j++)
            {
                adjMatrix[i][j] = 0; // initialization of all adjacency matrix elements as 0
            }
        }
    }
    ~GraphMatrix()
    {
        for(int i=0;i<vertices;i++)
        {
            delete adjMatrix[i];
            delete adjMatrix;
        }
    }
    void insertEdge(int a, int b)
    {
        if(a>vertices || b>vertices)
        {
            cout << "\nInvalid input"<<endl; // if a and b are greater than the total number of vertices the graph can store, return
            return;
        }
        if(adjMatrix[a][b]==1)
        {
            cout << "\nEdge already present"<<endl; // if edge is already present, return
            return;
        }
        adjMatrix[a][b] = 1; // store 1 in the corresponding matrix element to add edge
        cout << "\n"<<a<<" - "<<b<<" Edge added"<<endl;
    }
    void removeEdge(int a,int b)
    {
        if(a>vertices || b>vertices)
        {
            cout << "\nInvalid input"<<endl;
            return;
        }
        if(adjMatrix[a][b]==0)
        {
            cout << "\nEdge does not exist"<<endl;
            return;
        }
        adjMatrix[a][b] = 0; // store 0 in the corresponding matrix element to remove edge
        cout << "\n"<<a<<" - "<<b<<" Edge removed"<<endl;
    }
    void searchEdge(int a,int b)
    {
        if(adjMatrix[a][b]==1)
        {
            cout << "\n"<<a<<" - "<<b<<" Edge Present"<<endl;
        }
        else
        {
            cout << "\nEdge not present"<<endl;
        }
    }
    void printEdge()
    {
        for(int i=0;i<vertices;i++)
        {
            for(int j=0;j<vertices;j++)
            {
                if(adjMatrix[i][j]==1)
                {
                    cout << i << " - " << j << endl;
                }
            }
        }
    }
};

int main()
{
    cout << "Graph - Adjacency Matrix"<<endl;
    int option,a,b,v;
    cout << "\nNumber of vertices : ";
    cin >> v;
    GraphMatrix *GM = new GraphMatrix(v);
    do
    {
        cout << "\n1. Add"<<endl;
        cout << "2. Remove"<<endl;
        cout << "3. Search"<<endl;
        cout << "4. Display"<<endl;
        cout << "5. Clear Screen"<<endl;

        cout << "\nEnter option : ";
        cin >> option;

        switch(option)
        {
        case 1 :
            cout << "\nEdge to add : ";
            cin >> a >> b;
            GM->insertEdge(a,b);
            break;
        case 2 :
            cout << "\nEdge to remove : ";
            cin >> a >> b;
            GM->removeEdge(a,b);
            break;
        case 3 :
            cout << "\nEdge to search : ";
            cin >> a >> b;
            GM->searchEdge(a,b);
            break;
        case 4 :
            cout << "\nGraph : "<<endl;
            GM->printEdge();
            break;
        case 5 :
            system("cls");
            break;
        default :
            cout << "\nInvalid choice"<<endl;
            break;
        }
    }
    while(option!=0);
    delete GM;
}
