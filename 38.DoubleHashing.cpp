#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class DoubleHash
{
private :
    int *table; // hash table
    int cur_size; // holds the current size of the map, initialized to 0
    int capacity; // maximum keys the map can hold
public :
    DoubleHash(int c)
    {
        capacity = c;
        table = new int[capacity];
        cur_size = 0;
        for(int i=0;i<capacity;i++)
        {
            table[i] = -1; // all elements initialized to -1, -1 is the dummy value
        }
    }
    int hashFunc(int key) // hash function 1
    {
        return key%capacity;
    }
    int hashFunc2(int key) // hash function 2
    {
        return (capacity/2) - (capacity/2)*key;
    }
    void insert(int key)
    {
        if(cur_size==capacity) // if current size is equal to capacity, the map is full
        {
            cout << "\nMap is full"<<endl;
            return;
        }
        int index1 = hashFunc(key); // call hash function 1
        if(table[index1]==-1) // if no collision
        {
            table[index1] = key;
            cout << "\nInserted"<<endl;
            cur_size++;
        }
        else // if collision occurs
        {
            int index2 = hashFunc2(key); // call hash function 2
            int i = 1;
            while(true)
            {
                int index = (index1 + (i*index2)) % capacity; // get the double hash index value and loop until you do not find an empty slot
                if(table[index]==-1)
                {
                    table[index] = key;
                    cout << "\nInserted"<<endl;
                    cur_size++;
                    break;
                }
                i++;
            }
        }
    }
    void remove(int key)
    {
        int index1 = hashFunc(key); // similar as insertion
        if(table[index1]==key)
        {
            table[index1] = -1;
            cout << "\nDeleted"<<endl;
            cur_size--;
            return;
        }
        else
        {
            int index2 = hashFunc2(key);
            int i = 1;
            do
            {
                if(table[(index1 + (i*index2))%capacity] == key)
                {
                    table[(index1 + (i*index2))%capacity] = -1;
                    cout << "\nDeleted"<<endl;
                    cur_size--;
                    return;
                }
                i++;
            }
            while(table[(index1 + (i*index2))%capacity] != key);
        }
    }
    void display()
    {
        for(int i=0;i<capacity;i++)
        {
            if(table[i]!=-1)
            {
                cout << table[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    DoubleHash *DH = new DoubleHash(20);
    DH->insert(5);
    DH->insert(2);
    DH->insert(10);
    DH->insert(25);
    DH->insert(27);
    DH->display();
    DH->remove(27);
    DH->remove(5);
    DH->display();
    cin.get();
}
