#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Node
{
public :
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node* n)
{
    if(n==NULL)
    {
        return;
    }
    inOrder(n->left);
    cout << ""<<n->data<<"->";
    inOrder(n->right);
}

void preOrder(Node* n)
{
    if(n==NULL)
    {
        return;
    }
    cout << ""<<n->data<<"->";
    preOrder(n->left);
    preOrder(n->right);
}

void postOrder(Node* n)
{
    if(n==NULL)
    {
        return;
    }
    postOrder(n->left);
    postOrder(n->right);
    cout <<""<<n->data<<"->";
}

int main()
{
  cout << "Tree Traversal"<<endl;
  Node* n = new Node(5);
  n->left = new Node(4);
  n->right = new Node(3);
  n->left->left = new Node(2);
  n->left->right = new Node(1);
  cout << "\nPreorder : "<<endl;
  preOrder(n);
  cout << "\n\nInorder : "<<endl;
  inOrder(n);
  cout << "\n\nPostorder : "<<endl;
  postOrder(n);
  cout << endl;
}
