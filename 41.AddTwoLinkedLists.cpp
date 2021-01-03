#include<bits/stdc++.h>

using namespace std;

class Node
{
public :
    int value;
    Node* next;

    Node () : value(0),next(NULL) {}
    Node(int v) : value(v),next(NULL) {}
};

class SLL
{
private :
    Node* head;

public :
    SLL() : head(NULL){}
    SLL(Node* h) : head(h){}

    int append(int v)
    {
        Node* n = new Node(v);
        if(head==NULL)
        {
            head = n;
        }
        else
        {
            Node* ptr = head;
            Node* temp = NULL;
            while(ptr!=NULL)
            {
                if(ptr->next==NULL)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            temp->next = n;
        }
    }
    int prepend(int v)
    {
        Node* n = new Node(v);
        if(head==NULL)
        {
            head = n;
        }
        else
        {
            Node* temp = head;
            head = n;
            n->next = temp;
        }
    }
    int counter()
    {
        if(head==NULL)
            return 0;
        Node* ptr = head;
        int count = 0;
        while(ptr!=NULL)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
    void display()
    {
        if(head==NULL)
        {
            return;
        }
        else
        {
            Node* ptr = head;
            cout << endl;
            while(ptr!=NULL)
            {
                cout <<ptr->value <<" -> ";
                ptr = ptr->next;
            }
            cout << endl;
        }
    }
    int numReturn() // returns the list elements in a form of number
    {
        int count1 = counter();
        int mf = 1;
        int num = 0;
        Node* ptr = head;
        while(ptr!=NULL)
        {
            int x = ptr->value;
            num += x*mf;
            ptr = ptr->next;
            mf = mf*10;
        }
        return num;
    }
    SLL operator +(SLL List)
    {
        SLL temp;
        int x = numReturn();
        int y = List.numReturn();
        int z = x+y;
        while(z > 0)
        {
            int num = z % 10;
            temp.append(num);
            z = z/10;
        }
        return temp;
    }
};

int main()
{
    SLL L1,L2;
    L1.append(1); // appending to list 1
    L1.append(5);
    L1.append(2);
    L1.append(7);

    L2.append(5); // appending to list 2
    L2.append(2);
    L2.append(5);
    L2.append(9);

    SLL L3;
    L3 = L1 + L2; // adding both lists
    L3.display();
}
