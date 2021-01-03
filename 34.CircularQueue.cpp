#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Node
{
public :
    int key;
    string value;
    Node* next;

    Node() : key(0), value(string("None")), next(NULL) {}
    Node(int k, string v) : key(k), value(v), next(NULL) {}
};

class CircularQueue
{
private :
    Node* front_n;
    Node* rear_n;

public :
    CircularQueue() : front_n(NULL), rear_n(NULL) {}
    CircularQueue(Node* f, Node* r) : front_n(f), rear_n(r) {}

    Node* traverse()
    {
        if(front_n==NULL)
        {
            return NULL;
        }
        else
        {
            Node* ptr = front_n;
            Node* temp = NULL;
            do
            {
                if(ptr->next==front_n)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            while(ptr!=front_n);
            return temp;
        }

    }
    void enqueue(Node* n)
    {
        if(front_n==NULL)
        {
            front_n = n;
            rear_n = n;
            n->next = front_n;
            cout << "\nEnqueued"<<endl;
        }
        else
        {
            Node* ptr = traverse();
            ptr->next = n;
            rear_n = n;
            n->next = front_n;
            cout << "\nEnqueued"<<endl;
        }
    }
    void dequeue()
    {
        if(front_n==NULL)
        {
            cout << "\nQueue Empty"<<endl;
        }
        else
        {
            Node* ptr = front_n;
            front_n = ptr->next;
            rear_n->next = front_n;
            cout << "\nDequeued"<<endl;
        }
    }
    void print()
    {
        if(front_n==NULL)
        {
            return;
        }
        Node* ptr = front_n;
        do
        {
            cout << "("<<ptr->key<<", "<<ptr->value<<") -> ";
            ptr = ptr->next;
        }
        while(ptr!=front_n);
        cout << endl;
    }
};

int main()
{
    cout << "\nCircular Queue"<<endl;
    CircularQueue *CQ = new CircularQueue();
    int option,id=1;
    string v;
    do
    {
        cout << "\n1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Print"<<endl;
        cout << "4. Clear Screen"<<endl;

        cout << "\nEnter option : ";
        cin >> option;

        Node* n = new Node();

        switch(option)
        {
        case 1 :
            cout << "\nEnter name : ";
            cin >> v;
            n->value = v;
            n->key = id;
            CQ->enqueue(n);
            id++;
            break;
        case 2 :
             CQ->dequeue();
             break;
        case 3 :
            cout << "\nCircular Queue : "<<endl;
            CQ->print();
            break;
        case 4 :
            system("cls");
            break;
        default :
            cout << "\nInvalid Choice"<<endl;
            break;
        }
    }
    while(option!=0);
}
