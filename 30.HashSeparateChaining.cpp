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
    int bucket; // number of buckets(separate linked list each given an index value)
    list<int> *table; // pointer to list<int>
public :
    Hash(int b) // constructor initializing the number of buckets
    {
        bucket  = b;
        table = new list<int>[bucket]; // creating an array of bucket number of linked lists
    }
    int hashFunc(int key)
    {
        return key%bucket; // returns the index value
    }
    void insertValue(int key)
    {
        int index = hashFunc(key);  // gets the index value
        table[index].push_back(key); // puts the key into the linked list of the returned index
    }
    void printValue()
    {
        for(int i = 0;i<bucket;i++) // traverse for each bucket
        {
            cout << i;
            for(auto key : table[i])
            {
                cout << " -> "<< key; // printing all values in a single bucket and then iterating the next one
            }
            cout << endl;
        }
    }
};

int main()
{
    Hash h(9); // Hash table with 9 buckets constructed
    int *a = new int();
    int n;
    cout << "\nNumber of elements in hash table : ";
    cin >> n;
    for(int i =0;i<n;i++)
            {cin >> a[i];}
    for(int i=0;i<n;i++)
            {h.insertValue(a[i]);} // inserting every element
    h.printValue();
}
