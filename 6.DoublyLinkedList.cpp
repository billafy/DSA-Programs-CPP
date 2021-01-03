#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Node
{
public :
    int key;
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DLL
{
public :
    Node* head;
    DLL()
    {
        head = NULL;
    }
    DLL(Node *h)
    {
        head = h;
    }
    Node* nodeExists(int k)
    {
        Node* temp = NULL;
        Node* ptr = head;
        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp = ptr;
            }
                ptr = ptr->next;
        }
        return temp;
    }
    void append(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout << "\nThe node with key : "<<n->key<<" already exists"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head = n;
                cout << "\nNode appended"<<endl;
            }
            else
            {
            Node* ptr = head;
            while(ptr->next!=NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
            n->prev = ptr;
            cout << "\nNode appended"<<endl;
            }
        }
    }
    void prepend(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout << "\nThe node with key : "<<n->key<<" already exists"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head = n;
                cout << "\nNode prepended"<<endl;
            }
            else
            {
                Node* ptr = head;
                head = n;
                n->next = ptr;
                ptr->prev = n;
                cout << "\nNode prepended"<<endl;
            }
        }
    }
    void insert(Node*n, int key1)
    {
       Node* ptr = nodeExists(key1);
       if(ptr==NULL)
       {
           cout << "\nThe node with key "<<key1<<" does not exist"<<endl;
       }
       else
       {
           if(nodeExists(n->key)!=NULL)
           {
               cout << "\nNode with key : "<<n->key<<" already exists"<<endl;
           }
           else
           {
               Node* nextptr = ptr->next;
               ptr->next = n;
               n->prev = ptr;
               nextptr->prev = n;
               n->next = nextptr;
               cout << "\nNode Inserted"<<endl;
           }
       }
    }
    void update(int k, int d)
    {
        Node* ptr = nodeExists(k);
        if(ptr!=NULL)
        {
        ptr->data = d;
        cout << "\nNode Updated"<<endl;
        }
        else
        {
            cout << "\nNode with key "<<k<<" does not exist"<<endl;
        }
    }
    void remove(int k)
    {
        Node* ptr = nodeExists(k);
            if(ptr==NULL)
            {
                cout << "\nNode with key "<<k<<" does not exist"<<endl;
            }
            else
            {
                if(head->key==k)
                {
                    Node* nextptr = ptr->next;
                    head = ptr->next;
                    nextptr->prev = NULL;
                    cout << "\nNode deleted"<<endl;
                }
                else if(ptr->next==NULL)
                {
                    Node* prevptr = ptr->prev;
                    prevptr->next = NULL;
                    ptr->prev = NULL;
                    cout << "\nNode deleted"<<endl;
                }
                else
                {
                    Node* prevptr = ptr->prev;
                    Node* nextptr = ptr->next;
                    prevptr->next = nextptr;
                    nextptr->prev = prevptr;
                    cout << "\nNode Deleted"<<endl;
                }
            }

    }
    void print()
    {
       Node* ptr = head;
       while(ptr!=NULL)
       {
           cout << "("<<ptr->key<<","<<ptr->data<<")<->";
           ptr = ptr->next;
       }
       cout << endl;
    }
    int count()
    {
        int c = 0;
        Node* ptr = head;
        while(ptr!=NULL)
        {
            c++;
            ptr = ptr->next;
        }
        return c;
    }
    void peek(int k)
    {
        Node* ptr = nodeExists(k);
        if(ptr==NULL)
        {
            cout << "\nNode with key "<<k<<" does not exist"<<endl;
        }
        else
        {
            cout << "\nThe data in key "<<k<<" is "<<ptr->data<<endl;
        }
    }
};

int main()
{
    DLL d;
    int option, data1, key1, k1;
    cout << "\nDoubly Linked List"<<endl;
    do
    {
        cout <<"\n1. Append"<<endl;
        cout <<"2. Prepend"<<endl;
        cout <<"3. Insert"<<endl;
        cout <<"4. Delete"<<endl;
        cout <<"5. Update"<<endl;
        cout <<"6. Peek"<<endl;
        cout <<"7. Count"<<endl;
        cout <<"8. Display"<<endl;
        cout <<"9. Clear Screen"<<endl;

        cout << "\nEnter option : ";
        cin >> option;
        Node* n1 = new Node();

        switch(option)
        {
        case 0 :
            break;
        case 1 :
            cout << "Enter the key : ";
            cin >> key1;
            cout << "Enter the data : ";
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            d.append(n1);
            break;
        case 2 :
            cout << "Enter the key : ";
            cin >> key1;
            cout << "Enter the data : ";
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            d.prepend(n1);
            break;
        case 3 :
            cout << "Enter the key of node after which you want to enter another node : ";
            cin >> k1;
            cout << "Enter the key : ";
            cin >> key1;
            n1->key = key1;
            cout << "Enter the data : ";
            cin >> data1;
            n1->data = data1;
            d.insert(n1,k1);
            break;
        case 4 :
            cout << "Enter key of the node which you want to delete : ";
            cin >> k1;
            d.remove(k1);
            break;
        case 5 :
            cout << "\nEnter the key of which you want tot update the data : ";
            cin >> k1;
            cout << "Enter the data to be updated : ";
            cin >> data1;
            d.update(k1,data1);
            break;
        case 6 :
            cout << "\nEnter the key which you want to peek : ";
            cin >> k1;
            d.peek(k1);
            break;
        case 7 :
            cout << "\nThe number of nodes in the list is : "<<d.count()<<endl;
            break;
        case 8 :
            cout << "\nDoubly Linked List : "<<endl;
            d.print();
            break;
        case 9 :
            system("cls");
            break;
        default :
            break;
        }
    }
    while(option!=0);
}
