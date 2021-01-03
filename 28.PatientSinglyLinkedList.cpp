#include<iostream>
#include<string>
#include<math.h>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>
#include<fstream>

using namespace std;

int i = 1;

class Date
{
public :
     int day;
     int month;
     int year;

    Date()
    {
        day = 0;
        month = 0;;
        year = 0;
    }
    Date(int d,int m,int y)
    {
        day = d;
        month = m;
        year = y;
    }
 friend class SLL;
};

class Patient
{
public :
     int id;
     string name;
     int age;
     Date d;
     Patient* next;

    Patient() : id(0), name("None"), age(0){}
    Patient(int i,string n,int a,Date D)
    {
        id = i;
        name = n;
        age = a;
        d = D;
        next = NULL;
    }
    friend class SLL;
};

class SLL
{
private :
    Patient *head;
public :
    SLL() : head(NULL){}
    SLL(Patient *h) : head(h) {}

    void addRecord(Patient *s)
    {
        if(head==NULL)
        {
            head = s;
            cout << "\nAdded"<<endl;
            i++;
        }
        else
        {
            Patient* ptr = head;
            Patient* temp = NULL;
            while(ptr!=NULL)
            {
                if(ptr->next==NULL)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            temp->next = s;
            cout << "\nAdded"<<endl;
            i++;
        }
    }
    void removeRecord()
    {
        if(head==NULL)
        {
            cout << "\nAlready Empty"<<endl;
        }
        else
        {
            if(head->next==NULL)
            {
                head = NULL;
                cout << "\nRemoved"<<endl;
                i--;
            }
            else
            {
                Patient *prevptr = NULL;
                Patient *currptr = NULL;
                Patient *ptr = head;
                while(ptr!=NULL)
                {
                    if(ptr->next==NULL)
                    {
                        currptr = ptr;
                    }
                    ptr = ptr->next;
                }
                ptr = head;
                while(ptr!=currptr)
                {
                    if(ptr->next==currptr)
                    {
                        prevptr = ptr;
                    }
                    ptr = ptr->next;
                }
                prevptr->next = NULL;
                cout << "\nRemoved"<<endl;
                i--;
            }
        }
    }
    void printRecord()
    {
        if(head==NULL)
        {
            cout << "\nEmpty"<<endl;
        }
        else
        {
            Patient *ptr = head;
            cout << "\nID       NAME       AGE       DATE OF ADMISSION\n";
            cout << "-----------------------------------------------\n";
            while(ptr!=NULL)
            {
                cout << ptr->id <<"        "<< ptr->name << "       "<<ptr->age<<"       "<<ptr->d.day<<"/"<<ptr->d.month<<"/"<<ptr->d.year<<endl;
                ptr = ptr->next;
            }
        }
    }
};

int main()
{
    int option,a,dd,dm,dy;
    string n;
    SLL s;
    do
    {
        cout << "\n1. Add"<<endl;
        cout << "2. Remove"<<endl;
        cout << "3. Print"<<endl;
        cout << "4. Clear Screen"<<endl;

        cout << "\nEnter option : ";
        cin >> option;
        Date D;
        Patient* P = new Patient();

        switch(option)
        {
        case 1 :
            cout << "\nEnter Name : "; cin >> n;
            cout << "Enter Age : "; cin >> a;
            cout << "Enter Date : "; cin >> dd >> dm >> dy;
            D.day = dd;
            D.month = dm;
            D.year = dy;
            P->id = i;
            P->name = n;
            P->age = a;
            P->d = D;
            s.addRecord(P);
            break;
        case 2 :
            s.removeRecord();
            break;
        case 3 :
            s.printRecord();
            break;
        case 4 :
            system("cls");
            break;
        default :
            cout << "\nInvalid Choice"<<endl;
            break;
        }
    }
    while(option!=0);
}
