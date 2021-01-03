#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Stack
{
private :
    int arr[5]; // array which basically stores the stack elements
    int top; // holds the value of topmost element

public :
    Stack()
    {
        top = -1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0; // all the stack values are initialized by 0 using default constructor
        }
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
        if(top==4)
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
    int peek(int pos)
    {
        if(isEmpty())
        {
            cout << "\nStack Underflow"<<endl;
        }
        else
        {
            return (arr[pos]);
        }
    }
    void change(int val, int pos)
    {
        arr[pos]=val;
        cout << "\nItem changed at position : "<<pos<<endl;
    }
    void display()
    {
        for(int i=4;i>=0;i--)
        {
            cout << "\n"<<arr[i]<<endl;
        }
    }
};

int main()
{
    Stack s1;
    int option, position, value;
    do
    {
      cout << "\nWhat operation do you want to perform?"<<endl; // Menu for stack operations
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
      case 1 : // Separate case for each operation using SCD
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
          cout << "\nThe value at position "<<position<<" is "<<s1.peek(position)<<endl;
          break;
      case 7 :
          cout << "\nNumber of items in the stack are : "<<s1.count()<<endl;
          break;
      case 8 :
          cout << "\nStack : "<<endl;
          s1.display();
          break;
      case 9 :
          system("cls"); // Clears the screen
          break;
      default :
          cout << "\nInvalid choice"<<endl;
          break;
      }
    }
    while(option!=0); // when you select the option as 0, the program will end
    return 0;
}
