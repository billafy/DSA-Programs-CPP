#include<iostream>
#include<string>
#include<cmath>
#include <bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>
#include<cstdlib>

using namespace std;

class Stack
{
public :
    string s;
    int top;

    Stack()
    {
        s = "";
        top = -1;
    }

    int precedence(char a)
    {
        if(a=='+' || a=='-')
        {
            return 1;
        }
        else if(a=='*' || a=='/')
        {
            return 2;
        }
        else if(a=='^')
        {
            return 3;
        }
    }
    void push(char a)
    {
        s = s+a;
        top++;
    }
    char pop()
    {
        char a = s[top];
        s.erase(top);
        top--;
        return a;
    }
    string infixToPrefix(string infix)
    {
        string prefix="";
        for(int i=0;i<infix.length();i++)
        {
            if(infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')')
            {
                prefix = prefix + infix[i];
            }
            else if(infix[i]=='(')
            {
                push(infix[i]);
            }
            else if(infix[i]==')')
            {
                for(int j=top;j>=0;j--)
                {
                    if(s[top]!='(')
                    {
                        prefix = prefix+s[top];
                        pop();
                    }
                    else
                    {
                        pop();
                    }
                }
            }
            else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='^')
            {
                if(top==-1)
                {
                    push(infix[i]);
                }
                else if(top!=-1)
                {
                    if(precedence(infix[i])>precedence(s[top]))
                    {
                        push(infix[i]);
                    }
                    else if(precedence(infix[i])==precedence(s[top]) && infix[i]=='^')
                    {
                        while(precedence(infix[i])==precedence(s[top]))
                        {
                            prefix = prefix + s[top];
                            pop();
                        }
                        push(infix[i]);
                    }
                    else if(precedence(infix[i])==precedence(s[top]))
                    {
                        push(infix[i]);
                    }
                    else if(precedence(infix[i])<precedence(s[top]))
                    {
                        while(top!=-1 && precedence(infix[i])<=precedence(s[top])&& s[top]!='(')
                        {
                            prefix = prefix+s[top];
                            pop();
                        }
                        push(infix[i]);
                    }

                }

            }
        }
        while(top!=-1 && s[top]!='(')
        {
            prefix+= s[top];
            pop();
        }
        reverse(prefix.begin(),prefix.end());
        return prefix;
    }
    string reverseString(string a)
    {
       for(int i=0;i<a.length();i++)
       {
          for(int j=i+1;j<a.length();j++)
          {
              if(a[i]=='(' && a[j]==')')
              {
                  swap(a[i],a[j]);
              }
          }
       }
    reverse(a.begin(),a.end());
    return a;
    }

};

int main()
{
    string infix;
    Stack s1;
    cout << "\nInfix Expression : ";
    cin >> infix;
    string a = s1.reverseString(infix);
    cout << "\nPrefix Expression : "<<s1.infixToPrefix(a)<<endl;
}
