#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Node
{
public :
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(NULL), right(NULL) {}
};

Node* insertNode(Node *root,int value)
{
    if(root==NULL)
    {
        Node* n = new Node(value);
        root = n;
        cout << "\nInserted "<<value<<endl;
    }
    else
    {
        if(root->left==NULL)
        {
            root->left = insertNode(root->left,value);
        }
        else
        {
            root->right = insertNode(root->right,value);
        }
    }
    return root;
}

void inOrder(Node* root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout << root->value <<" ";
    inOrder(root->right);
}

void BFS(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node* n = Q.front();
        cout << n->value << " ";
        Q.pop();
        if(n->left!=NULL)
        {
            Q.push(n->left);
        }
        if(n->right!=NULL)
        {
            Q.push(n->right);
        }
    }
}

Node* deleteNode(Node* root,int v)
{
    Node* n = NULL;
    if(root==NULL)
    {
        return root;
    }
    if(root->left!=NULL)
    {
        root->left = deleteNode(root->left,v);
    }
    else if(root->right!=NULL)
    {
        root->right = deleteNode(root->right,v);
    }
    else
    {
        if(root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            cout << "\nDeleted"<<endl;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp = root->left;
            free(root);
            cout << "\nDeleted"<<endl;
            return temp;
        }
        Node* temp1 = root->left;
        Node* temp2 = root->right;
        free(root);
        cout << "\nDeleted"<<endl;
        return temp1;
    }
}

int main()
{
    cout << "Yash"<<endl;
    Node* root = NULL;
    cout << "Binary Tree"<<endl;
    root = insertNode(root,5);
    root = insertNode(root,10);
    root = insertNode(root,15);
    root = insertNode(root,20);
    root = insertNode(root,25);
    inOrder(root);
    cout << endl;
    root = deleteNode(root,15);
    BFS(root);
}
