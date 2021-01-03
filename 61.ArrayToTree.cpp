#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> convertTree(int key[],int left[],int right[],int n)
{
    vector<int> nodes;
    queue<int> nextN;
    queue<int> nextI;
    nextN.push(key[0]);
    nextI.push(0);
    int c = 0;
    while(!nextN.empty() || nextI.empty())
    {
        int a = nextN.front();
        int i = nextI.front();
        if(a!=-1)
            {++c;}
        nodes.push_back(a);
        if(left[i]!=-1)
        {
            nextN.push(key[left[i]]);
            nextI.push(left[i]);
        }
        else
        {
            nextN.push(key[n]);
            nextI.push(n);
        }
        if(right[i]!=-1)
        {
            nextN.push(key[right[i]]);
            nextI.push(right[i]);
        }
        else
        {
            nextN.push(key[n]);
            nextI.push(n);
        }
        nextI.pop();
        nextN.pop();
        if(c==n)
            break;
    }
    return nodes;
}

void inorder(vector<int> nodes,int i)
{
    if(i>=nodes.size())
        return;
    inorder(nodes,(2*i)+1);
    if(nodes[i]!=-1)
        cout << nodes[i] << " ";
    inorder(nodes,(2*i)+2);
}

void preorder(vector<int> nodes,int i)
{
    if(i>=nodes.size())
        return;
    if(nodes[i]!=-1)
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
    if(nodes[i]!=-1)
        cout << nodes[i] << " ";
}

int main()
{
    int n; // number of nodes
    cin >> n;
    int key[n+1],left[n+1],right[n+1];
    for(int i=0;i<n;i++)
    {
        cin >> key[i] >> left[i] >> right[i];
    }
    key[n] = -1;
    left[n] = -1;
    right[n] = -1;
    vector<int> nodes = convertTree(key,left,right,n);
    cout << endl;
    inorder(nodes,0);
    cout << endl;
    preorder(nodes,0);
    cout << endl;
    postorder(nodes,0);
}

