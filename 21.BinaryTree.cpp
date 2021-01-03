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
    Node* left;
    Node* right;

    Node() : value(0),left(NULL),right(NULL){}
    Node(int v) : value(v),left(NULL),right(NULL){}
};

class Tree
{
public :
    Node* root;

    Tree() : root(NULL){};
    Tree(Node* r) : root(r){};

    Node* addNode(int v)
    {
        if(root==NULL)
        {
            Node* r = new Node();
            r->value = v;
            r->left = NULL;
            r->right = NULL;
            cout << "Node Added"<<endl;
            return r;
        }
        else
        {
            if(root->left == NULL)
            {
                addNode(root->left);
            }
            else if(root->right == NULL)
            {
                addNode(root->right);
            }
        }
    }
    void inorder(Node* r)
    {
        inorder(r->left);
        cout << r->value << " "<<endl;
        inorder(r->right);
    }
};

int main()
{
    Tree t;
    int option,val;
    do
    {
        cout << "\n1. Add"<<endl;
        cout << "2. Print"<<endl;
        cout << "3. Clear Screen" <<endl;
        cout << "\nEnter option : ";
        cin >> option;
        switch(option)
        {
        case 1 :
            cout << "\nEnter value to add : ";
            cin >> val;
            t.addNode(val);
            break;
        case 2 :
           // cout << "\nInorder Traversal : "<<endl;
          //  t.inorder();
            break;
        case 3 :
            system("cls");
            break;
        default :
            cout << "\nInvalid Choice"<<endl;
            break;
        }
    }
    while(option!=0);
}
