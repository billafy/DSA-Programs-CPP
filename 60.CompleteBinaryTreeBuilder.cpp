#include <bits/stdc++.h>

using namespace std;

vector<int> convertTree(int key[],int left[],int right[],int n)
{
    vector<int> nodes;
    queue<int> nextN;
    queue<int> nextI;
    nextN.push(key[0]);
    nextI.push(0);
    while(!nextN.empty())
    {
        int n = nextN.front();
        int i = nextI.front();
        nodes.push_back(n);
        if(left[i]!=-1)
        {
            nextN.push(key[left[i]]);
            nextI.push(left[i]);
        }
        if(right[i]!=-1)
        {
            nextN.push(key[right[i]]);
            nextI.push(right[i]);
        }
        nextI.pop();
        nextN.pop();
    }
    return nodes;
}

void inorder(vector<int> nodes,int i)
{
    if(i>=nodes.size())
        return;
    inorder(nodes,(2*i)+1);
    cout << nodes[i] << " ";
    inorder(nodes,(2*i)+2);
}

void preorder(vector<int> nodes,int i)
{
    if(i>=nodes.size())
        return;
    cout << nodes[i] << " ";
    preorder(nodes,(2*i)+1);
    preorder(nodes,(2*i)+2);
}

void postorder(vector<int> nodes,int i)
{
    if(i>=nodes.size())
        return;
    postorder(nodes,(2*i)+1);
    postorder(nodes,(2*i)+2);
    cout << nodes[i] << " ";
}

int main()
{
    int n; // number of nodes
    cin >> n;
    int key[n],left[n],right[n];
    for(int i=0;i<n;i++)
    {
        cin >> key[i] >> left[i] >> right[i];
    }
    vector<int> nodes = convertTree(key,left,right,n);
    cout << endl;
    inorder(nodes,0);
    cout << endl;
    preorder(nodes,0);
    cout << endl;
    postorder(nodes,0);
}

