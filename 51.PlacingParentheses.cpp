#include<bits/stdc++.h>

using namespace std;

int calc(int a,int b,char o)
{
    if(o=='+')
        return a+b;
    else if(o=='-')
        return a-b;
    else
        return a*b;
}

int minAndMax(vector<vector<char>> m,vector<vector<char>> M,int i,int j,vector<char> operators)
{
    int min_Val = -10000;
    int max_Val = 10000;
    for(int k=i;k<=j;k++)
    {
        int a = calc(M[i][k],M[k+1][j],operators[k]);
        int b = calc(M[i][k],m[k+1][j],operators[k]);
        int c = calc(m[i][k],M[k+1][j],operators[k]);
        int d = calc(m[i][k],m[k+1][j],operators[k]);

        int e = min(a,b);
        int f = min(c,d);
        int g = max(a,b);
        int h = max(c,d);
        min_Val = min(e,f);
        max_Val = min(g,h);
    }
    return min_Val,max_Val;
}

int parentheses(vector<char> operators,vector<char> operands)
{
    int sz = operands.size();
    vector<vector<char>> m(sz);
    vector<vector<char>> M(sz);
    for(int i=0;i<sz;i++)
    {
        for(int j=0;i<sz;j++)
        {
            m[i][j] = 0;
            M[i][j] = 0;
        }
    }
    for(int i=0;i<sz;i++)
    {
        m[i][i] = operands[i];
        M[i][i] = operands[i];
    }
    for(int s=1;s<sz;s++)
    {
        for(int i=1;i<=sz-s;i++)
        {
            int j = i+s;
            m[i][j],M[i][j] = minAndMax(m,M,i,j,operators);
        }
    }
    return M[0][sz-1];
}

int main()
{
    string expression;
    cin >> expression;
    vector<char> operators;
    vector<char> operands;
    for(int i=0;i<expression.length();i++)
    {
        if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
        {
            operators.push_back(expression[i]);
        }
        else
        {
            operands.push_back(expression[i]);
        }
    }
    cout << parentheses(operators,operands) <<endl;
}
