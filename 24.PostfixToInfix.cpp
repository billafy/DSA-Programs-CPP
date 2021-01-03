#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>
#include<cstdlib>

using namespace std;

string postfixToInfix(string postfix)
{
    stack<string> s;
    string infix;
    for(int i=0;i<postfix.length();i++)
    {
        if(postfix[i]!='+' &&  postfix[i]!='-' && postfix[i]!='*' && postfix[i]!='/' && postfix[i]!='^')
        {
            string ope(1,postfix[i]);
            s.push(ope);
        }
        else if(postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='*' || postfix[i]=='/' || postfix[i]=='^')
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("("+op2+postfix[i]+op1+")");
        }
    }
    return s.top();
}

int main()
{
   string postfix;
   cout << "Postfix Expression : ";
   cin >> postfix;
   cout << "\nInfix Expression : "<<postfixToInfix(postfix)<<endl;
}
