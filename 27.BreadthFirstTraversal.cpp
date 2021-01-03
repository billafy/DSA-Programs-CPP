#include<iostream>
#include<string>
#include<math.h>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Node
{
public :
    int value;
    Node *left,*right;

    Node() : value(0),left(NULL),right(NULL){}
    Node(int v) : value(v),left(NULL),right(NULL){}
};

void bfs(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node* r = q.front();
        cout << r->value << " ";
        q.pop();
        if(r->left!=NULL)
        {
            q.push(r->left);
        }
        if(r->right!=NULL)
        {
            q.push(r->right);
        }
    }
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->left->right = new Node(25);
    root->right->left = new Node(30);
    root->right->right = new Node(35);
    bfs(root);
}
