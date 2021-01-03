#include<bits/stdc++.h>

using namespace std;

class Node
{
public :
    int value;
    Node* left;
    Node* right;
    bool leftThread,rightThread;

    Node(int v)
    {
        value = v;
        left = right = NULL;
        leftThread = rightThread = false;
    }
};

class ThreadedBinarySearchTree
{
public :
    Node* insertNode(Node* root,int v)
    {
        Node* ptr = root;
        Node* parent = NULL;
        while(ptr)
        {
            if(ptr->value == v)
            {
                cout << "Duplicate Key" << endl;
                return root;
            }
            parent = ptr;
            if(v < ptr->value)
            {
                if(ptr->leftThread == false)
                    ptr = ptr->left;
                else
                    break;
            }
            else
            {
                if(ptr->rightThread == false)
                    ptr = ptr->right;
                else
                    break;
            }
        }
        Node* temp = new Node(v);
        if(parent == NULL)
        {
            parent = temp;
        }
        else if(v < parent->value)
        {
            temp->left = parent->left;
            temp->right = parent;
            parent->leftThread = false;
            parent->left = temp;
        }
        else
        {
            temp->right = parent->right;
            temp->left = parent;
            parent->rightThread = false;
            parent->right = temp;
        }
        temp->leftThread = true;
        temp->rightThread = true;
        return root;
    }
    void inOrder(Node* root)
    {
        Node* cur = root;
        while(cur->left)
        {
            cur = cur->left;
        }
        while(cur)
        {
            cout << cur->value << ' ';
            cur = inorderSuccessor(cur);
        }
    }
    Node* inorderSuccessor(Node* ptr)
    {
        if(ptr->rightThread==true)
            return ptr->right;
        ptr = ptr->right;
        while(ptr->leftThread==false)
        {
            ptr = ptr->left;
        }
        return ptr;
    }
};

int main()
{
    Node* root = new Node(5);
    ThreadedBinarySearchTree* TBT = new ThreadedBinarySearchTree();
    root = TBT->insertNode(root,1);
    root = TBT->insertNode(root,4);
    root = TBT->insertNode(root,6);
    root = TBT->insertNode(root,7);
    root = TBT->insertNode(root,2);
    root = TBT->insertNode(root,3);
    TBT->inOrder(root);
}
