#include <bits/stdc++.h>

using namespace std;

class Node
{
public :
    int value;
    Node* left;
    Node* right;

    Node() : value(0),left(NULL),right(NULL) {}
    Node(int v) : value(v),left(NULL),right(NULL) {}
};

Node* insertNode(Node* root,int v)
{
    if(root==NULL)
    {
        Node* n = new Node(v);
        root = n;
    }
    else
    {
        if(root->value >= v)
        {
            root->left = insertNode(root->left,v);
        }
        else
        {
            root->right = insertNode(root->right,v);
        }
    }
    return root;
}

int heightTree(Node* root)
{
    if(root==NULL)
        return 0;
    return 1+ max(heightTree(root->left),heightTree(root->right));
}

void inOrder(Node* root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}

int main()
{
    int n,v;
    cin >> n;
    cout << "\nEnter nodes : ";
    Node* root = NULL;
    for(int i=0;i<n;i++)
    {
        cin >> v;
        root = insertNode(root,v);
    }
    cout << "\nHeight of Tree : "<<heightTree(root) << endl;
}
