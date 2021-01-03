#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<stdlib.h>
#include<conio.h>
#include<cstdlib>

using namespace std;

string prefixToInfix(string prefix)
{
    stack<string> s;
    for(int i=prefix.length()-1;i>=0;i--)
    {
        if(prefix[i]!='+' &&  prefix[i]!='-' && prefix[i]!='*' && prefix[i]!='/' && prefix[i]!='^')
        {
            string ope(1,prefix[i]);
            s.push(ope);
        }
        else if(prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/' || prefix[i]=='^')
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("("+op1+prefix[i]+op2+")");
        }
    }
    return s.top();
}

int main()
{
   string prefix;
   cout << "Prefix Expression : ";
   cin >> prefix;
   cout << "\nInfix Expression : "<<prefixToInfix(prefix)<<endl;
}
