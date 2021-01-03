#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>

using namespace std;

template <class K,class V> // generic type names
class Pair // creating a pair of key and value which will be inserted in the hash map
{
public :
     K key;
     V value;
     Pair()
     {
         key = 0;
         value = "None";
     }
     Pair(K k, V v)
     {
         key = k;
         value = v;
     }
};

template <typename K,typename V>
class Hash
{
private :
    Pair<K,V> **P;
    int capacity; // capacity of the whole hash map
    int hsize; // will track the current size of the hash map
    Pair<K,V> *dummy; // dummy pair to mark a deleted pair in the hash map
public :
    Hash(int c)
    {
        capacity = c;
        hsize = 0;
        P = new Pair<K,V>*[capacity]; // P is the array of pairs of size of capacity
        for(int i=0;i<capacity;i++)
        {
            P[i] = NULL; // initialize all the elements to NULL
        }
        dummy = new Pair<K,V>(-1,"None"); // dummy element will be store -1 and -1 key and value
    }
    int hashFunc(K k)
    {
        return k%capacity;
    }
    void insertPair(K k, V v)
    {
        int i =1;
        int index  = hashFunc(k); // take the index value by calling the special has function
        Pair<K,V> *temp = new Pair<K,V>(k,v);
        if(hsize==capacity) // if the number of pairs become equal to the map capacity, do no insert anymore pairs
        {
            cout << "\nHash Map Full"<<endl;
        }
        else if(P[index]==NULL || P[index]->key==-1) // if a slot is vacant or holds a dummy key, insert the pair
        {
            P[index] = temp;
            hsize++;
            cout << "\nInserted"<<endl;
        }
        else // if the calculated slot is not vacant for the pair, follow the steps below
        {
            while(P[index]!=NULL && P[index]->key!=-1 && (i*i)<capacity) // traverse until you find a slot with NULL or dummy pair
            {
                index+= (i*i); // probing by incrementing index value
                index = index%capacity;
                i++;
            }
            if((i*i)>capacity)
            {
                while(P[index]!=NULL && P[index]->key!=-1) // traverse until you find a slot with NULL or dummy pair
                {
                index++; // probing by incrementing index value
                index = index%capacity;
                }
            }

                P[index] = temp;
                hsize++;
                cout << "\nInserted"<<endl;
        }
    }
    V deletePair(K k)
    {
        int index = hashFunc(k);
        int count = 1; // count meter so the loop can break when it has traversed through all pairs
        int i=1;
        while(P[index]!=NULL)
        {
            if(P[index]->key == k) // if the pair key is equal to passed key, replace it by dummy pair
            {
                Pair<K,V> *temp = P[index];
                P[index] = dummy;
                hsize--; // decrement the hash map size
                return temp->value; // return the deleted value
            }
            index += (i*i); // increment index to check the next pair
            index = index%capacity;
            count++;
            i++;
            if(count>capacity)
            {
                break;
            }
            if((i*i)>capacity)
            {
                break;
            }
        }
        if((i*i)>capacity)
        {
          while(P[index]!=NULL)
          {
            if(P[index]->key == k) // if the pair key is equal to passed key, replace it by dummy pair
            {
                Pair<K,V> *temp = P[index];
                P[index] = dummy;
                hsize--; // decrement the hash map size
                return temp->value; // return the deleted value
            }
            index++; // increment index to check the next pair
            index = index%capacity;
            count++;
            if(count>capacity)
            {
                break;
            }

          }
        }
        return string("NULL"); // return NULL if key does not exist
    }
    bool searchPair(int k)
    {
        int index = hashFunc(k);
        int count=1;
        int i =1;
        while(P[index]!=NULL)
        {
            if(P[index]->key==k) // if key is present return true
            {
                return true;
            }
            index+=(i*i);
            index%=capacity;
            i++;
            count++;
            if(count>capacity) // traverse until count is equal to capacity and break
            {
                break;
            }
            if((i*i)>capacity)
            {
                break;
            }
        }
        if((i*i)>capacity)
        {
            while(P[index]!=NULL)
           {
            if(P[index]->key==k) // if key is present return true
            {
                return true;
            }
            index++;
            index%=capacity;
            count++;
            if(count>capacity) // traverse until count is equal to capacity and break
            {
                break;
            }
           }
        }
        return false;
    }
    void printPair() // displays all the key value pairs
    {
        for(int i=0;i<capacity;i++)
        {
            if(P[i]!=NULL && P[i]->key!=-1) // would not print dummy pairs

                cout << "Key : "<<P[i]->key<<" Value : "<<P[i]->value<<endl;
        }
        cout << endl;
    }
};

int main()
{
    int c,option,k;
    string v,returnedvalue;
    cout << "Open Addressing - Quadratic Probing"<<endl;
    cout << "\nEnter capacity of hash map : ";
    cin >> c;
    Hash<int,string> *H = new Hash<int,string>(c);
    do
    {
        cout << "\n1. Insert"<<endl;
        cout << "2. Delete"<<endl;
        cout << "3. Search"<<endl;
        cout << "4. Display"<<endl;
        cout << "5. Clear Screen"<<endl;

        cout << "\nEnter option : ";
        cin >> option;

        Pair<int,string> *P = new Pair<int,string>();

        switch(option)
        {
        case 1 :
            cout << "\nEnter key to insert : ";
            cin >> k;
            cout << "Enter value to insert : ";
            cin >> v;
            P->key = k;
            P->value = v;
            H->insertPair(k,v);
            break;
        case 2 :
            cout << "\nEnter key to delete : ";
            cin >> k;
             returnedvalue = H->deletePair(k);
            if(returnedvalue!="NULL")
            {
                cout << "\nDeleted key with value : "<<returnedvalue<<endl;
            }
            else
            {
                cout << "\nPair does not exist"<<endl;
            }
            break;
        case 3 :
             cout << "Enter key to search : ";
             cin >> k;
             if(H->searchPair(k))
             {
                 cout << "\nKey is present"<<endl;
             }
             else
             {
                 cout << "\nKey is not Present"<<endl;
             }
             break;
        case 4 :
             cout << "\nHash Map : \n";
             H->printPair();
             break;
        case 5 :
            system("cls");
             break;
        default :
             cout << "\nInvalid Choice"<<endl;
             break;
        }
        delete P;
    }
    while(option!=0);
}

