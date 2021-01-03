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
    string fruit;
    Node* left;
    Node* right;

    Node() : fruit(""),left(NULL),right(NULL) {}
    Node(string f)
    {
        fruit = f;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* r)
{
    if(r==NULL)
        return;

    inorder(r->left);
    cout << r->fruit << " ";
    inorder(r->right);
}

void preorder(Node* r)
{
    if(r==NULL)
        return;

    cout << r->fruit << " ";
    inorder(r->left);
    inorder(r->right);
}

void postorder(Node* r)
{
    if(r==NULL)
        return;

    inorder(r->left);
    inorder(r->right);
    cout << r->fruit << " ";
}

int main()
{
  Node* root = new Node("Cherry");
  root->left = new Node("Banana");
  root->right = new Node("Fig");
  root->left->left = new Node("Apple");
  root->right->left = new Node("Date");
  root->right->right = new Node("Grape");
  root->right->right->right = new Node("Honeydew");

  cout << "Inorder Traversal : "; inorder(root);
  cout << endl;
  cout << "Postorder Traversal : "; postorder(root);
  cout << endl;
  cout << "Preorder Traversal : "; preorder(root);
  cout << endl;
  delete root;
}
