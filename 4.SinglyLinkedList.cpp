#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Node
{
public :
    int data;
    int key;
    Node* next;
public :
    Node()
    {
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
friend class SLL;
};

class SLL
{
public :
    Node* head;
public :
    SLL()
    {
        head = NULL;
    }
    SLL(Node *h)
    {
        head = h;
    }
    Node* nodeExists(int k) // Check if nodes exists passing the key value
    {
        Node* temp = NULL;
        Node* ptr = head;
        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp=ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    void append(Node *h) // Attach a node to the end
    {
        if(nodeExists(h->key)!=NULL)
        {
            cout << "\nNode already exists with key value : "<<h->key<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head = h;
                cout << "\nNode appended"<<endl;
            }
            else
            {
                Node* ptr = head;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = h;
                cout << "\nNode appended"<<endl;
            }
        }
    }
    void prepend(Node* n) // Attach the note to the start
    {
       if(nodeExists(n->key)!=NULL)
        {
            cout << "\nNode already exists with key value : "<<n->key<<endl;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "\nNode prepended"<<endl;
        }
    }
    void insert(Node* n, int k) // Insert a node after a specific node by using key
    {
        Node *ptr = nodeExists(k);
        if(ptr==NULL)
        {
            cout << "\nNo node exists with key value"<<k<<endl;
        }
        else
        {
           if(nodeExists(n->key)!=NULL)
           {
               cout << "\nNode already exists with key value : "<<n->key<<endl;
           }
           else
           {
               n->next = ptr->next;
               ptr->next = n;
               cout << "\nNode inserted"<<endl;
           }
        }
    }
    void deleteNode(int k) // Delete a specific node by using key
    {
        if(head==NULL)
        {
            cout << "\nNo node attached yet"<<endl;
        }
        else if(head!=NULL)
        {
            if(head->key==k)
            {
            head = head->next;
            cout << "\nNode unlinked with key : "<<k<<endl;
            }
            else
            {
                Node* temp = NULL;
                Node* prevptr = head;
                Node* currptr = head->next;
                while(currptr!=NULL)
                {
                    if(currptr->key==k)
                    {
                        temp = currptr;
                        currptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currptr = currptr->next;
                    }
                }
                if(temp!=NULL)
                {
                    prevptr->next = temp->next;
                    cout << "\nNode unlinked with key : "<<k<<endl;
                }
                else
                {
                    cout << "\nNode doesn't exist with key : "<<k<<endl;
                }
            }
        }
    }
    void update(int k, int d) // updates the node data
    {
        Node* ptr = nodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data = d;
            cout << "\nNode data updated"<<endl;
        }
        else
        {
            cout << "\nNode doesn't exist with key : "<<k<<endl;
        }
    }
    void sort()
    {
        if(head==NULL)
        {
            cout << "\nEmpty List"<<endl;
        }
        else
        {
            Node* ptr = head;
            Node* nextptr = head->next;
            int temp;
            while(nextptr!=NULL)
            {
              if((ptr->data)>(nextptr->data))
              {
                  temp = ptr->data;
                  ptr->data = nextptr->data;
                  nextptr->data = temp;
              }
              ptr = ptr->next;
              nextptr = nextptr->next;
            }
            cout << "\nList Sorted"<<endl;
        }
    }
    void print() // Prints The SLL
    {
        if(head==NULL)
        {
            cout << "\nNo nodes to display"<<endl;
        }
        else
        {
            cout << "\nSingly List Linked : ";
            Node* temp = head;

            while(temp!=NULL)
            {
                cout << "("<<temp->key<<","<<temp->data<<")->";
                temp = temp->next;
            }
            cout << endl;
        }
    }

};

int main()
{
    SLL s1;
    int option;
    int key1,k,data1;
    do
    {

    cout << "\nSingly Linked List"<<endl;
    cout << "\n1. Append"<<endl;
    cout << "2. Prepend"<<endl;
    cout << "3. Insert"<<endl;
    cout << "4. Delete"<<endl;
    cout << "5. Update"<<endl;
    cout << "6. Sort"<<endl;
    cout << "7. Print"<<endl;
    cout << "8. Clear Screen"<<endl;
    cout << "\nEnter a option : "<<endl;
    cin >> option;
    Node* n1 = new Node();

    switch(option)
    {
    case 0 :
        break;
    case 1 :
        cout << "\nEnter the key : ";
        cin >> key1;
        cout << "Enter the data : ";
        cin >> data1;
        n1->key = key1;
        n1->data = data1;
        s1.append(n1);
        break;
    case 2 :
        cout << "\nEnter the key : ";
        cin >> key1;
        cout << "Enter the data : ";
        cin >> data1;
        n1->key = key1;
        n1->data = data1;
        s1.prepend(n1);
        break;
    case 3 :
        cout << "\nEnter the key : ";
        cin >> key1;
        cout << "Enter the data : ";
        cin >> data1;
        cout << "Enter the key of node after which you want to insert this node : ";
        cin >> k;
        n1->key = key1;
        n1->data = data1;
        s1.insert(n1,k);
        break;
    case 4 :
        cout << "\nEnter the key of node which you want to delete : ";
        cin >> k;
        s1.deleteNode(k);
        break;
    case 5 :
        cout << "\nEnter the key of which you have to update data : ";
        cin >> k;
        cout << "Enter the data which you want to update : ";
        cin >> data1;
        s1.update(k,data1);
        break;
    case 6 :
        s1.sort();
        break;
    case 7 :
        s1.print();
        break;
    case 8 :
        system("cls");
        break;
    default :
        cout << "\nInvalid choice"<<endl;
        break;
    }
    }
    while(option!=0);
    return 0;
}
