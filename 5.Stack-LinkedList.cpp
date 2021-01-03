#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Ele
{
public :
    int key;
    int data;
    Ele* prev;
public :
    Ele()
    {
        key = 0;
        data = 0;
        prev = NULL;
    }
    Ele(int k, int d)
    {
        key = k;
        data = d;
        prev = NULL;
    }
};

class Stack
{
public :
    Ele* top;
public :
    Stack()
    {
        top=NULL;
    }
    Ele* eleExists(int k)
    {
        Ele* temp = NULL;
        Ele* ptr = top;
        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp = ptr;
            }
            ptr = ptr->prev;
        }
        return temp;
    }
    bool isEmpty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(Ele* n)
    {
        if(eleExists(n->key)!=NULL)
        {
            cout << "\nElement already exists with key : "<<n->key<<endl;
        }
        else
        {
            n->prev = top;
            top = n;
            cout << "\nElement was pushed"<<endl;
        }
    }
    void pop()
    {
       if(isEmpty())
       {
           cout << "\nStack Underflow"<<endl;
       }
       else
       {
           Ele * ptr;
           ptr = top;
           top = ptr->prev;
           ptr->prev = NULL;
           cout << "\nElement was popped"<<endl;
       }
    }
    void change(int k, int d)
    {
        Ele* ptr = eleExists(k);
        Ele* temp = NULL;
        Ele* pointer = top;
        if(ptr!=NULL)
        {
              ptr->data = d;
            while(pointer->prev!=ptr->prev)
            {
                temp= pointer->prev;
                pointer = pointer->prev;
            }
            top = ptr;
            cout<< "\nElement data updated"<<endl;
        }
        else
        {
            cout << "\nNode does not exist with key : "<<k<<endl;
        }
    }
    void peek(int k)
    {
        Ele* ptr = eleExists(k);
        if(ptr!=NULL)
        {
            cout << "\nThe data at key value "<<k<<" is "<<ptr->data<<endl;;
        }
        else
        {
            cout << "\nNode does not exist with key : "<<k<<endl;
        }
    }
    int count()
    {
        Ele* ptr = top;
        int c=0;
        while(ptr!=NULL)
        {
            c++;
            ptr = ptr->prev;
        }
        return c;
    }
    void display()
    {
        Ele* ptr = top;
        if(isEmpty())
        {
            cout << "\nStack is Empty"<<endl;
        }
        else
        {
        while(ptr!=NULL)
        {
            cout << ptr->data<<endl;
            ptr = ptr->prev;
        }
        }
    }

};

int main()
{
    Stack s;
    cout << "\nStack"<<endl;
    int option, key1, data1, k;
    do
    {
        cout << "\n1. Push"<<endl;
        cout << "2. Pop"<<endl;
        cout << "3. Peek"<<endl;
        cout << "4. Count"<<endl;
        cout << "5. Update"<<endl;
        cout << "6. Display"<<endl;
        cout << "7. Clear Screen"<<endl;

        cout << "\nEnter the option : ";
        cin >> option;

        Ele* n1 = new Ele();

        switch(option)
        {
        case 0 :
            break;
        case 1:
            cout << "Enter the key : ";
            cin >> key1;
            cout << "Enter the data : ";
            cin >> data1;
            n1->data = data1;
            n1->key = key1;
            s.push(n1);
            break;
        case 2 :
            s.pop();
            break;
        case 3 :
            cout << "\nEnter the key of element which you want to peek : ";
            cin >> k;
            s.peek(k);
            break;
        case 4 :
            cout << "\nThe number of elements in the stack is "<<s.count()<<endl;
            break;
        case 5 :
            cout << "Enter the key of element in which you want to update the data : ";
            cin >> k;
            cout << "Enter the data you want to update : ";
            cin >> data1;
            s.change(k,data1);
            break;
        case 6 :
            cout << "\nStack : "<<endl;
            s.display();
            break;
        case 7 :
            system("cls");
            break;
        default :
            cout << "\nInvalid choice"<<endl;
            break;
        }
    }
    while(option!=0);
}

