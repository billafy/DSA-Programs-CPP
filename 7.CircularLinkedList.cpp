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

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

class CLL
{
public :
    Node* head;

    CLL()
    {
        head = NULL;
    }
    CLL(Node* h)
    {
        head = h;
    }
    Node* nodeExists(int k)
    {
        Node* ptr = head;
        Node* temp = NULL;
        if(ptr==NULL)
        {
            return temp;
        }
        else
        {
        do
        {
            if(ptr->key==k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        while(ptr!=head);
        return temp;
        }
    }
    void append(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout << "\nNode with key "<<n->key<<" already exists"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head = n;
                n->next = head;
                cout << "\nNode Appended"<<endl;
            }
            else
            {
                Node* ptr = head;
                while(ptr->next!=head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                cout << "\nNode appended"<<endl;
            }
        }
    }
    void prepend(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout << "\nNode with key "<<n->key<<" already exists"<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head = n;
                n->next = n;
                cout << "\nNode Prepended"<<endl;
            }
            else
            {
                Node* ptr = head;
                Node* temp = NULL;
                Node* second = head;
                do
                {
                    if(ptr->next==head)
                    {
                        temp=ptr;
                    }
                    ptr = ptr->next;
                }
                while(ptr!=head);
                n->next = second;
                head = n;
                temp->next = head;
                cout << "\nNode Prepended"<<endl;
            }
        }
    }
    void insert(int k, Node* n)
    {
        Node* ptr = nodeExists(k);
        if(ptr==NULL)
        {
            cout << "\nNode does not exist with key : "<<k<<endl;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout << "\nNode already exists with key : "<<n->key<<endl;
            }
            else if(head==NULL)
            {
                head = n;
                n->next = n;
                cout << "\nNode Inserted"<<endl;
            }
            else
            {
                Node* nextptr = ptr->next;
                ptr->next = n;
                n->next = nextptr;
                cout << "\nNode Inserted"<<endl;
            }
        }
    }
    void remove(int k)
    {
        Node* ptr = nodeExists(k);
        Node* prevptr = head;
        Node* nextptr = ptr->next;
        if(ptr==NULL)
        {
            cout << "\nNode with key : "<<k<<" does not exist"<<endl;
        }
        else
        {
            if(ptr==head)
            {
              if(head->next==head)
              {
                  head = NULL;
                  cout << "\nNode deleted"<<endl;
              }
              else
              {
                 Node* ptr = head;
                 while(ptr->next!=head)
                 {
                     ptr=ptr->next;
                 }
                 ptr->next = head->next;
                 head = head->next;
                 cout << "\nNode deleted"<<endl;
              }
            }
            else
            {
                Node* temp=NULL;
                while(prevptr->next!=ptr)
                {
                   temp = prevptr->next;
                   prevptr = prevptr->next;
                }
                prevptr->next = nextptr;
                ptr->next = NULL;
                cout << "\nNode Deleted"<<endl;
             }
        }
    }
    void update(int k, int d)
    {
        Node* ptr = nodeExists(k);
        ptr->data = d;
        cout << "\nNode Updated"<<endl;
    }
    void peek(int k)
    {
        Node* ptr = nodeExists(k);
        cout << "The data in the key "<<k<<" is "<<ptr->data<<endl;
    }
    void count()
    {
        int c = 0;
        Node* ptr = head;
        do
        {
            c++;
            ptr=ptr->next;
        }
        while(ptr!=head);
        cout << "\nNumber of nodes : "<<c<<endl;
    }
    void display()
    {
        if(head==NULL)
        {
            cout << "\nList is empty"<<endl;
        }
        else
        {
            Node* ptr = head;
            do
            {
                cout << "("<<ptr->key<<","<<ptr->data<<")->";
                ptr = ptr->next;
            }
            while(ptr!=head);
            cout << "\n";
        }
    }
};

int main()
{
    cout << "\nCircular Linked List"<<endl;
    CLL c;
    int option, key1, data1, k;
    do
    {
        cout << "\n1. Append"<<endl;
        cout << "2. Prepend"<<endl;
        cout << "3. Insert"<<endl;
        cout << "4. Delete"<<endl;
        cout << "5. Update"<<endl;
        cout << "6. Peek"<<endl;
        cout << "7. Count"<<endl;
        cout << "8. Display"<<endl;
        cout << "9. Clear Screen"<<endl;
        cout << "0. Exit Portal"<<endl;

        cout << "\nEnter the option : ";
        cin >> option;
        Node* n = new Node();

        switch(option)
        {
        case 0 :
            break;
        case 1 :
            cout << "Enter the key : ";
            cin >> key1;
            cout << "Enter the data : ";
            cin >> data1;
            n->key= key1;
            n->data = data1;
            c.append(n);
            break;
        case 2 :
            cout << "Enter the key : ";
            cin >> key1;
            cout << "Enter the data : ";
            cin >> data1;
            n->key= key1;
            n->data = data1;
            c.prepend(n);
            break;
        case 3 :
            cout << "Enter the key after which you want insert the new node : ";
            cin >> k;
            cout << "Enter the new key : ";
            cin >> key1;
            cout << "Enter the data : ";
            cin >> data1;
            n->key = key1;
            n->data = data1;
            c.insert(k,n);
            break;
        case 4 :
            cout << "Enter key of the node which you want to delete : ";
            cin >> key1;
            c.remove(key1);
            break;
        case 5 :
            cout << "\nEnter key of the node in which you want to update data : ";
            cin >> k;
            cout << "Enter the data you want to update : ";
            cin >> data1;
            c.update(k,data1);
            break;
        case 6 :
            cout << "\nEnter the key of node which you want to peek : ";
            cin >> k;
            c.peek(k);
            break;
        case 7 :
            c.count();
            break;
        case 8 :
            cout << "\nCircular Linked List : "<<endl;
            c.display();
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
