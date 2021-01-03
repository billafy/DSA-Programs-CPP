#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Queue
{
public :
    int* a;
    int qsize;
    int front;
    int rear;

    Queue(int q)
    {
        qsize = q;
        a = new int(qsize);
        for(int i=0;i<qsize;i++)
        {
            a[i]=0;
        }
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if(rear==-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(rear==qsize-1)
            return true;
        else
            return false;
    }
    void enqueue(int d)
    {
        if(isFull())
        {
            cout << "\nQueue is full"<<endl;
        }
        else
        {
            if(front==-1 && rear==-1)
            {
                a[0] = d;
                cout << "\nEnqueued"<<endl;
                front++;
                rear++;
            }
            else
            {
                a[rear+1] = d;
                rear++;
                cout << "\nEnqueued"<<endl;
            }
        }
    }
    void dequeue(int i)
    {
        if(isEmpty())
        {
            cout << "\nQueue is empty"<<endl;
        }
        else
        {
            if(front==0 && rear==0)
            {
                a[0]=0;
                front--;
                rear--;
            }
            else
            {
                a[front]=0;
                for(int i=0;i<qsize;i++)
                {
                    a[i] = a[i+1];
                }
                rear--;
                for(int i=rear+1;i<qsize;i++)
                {
                    a[i]=0;
                }
            }
        }
    }
    void update(int ind, int d)
    {
        for(int i=0;i<ind;i++)
        {
            dequeue(i);
        }
        a[0]=d;
        cout << "\nData updated"<<endl;
    }
    void peek(int ind)
    {
        cout << "\nThe data at index position "<<ind<<" is : "<<a[ind]<<endl;
    }
    int count()
    {
       int c = 0;
       for(int i=0;i<qsize;i++)
       {
           if(a[i]!=0)
           {
              c++;
           }
       }
       return c;
    }
    void display()
    {
        cout << "\nQueue : "<<endl;
        for(int i=0;i<qsize;i++)
        {
            cout <<""<<a[i]<<"-";
        }
        cout <<"\n";
    }
};

int main()
{
    int n,option,data,index;
    cout << "\nQueue-Array"<<endl;
    cout << "\nEnter the size of queue : ";
    cin >> n;
    Queue q(n);

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

        switch(option)
        {
        case 0 :
            break;
        case 1 :
            cout << "\nEnter the element you want to enqueue : ";
            cin >> data;
            q.enqueue(data);
            break;
        case 2 :
            q.dequeue(0);
            cout << "\nDequeued"<<endl;
            break;
        case 3 :
            cout << "\nOf which index position do you want update the data : ";
            cin >> index;
            cout << "Data to be updated : ";
            cin >> data;
            q.update(index,data);
            break;
        case 4 :
            cout << "\nWhich index position do you want to peek : ";
            cin >> index;
            q.peek(index);
            break;
        case 5 :
            cout << "\nThe count of queue : "<<q.count()<<endl;
            break;
        case 6 :
            q.display();
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
