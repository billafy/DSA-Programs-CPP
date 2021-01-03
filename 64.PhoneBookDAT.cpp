#include <bits/stdc++.h>

using namespace std;

class PhoneBook
{
private :
    vector<pair<int,string>> book;
    int capacity;
    pair<int,string> dummy;
public :
    PhoneBook(int n)
    {
        capacity = n;
        book.resize(capacity);
        dummy.first = -1;
        dummy.second = "None";
    }
    void addN(int num,string nam)
    {
        pair<int,string> P;
        P.first = num;
        P.second = nam;
        book[num] = P;
    }
    void deleteN(int num)
    {
        book[num] = dummy;
    }
    string findN(int num)
    {
        if(book[num].first==num)
        {
            return book[num].second;
        }
        else
        {
            return "not found";
        }
    }
};

int main()
{
    PhoneBook PB(10000000);
    int n,number;
    string name,query;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> query;
        if(query=="add")
        {
            cin >> number >> name;
            PB.addN(number,name);
        }
        else if(query=="del")
        {
            cin >> number;
            PB.deleteN(number);
        }
        else if(query=="find")
        {
            cin >> number;
            cout << PB.findN(number) <<endl;
        }
    }
}
