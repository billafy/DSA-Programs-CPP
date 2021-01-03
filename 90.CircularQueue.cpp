#include<bits/stdc++.h>

using namespace std;

class CircularQueue
{
private :
    vector<int> cqueue;
    int capacity,F,R,cur;
public :
    CircularQueue(int n)
    {
        capacity = n;
        cqueue.resize(capacity);
        F = 0;
        R = -1;
        cur = 0;
    }
    void enqueue(int v)
    {
        if(cur==capacity)
        {
            cout << "\nFull" << endl;
            return;
        }
        cur++;
        if(F==-1 && R==-1)
        {
            cqueue[++R] = v;
            ++F;
        }
        else if(R==capacity-1)
        {
            R = 0;
            cqueue[R] = v;
        }
        else
        {
            cqueue[++R] = v;
        }
    }
    void dequeue()
    {
        if(cur==0)
        {
            cout << "\nEmpty" << endl;
            return;
        }
        cur--;
        F++;
    }
    void display()
    {
        if(cur==0)
        {
            cout << "\nEmpty" << endl;
            return;
        }
        cout << endl;
        if(R>F)
        {
           for(int i=F;i<=R;++i)
                cout << cqueue[i] << " ";
        }
        else
        {
            for(int i=F;i<capacity;++i)
                cout << cqueue[i] << " ";
            for(int i=0;i<=R;++i)
                cout << cqueue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int N;
    cin >> N;
    CircularQueue CQ(N);
    int v,option;
    do
    {
        cout << "\n1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Print" << endl;

        cout << "4. ClearScreen" << endl;

        cout << "\nEnter option : ";
        cin >> option;

        switch(option)
        {
        case 1 :
             cout << "\nValue : ";
             cin >> v;
             CQ.enqueue(v);
             break;
        case 2 :
            CQ.dequeue();
            break;
        case 3 :
            CQ.display();
            break;
        case 4 :
            system("cls");
            break;
        default :
            cout << "\nInvalid Choice" << endl;
            break;
        }
    }
    while(option!=0);
}
