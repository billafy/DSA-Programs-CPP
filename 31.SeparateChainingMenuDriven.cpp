#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>
#include<thread>

using namespace std;

class Hash
{
private :
    int bucket;
    list<int> *table;
public :
    Hash(int b)
    {
        bucket  = b;
        table = new list<int>[bucket];
    }
    int hashFunc(int key)
    {
        return key%bucket;
    }
    void insertValue(int key)
    {
        int index = hashFunc(key);
        table[index].push_back(key);
        cout << "\nInserted"<<endl;
    }
    bool searchValue(int key)
    {
        int index = hashFunc(key);
        list<int> :: iterator itr;
        itr = table[index].begin();
        while(itr!=table[index].end())
        {
            if(*(itr)==key)
            {
                return true;
            }
            ++itr;
        }
        return false;
    }
    void deleteValue(int key)
    {
        int index = hashFunc(key);
        table[index].remove(key);
        cout << "\nDeleted"<<endl;
    }
    void printValue()
    {
        cout << "\nSeparate Chaining :\n";
        for(int i = 0;i<bucket;i++)
        {
            cout << i;
            for(auto key : table[i])
            {
                cout << " -> "<< key;
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << "Hash\n";
    int b,option,key;
    cout << "\nNumber of buckets : ";
    cin >> b;
    Hash h(b);
    do
    {
        cout << "\n1. Insert"<<endl;
        cout << "2. Search"<<endl;
        cout << "3. Delete"<<endl;
        cout << "4. Print"<<endl;
        cout << "5. Clear Screen"<<endl;

        cout << "\nEnter option : ";
        cin >> option;

        switch(option)
        {
        case 1 :
            cout << "\nKey to insert : ";
            cin >> key;
            h.insertValue(key);
            break;
        case 2 :
            cout << "\nKey to search : ";
            cin >> key;
            if(h.searchValue(key)==true)
            {
                cout << "\nPresent"<<endl;
            }
            else
            {
                cout << "\nNot Present"<<endl;
            }
            break;
        case 3 :
            cout << "\nKey to delete : ";
            cin >> key;
            h.deleteValue(key);
            break;
        case 4 :
            h.printValue();
            break;
        case 5 :
            system("cls");
            break;
        default :
            cout << "\nInvalid Choice"<<endl;
            break;
        }

    }
    while(option!=0);
}
