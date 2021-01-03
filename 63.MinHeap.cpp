#include<bits/stdc++.h>

using namespace std;

class minHeap
{
private :
    vector<int> heap;
    int hsize;
    int capacity;
public :
    minHeap(int c)
    {
        capacity = c;
        heap.resize(capacity);
        hsize = 0;
    }
    int parent(int i)
    {
        return (i-1)/2;
    }
    int leftChild(int i)
    {
        return 2*i +1;
    }
    int rightChild(int i)
    {
        return 2*i +2;
    }
    void siftUp(int i)
    {
        if(hsize==0)
            return;
        while(i>0 && heap[i]<heap[parent(i)])
        {
            swap(heap[i],heap[parent(i)]);
            i = parent(i);
        }
    }
    void siftDown(int i)
    {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        if(left<=hsize && heap[left]<heap[minIndex])
        {
            minIndex = left;
        }
        if(right<=hsize && heap[right]<heap[minIndex])
        {
            minIndex = right;
        }
        if(i!=minIndex)
        {
            swap(heap[i],heap[minIndex]);
            siftDown(minIndex);
        }
    }
    void addV(int x)
    {
        if(hsize==capacity)
        {
            cout << "\nHeap full"<<endl;
            return;
        }
        heap[hsize] = x;
        siftUp(hsize);
        hsize++;
        cout << "\nValue added"<<endl;
    }
    void removeV(int i)
    {
        if(hsize==0)
        {
            cout << "\nHeap empty"<<endl;
        }
        heap[i] = -100000;
        siftUp(i);
        cout << "\nValue removed"<<endl;
        getMin();
    }
    void changeV(int i,int x)
    {
        int oldV = heap[i];
        heap[i] = x;
        if(oldV < x)
        {
            siftDown(i);
        }
        else
        {
            siftUp(i);
        }
        cout << "\nValue changed"<<endl;
    }
    int getMin()
    {
        int minV = heap[0];
        heap[0] = heap[hsize];
        hsize--;
        siftDown(0);
        return minV;
    }
    void display()
    {
        cout << endl;
        for(int i=0;i<hsize;i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "MinHeap"<<endl;
    int option,n,v,i;
    cout << "\nEnter capacity of heap : ";
    cin >> n;
    minHeap MH(n);
    do
    {
        cout << "\n1. Insert"<<endl;
        cout << "2. Remove"<<endl;
        cout << "3. GetMin"<<endl;
        cout << "4. ChangePriority"<<endl;
        cout << "5. DisplayHeap"<<endl;
        cout << "6. ClearScreen"<<endl;

        cout << "\nEnter option : ";
        cin >> option;

        switch(option)
        {
        case 1 :
            cout << "\nElement to insert : ";
            cin >> v;
            MH.addV(v);
            break;
        case 2 :
            cout << "\nElement position to remove : ";
            cin >> i;
            MH.removeV(i);
            break;
        case 3 :
            cout << "\nMaximum Element : "<<MH.getMin()<<endl;
            break;
        case 4 :
            cout << "\nPosition in which to change priority : ";
            cin >> i;
            cout << "Element to change : ";
            cin >> v;
            MH.changeV(i,v);
             break;
        case 5 :
            cout << "\nMax Heap : \n";
            MH.display();
            break;
        case 6 :
             system("cls");
             break;
        default :
            break;
        }
    }
    while(option!=0);
}
