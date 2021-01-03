#include <bits/stdc++.h>

using namespace std;

class MaxHeap
{
private :
    int capacity; // maximum capacity of the heap
    int hsize; // current size of the heap
    int *Heap; // array which will store the heap contents

public :
    MaxHeap(int cap)
    {
        capacity = cap;
        Heap = new int[capacity]; // creating an array of passed capacity size
        hsize = 0; // setting current size to 0
    }

    int parent(int i)
    {
        return (i/2); // will return the parent index
    }
    int leftChild(int i)
    {
        return (2*i); // returns the index of left child
    }
    int rightChild(int i)
    {
        return ((2*i)+1); // returns the index of right child
    }
    void siftUp(int i)
    {
        while(i>1 && Heap[i]>Heap[parent(i)]) // loop until the parent is not greater than the i element
        {
            swap(Heap[parent(i)],Heap[i]);
            i = parent(i);
        }
    }
    void siftDown(int i)
    {
        int maxIndex = i;
        int left = leftChild(i); // compare left and right child and swap the i element with the largest one
        if(left<=hsize && Heap[left]>Heap[maxIndex])
            maxIndex = left;
        int right = rightChild(i);
        if(right<=hsize && Heap[right]>Heap[maxIndex])
            maxIndex = right;
        if(i!=maxIndex)
        {
            swap(Heap[maxIndex],Heap[i]);
            siftDown(maxIndex);
        }
    }
    void insertElement(int v)
    {
        if(hsize==capacity)
        {
            cout << "\nHeap Full"<<endl;
            return;
        }
        hsize++;
        Heap[hsize] = v; // insert new element as a leaf and sift it up until it is balanced
        siftUp(hsize);
        cout << "\nInserted"<<endl;
    }
    int getMax()
    {
        if(hsize==0)
        {
            cout << "\nHeap Empty"<<endl;
            return 0;
        }
        int maxV = Heap[1]; // store the root element as it is the maximum
        Heap[1] = Heap[hsize]; // now store the last leaf as root
        hsize--; // decrease heap size
        siftDown(1); // sift the new root until heap is balanced
        return maxV;
    }
    void removeElement(int i)
    {
        if(hsize==0)
        {
            cout << "\nHeap Empty"<<endl;
            return;
        }
        Heap[i] = 100000; // set the element to be removed to a large number
        siftUp(i); // sift it up
        cout << "\nRemoved"<<endl;
        getMax(); // getMax it as it will get removed
    }
    void changePriority(int i,int v)
    {
        int old = Heap[i];
        Heap[i] = v;
        if(Heap[i]>old) // if new value is greater than old value, sift up else sift down
        {
            siftUp(i);
        }
        else
        {
            siftDown(i);
        }
        cout << "\nChanged"<<endl;
    }
    void displayHeap()
    {
        if(hsize==0)
        {
            cout << "\nHeap Empty"<<endl;
        }
        for(int i=1;i<=hsize;i++)
        {
            cout << Heap[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "MaxHeap"<<endl;
    int option,n,v,i;
    cout << "\nEnter capacity of heap : ";
    cin >> n;
    MaxHeap MH(n);
    do
    {
        cout << "\n1. Insert"<<endl;
        cout << "2. Remove"<<endl;
        cout << "3. GetMax"<<endl;
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
            MH.insertElement(v);
            break;
        case 2 :
            cout << "\nElement position to remove : ";
            cin >> i;
            MH.removeElement(i);
            break;
        case 3 :
            cout << "\nMaximum Element : "<<MH.getMax()<<endl;
            break;
        case 4 :
            cout << "\nPosition in which to change priority : ";
            cin >> i;
            cout << "Element to change : ";
            cin >> v;
            MH.changePriority(i,v);
             break;
        case 5 :
            cout << "\nMax Heap : \n";
            MH.displayHeap();
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
