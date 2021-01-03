#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>

using namespace std;

class Node // a single tree node which has a integer value, and two pointers left and right
{
public :
    int value;
    Node* left;
    Node* right;

    Node() : value(0), left(NULL), right(NULL) {}
    Node(int v) : value(v), left(NULL), right(NULL) {}
};

class BST
{
public :
    BST() {}

    Node* insertNode(Node* r,int v)
    {
        if(r==NULL) // if the root is NULL, attach the node to the root
        {
            Node* n = new Node(v);
            r = n;
            cout << "\nRoot inserted"<<endl;
        }
        else
        {
            if(v <= r->value) // go to left if passed value is lesser than r's value
            {
                r->left = insertNode(r->left,v);
            }
            else // go to right if passed value is greater than r's value
            {
                r->right = insertNode(r->right,v);
            }
        }
        return r;
    }
    void preOrder(Node* r)
    {
        if(r==NULL)
        {
            return;
        }
          cout << r->value << " ";
          preOrder(r->left);
          preOrder(r->right);
    }
    void inOrder(Node* r)
    {
        if(r==NULL)
        {
            return;
        }
        inOrder(r->left);
        cout << r->value << " ";
        inOrder(r->right);
    }
    void postOrder(Node* r)
    {
        if(r==NULL)
        {
            return;
        }
        postOrder(r->left);
        postOrder(r->right);
        cout << r->value << " ";
    }
    bool searchNode(Node* r, int v)
    {
        if(r==NULL) // if no node is present, return false
        {
            return false;
        }
        if(r->value == v) // if r value is equal to passed value, return true
        {
            return true;
        }
        else
        {
            if(v <= r->value)
            {
                searchNode(r->left,v); // if less, recurse to left
            }
            else
            {
                searchNode(r->right,v); // if right, recurse to right
            }
        }
        return false; // if value is not found, return false
    }
    Node* deleteNode(Node* r,int v)
    {
        if(r==NULL) // if no node is present, return r
        {
            return r;
        }
        if(v<r->value) // if passed value is less than node value, recurse to left
        {
            r->left = deleteNode(r->left,v);
        }
        else if(v>r->value) // if passed value is greater than node value, recurse to right
        {
            r->right = deleteNode(r->right,v);
        }
        else
        {
            if(r->left == NULL) // if only one child or no child is present
            {
                Node* temp = r->right;
                free(r); // free keyword frees the memory
                cout << "\nDeleted"<<endl;
                return temp;
            }
            else if(r->right==NULL)
            {
                Node* temp = r->left;
                free(r);
                cout << "\nDeleted"<<endl;
                return temp;
            }
            // if the node to be deleted has two children
            Node *temp = minimumValue(r->right); // find the minimum value and store it in a temporary node
            r->value = temp->value; // copy the temporary value in the node's value
            r->right = deleteNode(r->right,temp->value); // recurse to the right with temporary value
        }
        return r;
    }
    Node* minimumValue(Node* r) // returns the node with minimum value
    {
        Node* minV = r;
        while(minV && minV->left!=NULL)
        {
            minV = minV->left;
        }
        return minV;
    }
    int minimumValue(Node* r,int x) // returns the minimum value
    {
        Node* minV = r;
        while(minV && minV->left!=NULL)
        {
            minV= minV->left;
        }
        return minV->value;
    }
    int maximumValue(Node* r) // returns the maximum value
    {
        Node* maxV = r;
        while(maxV && maxV->right!=NULL)
        {
            maxV = maxV->right;
        }
        return maxV->value;
    }
    void BFS(Node* r) // breadth first traversal
    {
        if(r==NULL) // return when the node becomes NULL
        {
            return;
        }
        queue<Node *> Q; // declare a queue
        Q.push(r); // push node value in left
        while(!Q.empty()) // while queue is not empty, keep running
        {
          Node* n = Q.front(); // node n will take the value of queue's front element
          cout << n->value << " "; // print node n value
          Q.pop(); // pop it from queue
          if(n->left!=NULL) // if n's left is not null, push it's left into the queue
          {
              Q.push(n->left);
          }
          if(n->right!=NULL) // if n's right is not NULL, push it's right into the queue
          {
              Q.push(n->right);
          }
        }
        cout << endl;
    }
};

int main()
{
    BST *B = new BST();
    Node* root = NULL;
    cout << "Binary Search Tree"<<endl;
    int option,v;
    do
    {
        cout << "\n1. Insert"<<endl;
        cout << "2. Inorder"<<endl;
        cout << "3. Preorder"<<endl;
        cout << "4. Postorder"<<endl;
        cout << "5. Search"<<endl;
        cout << "6. Delete"<<endl;
        cout << "7. Minimum Value"<<endl;
        cout << "8. Maximum Value"<<endl;
        cout << "9. BFS"<<endl;
        cout << "10. Clear Screen"<<endl;

        cout << "\nEnter option : ";
        cin >> option;

        switch(option)
        {
        case 1 :
            cout << "\nValue to insert : ";
            cin >> v;
            root = B->insertNode(root,v);
            break;
        case 2 :
            cout << "\nInorder Traversal : \n";
            B->inOrder(root);
            cout << endl;
            break;
        case 3 :
            cout << "\nPreorder Traversal : "<<endl;
            B->preOrder(root);
            cout << endl;
            break;
        case 4 :
            cout << "\nPostorder Traversal : "<<endl;
            B->postOrder(root);
            cout << endl;
            break;
        case 5 :
            cout << "Value to search : ";
            cin >> v;
            if(B->searchNode(root,v))
            {
                cout << "\nPresent"<<endl;
            }
            else
            {
                cout << "\nNot Present"<<endl;
            }
            break;
        case 6 :
            cout << "\nValue to Delete : ";
            cin >> v;
            root = B->deleteNode(root,v);
            break;
        case 7 :
            cout << "\nSmallest value : "<<B->minimumValue(root,1)<<endl;
            break;
        case 8 :
            cout << "\nLargest value : "<<B->maximumValue(root)<<endl;
            break;
        case 9 :
            cout << "\nBreadth-First Traversal : \n";
            B->BFS(root);
            break;
        case 10 :
            system("cls");
            break;
        default :
            cout << "\nInvalid choice"<<endl;
            break;
        }
    }
    while(option!=0);
}

