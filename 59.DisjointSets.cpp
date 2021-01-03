#include<bits/stdc++.h>

using namespace std;

class disjointSets
{
private :
    int *Parent;
    int *Rank;
    int Size;

public :
    disjointSets(int n)
    {
        Size = n;
        Parent = new int(Size);
        Rank = new int(Size);
        for(int i=0;i<Size;i++)
        {
            Parent[i] = 0;
            Rank[i] = -1;
        }
    }
    void makeSet(int i)
    {
        if(i<=0 || i>=Size)
        {
            cout << "\nInvalid input"<<endl;
            return;
        }
        Parent[i] = i;
        Rank[i] = 0;
        cout << "\nSet created"<<endl;
    }
    int findID(int i)
    {
        if(Parent[i]==0)
        {
            cout << "\nElement does not exist"<<endl;
            return -1;
        }
        while(i!=Parent[i])
        {
            i = Parent[i];
        }
        return i;
    }
    void unionSet(int i,int j)
    {
        if(Parent[i]==0 || Parent[j]==0)
        {
            cout << "\nElement does not exist"<<endl;
            return;
        }
        int i_id = findID(i);
        int j_id = findID(j);
        if(i_id==j_id)
            return;
        if(Rank[i_id]>Rank[j_id])
        {
            Parent[j_id] = i_id;
        }
        else
        {
            Parent[i_id] = j_id;
            if(Rank[i_id]==Rank[j_id])
            {
                ++Rank[j_id];
            }
        }
        cout << "\nUnion created"<<endl;
    }
    void displaySets()
    {
        for(int i=1;i<Size;i++)
        {
            for(int j=0;j<Size;j++)
            {
                if(Parent[j]==i)
                {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }
    bool isAFriend(int i,int j)
    {
        return Parent[i]==Parent[j] ? 1 : 0;
    }
    int heightSet(int i)
    {
        return Rank[i];
    }
};

int main()
{
    int n;
    cout << "\nDisjoint Sets"<<endl;
    cout << "\nNumber of elements in the set : ";
    cin >> n;
    disjointSets DS(n+1);
    int option,i,j;
    do
    {
        cout << "\n1. MakeSet"<<endl;
        cout << "2. FindID"<<endl;
        cout << "3. Union"<<endl;
        cout << "4. IsAFriend?"<<endl;
        cout << "5. DisplaySets"<<endl;
        cout << "6. Clear Screen"<<endl;

        cout << "\nEnter option : ";
        cin >> option;

        switch(option)
        {
        case 1 :
            cout << "\nElement to add in the set : ";
            cin >> i;
            DS.makeSet(i);
            break;
        case 2 :
            cout << "\nElement to get ID of : ";
            cin >> i;
            cout << "ID : "<<DS.findID(i)<<endl;
            break;
        case 3 :
            cout << "\nElement 1 : ";
            cin >> i;
            cout << "Element 2 : ";
            cin >> j;
            DS.unionSet(i,j);
            break;
        case 4 :
            cout << "\nElement 1 : ";
            cin >> i;
            cout << "Element 2 : ";
            cin >> j;
            if(DS.isAFriend(i,j))
                cout << "\nYes"<<endl;
            else
                cout << "\nNo"<<endl;
            break;
        case 5 :
            cout << "\nDisjoint Sets : \n";
            DS.displaySets();
            break;
        case 6 :
            cout << "\nElement to find rank of : ";
            cin >> i;
            cout << "\nRank : "<<DS.heightSet(i)<<endl;
            break;
        case 7 :
            system("cls");
            break;
        default :
            cout << "\nInvalid option"<<endl;
            break;
        }
    }
    while(option!=0);
}
