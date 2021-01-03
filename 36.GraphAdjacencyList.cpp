#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class GraphList
{
private :
    int vertices;
    set<int> *S;

public :
    GraphList(int v)
    {
        vertices = v;
        S = new set<int>[v];
    }
    ~GraphList()
    {
        delete S;
    }
    void addEdge(int a, int b)
    {
        if(a>=vertices || b>=vertices)
        {
            cout << "\nInvalid input"<<endl;
            return;
        }
        S[a].insert(b);
        S[b].insert(a);
        cout << "\n"<<a<<" - "<<b<<" Edge added"<<endl;
    }
    void removeEdge(int a,int b)
    {
        if(a>vertices || b>vertices)
        {
            cout << "\nInvalid input"<<endl;
            return;
        }
        if(S[a].find(b)==S[a].end())
        {
            cout << "\nEdge does not exist"<<endl;
            return;
        }
        S[a].erase(b);
        S[b].erase(a);
        cout << "\n"<<a<<" - "<<b<<" Edge removed"<<endl;
    }
    void searchEdge(int a,int b)
    {
        if(S[a].find(b)!=S[a].end())
        {
            cout << "\n"<<a<<" - "<<b<<" Edge present"<<endl;
        }
        else
        {
            cout << "\nEdge not present"<<endl;
        }
    }
    void printEdge()
    {
        set<int> :: iterator itr;
        for(int i=0;i<vertices;i++)
        {
            cout << i <<" -> ";
            for(itr=S[i].begin();itr!=S[i].end();++itr)
            {
                cout << *itr << " - ";
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << "Graph - Adjacency List"<<endl;
    int option,a,b,v;
    cout << "\nNumber of vertices : ";
    cin >> v;
    GraphList *GL = new GraphList(v);
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
            GL->addEdge(a,b);
            break;
        case 2 :
            cout << "\nEdge to remove : ";
            cin >> a >> b;
            GL->removeEdge(a,b);
            break;
        case 3 :
            cout << "\nEdge to search : ";
            cin >> a >> b;
            GL->searchEdge(a,b);
            break;
        case 4 :
            cout << "\nGraph : "<<endl;
            GL->printEdge();
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
    delete GL;
}
