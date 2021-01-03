#include<iostream>
#include<string>
#include<cmath>
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
    string infixToPostfix(string infix)
    {
        string postfix="";
        for(int i=0;i<infix.length();i++)
        {
            if(infix[i]!='+' && infix[i]!='-' && infix[i]!='*' && infix[i]!='/' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')')
            {
                postfix = postfix + infix[i];
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
                        postfix = postfix+s[top];
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
                        push(infix[i]);
                    }
                    else
                    {
                        while(top!=-1 && precedence(infix[i])<=precedence(s[top])&& s[top]!='(')
                        {
                            postfix = postfix+s[top];
                            pop();
                        }
                        push(infix[i]);
                    }

                }

            }
        }
        while(top!=-1 && s[top]!='(')
        {
            postfix+= s[top];
            pop();
        }
        return postfix;
    }
};

int main()
{
    string infix;
    Stack s1;
    cout << "\nInfix Expression : ";
    cin >> infix;
    cout << "\nPostfix Expression : "<<s1.infixToPostfix(infix)<<endl;
}
