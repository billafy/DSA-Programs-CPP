#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Stack
{
private :
    int *arr;
    int top;
    int asize;
public :
    Stack(int *x,int n) // pointer array as an argument
    {
        asize = n;
        arr = new int(asize); // class pointer (dynamic memory allocation)
        for(int i=0;i<asize;i++)
        {
            arr[i]=x[i]; // values shared
        }
        top = -1; // top initialized to -1
    }
    bool isEmpty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if(top==asize-1)
            return true;
        else
            return false;
    }
    void push(int val)
    {
        if(isFull())
        {
            cout << "\nStack Overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]= val;
        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout << "\nStack Underflow"<<endl;
            return 0;
        }
        else
        {
            int popValue = arr[top];
            arr[top]=0;
            top--;
            return popValue;
        }
    }
    int count()
    {
        return (top+1);
    }
    void peek(int pos)
    {
        if(pos>=asize)
        {
            cout << "\nInvalid Position"<<endl;
        }
        else
        {
            if(isEmpty())
            {
              cout << "\nStack Underflow"<<endl;
            }
            else
            cout << "\nThe value at position "<<pos<<" is "<<arr[pos]<<endl;
        }
    }
    void change(int val, int pos)
    {
        for(int i=pos+1;i<=asize-1;i++)
        {
            pop();
        }
        if(pos==top+1)
          {arr[pos]=val;
          cout << "\nItem changed at position : "<<pos<<endl;}
        else
          {cout << "\nThe value cannot be changed there"<<endl;}
    }
    void display()
    {
        cout << "\n";
        for(int i=asize-1;i>=0;i--)
        {
            cout << arr[i]<<endl;
        }

    }
};

int main()
{
    int n;
    int *ptr; // pointer variable created which will later become a stack(array)
    cout << "Stack"<<endl;
    cout << "\nEnter the size of stack : "<<endl;
    cin >> n;
    ptr = new int(n); // conversion of pointer to array (dynamic memory allocation)
    for(int i=0;i<n;i++)
    {
        ptr[i] = 0; // all values of array initialized to 0
    }
    Stack s1(ptr,n); // pointer array and size of array passed to the parameterized constructor
    int option, position, value;
    do
    {
      cout << "\nWhat operation do you want to perform?"<<endl;
      cout << "1. Push"<<endl;
      cout << "2. Pop"<<endl;
      cout << "3. Is Empty?"<<endl;
      cout << "4. Is Full?"<<endl;
      cout << "5. Change"<<endl;
      cout << "6. Peek"<<endl;
      cout << "7. Count"<<endl;
      cout << "8. Display"<<endl;
      cout << "9. Clear Screen"<<endl;

      cout << "\nSelect the option from the above menu : "<<endl;
      cin >> option;
      switch(option)
      {
      case 1 :
          cout << "\nEnter the value you want to push : "<<endl;
          cin >> value;
          s1.push(value);
          break;
      case 2 :
          cout << "\nThe popped value is : "<<s1.pop()<<endl;
          break;
      case 3 :
          if(s1.isEmpty())
            cout << "\nStack is Empty"<<endl;
          else
            cout << "\nStack is not Empty"<<endl;
          break;
      case 4 :
          if(s1.isFull())
            cout << "\nStack is Full"<<endl;
          else
            cout << "\nStack is not Full"<<endl;
          break;
      case 5 :
          cout << "\nEnter the value you want to change : "<<endl;
          cin >> value;
          cout << "\nAt what position : "<<endl;
          cin >> position;
          s1.change(value,position);
          break;
      case 6 :
          cout << "\nAt what position do you want to peek : "<<endl;
          cin >> position;
          s1.peek(position);
          break;
      case 7 :
          cout << "\nNumber of items in the stack are : "<<s1.count()<<endl;
          break;
      case 8 :
          cout << "\nStack : "<<endl;
          s1.display();
          break;
      case 9 :
          system("cls");
          break;
      default :
          cout << "\nInvalid choice"<<endl;
          break;
      }
    }
    while(option!=0);
    return 0;
}
