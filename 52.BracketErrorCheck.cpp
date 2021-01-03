#include <bits/stdc++.h>
using namespace std;

void errorCheck(string text)
{
    stack<char> openB;
    int counter = 1;
    vector<int> position;
    for(int i=0;i<text.length();i++)
    {
        char next = text[i];
        if(next=='(' || next=='[' || next=='{')
        {
            openB.push(next);
            counter++;
            position.push_back(counter);
        }
        else if(next==')' || next==']' || next=='}')
        {
            if(openB.empty())
            {
                cout << counter;
                return;
            }
            char top = openB.top();
            if(next==')' && top=='(' || next==']' && top=='[' || next=='}' && top=='{')
            {
                openB.pop();
                counter++;
                position.pop_back();
            }
            else
            {
                cout << counter;
                return;
            }
        }
        else
        {
            counter++;
        }
    }
    if(!openB.empty())
    {
        cout << position[0]-1;
        return;
    }
    cout << "Success" << endl;
}

int main()
{
    string text;
    cin >> text;
    errorCheck(text);
}
