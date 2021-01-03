#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Member
{
public :
    int key;
    int data;
    Member* next;

    Member()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Member(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

class Queue
{
  public :
      Member* head;

      Queue()
      {
          head = NULL;
      }
      Queue(Member* h)
      {
          head = h;
      }

      Member* traverse(int k)
      {
          Member* ptr = head;
          Member* temp = NULL;
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
      void enqueue(Member* n)
      {
          if(traverse(n->key)!=NULL)
          {
              cout << "\nMember already exists with key : "<<n->key<<endl;
          }
          else
          {
            if(head==NULL)
            {
                head = n;
                cout << "\nEnqueued"<<endl;
            }
            else
            {
                Member* ptr = head;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "\nEnqueued"<<endl;
            }
          }
      }
      void dequeue()
      {
          if(head==NULL)
          {
              cout << "\nQueue is empty"<<endl;
          }
          else
          {
              if(head->next==NULL)
              {
                  head = NULL;
              }
              else
              {
                  Member* nextptr = head->next;
                  head = nextptr;
              }
          }
      }
      void update(int k, int d)
      {
          Member* ptr = traverse(k);
          Member* pointer = head;
          while(pointer->key!=k)
          {
              dequeue();
              pointer = pointer->next;
          }
          ptr->data = d;
          cout << "\nData updated"<<endl;
      }
      void peek(int k)
      {
          Member* ptr = traverse(k);
          cout << "\nThe data at key : "<<k<<" is : "<<ptr->data<<endl;
      }
      void count()
      {
           int c = 0;
           Member* ptr = head;
           while(ptr!=NULL)
           {
               ptr = ptr->next;
               c++;
           }
           cout << "\nThe count of members : "<<c<<endl;
      }
      void print()
      {
          if(head==NULL)
          {
              cout << "\nQueue is empty"<<endl;
          }
          else
          {
          Member* ptr = head;
          while(ptr!=NULL)
          {
              cout <<""<<ptr->data<<"-";
              ptr = ptr->next;
          }
          cout << "\n";
          }
      }
};

int main()
{
    int option,key1,data1;
    Queue q;
    cout << "\nQueue-Array"<<endl;
    do
    {
        cout << "\n1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Update"<<endl;
        cout << "4. Peek"<<endl;
        cout << "5. Count"<<endl;
        cout << "6. Print"<<endl;
        cout << "7. Clear Screen"<<endl;

        cout << "\nEnter the option : ";
        cin >> option;

        Member* n = new Member();

        switch(option)
        {
        case 0 :
            break;
        case 1 :
            cout << "\nEnter the key of member you want to enqueue : ";
            cin >> key1;
            cout << "Enter the data you want to enqueue : ";
            cin >> data1;
            n->key = key1;
            n->data = data1;
            q.enqueue(n);
            break;
        case 2 :
            q.dequeue();
            cout << "\nDequeued"<<endl;
            break;
        case 3 :
            cout << "\nEnter the key of member of which want to update the data : ";
            cin >> key1;
            cout << "Data to be updated : ";
            cin >> data1;
            q.update(key1,data1);
            break;
        case 4 :
            cout << "\nWhich key position do you want to peek : ";
            cin >> key1;
            q.peek(key1);
            break;
        case 5 :
            q.count();
            break;
        case 6 :
            cout << "\nQueue : "<<endl;
            q.print();
            break;
        case 7 :
            system("cls");
            break;
        default :
            break;
        }
    }
    while(option!=0);
}
