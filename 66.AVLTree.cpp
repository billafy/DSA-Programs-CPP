 #include<bits/stdc++.h>

using namespace std;

class Node
{
public :
    int value;
    int height;
    Node* left;
    Node* right;
};

Node* newNode(int v)
{
    Node* n = new Node();
    n->value = v;
    n->right =  NULL;
    n->left = NULL;
    n->height = 1;
    return(n);
}

int heightNode(Node* n)
{
    if(n==NULL)
        return 0;
    return n->height;
}

int getBalance(Node* n)
{
    if(n==NULL)
        return 0;
    return heightNode(n->left)-heightNode(n->right);
}

Node* leftRotate(Node* a)
{
    Node* b = a->right;
    Node* temp = b->left;

    b->left = a;
    a->right = temp;

    a->height = max(heightNode(a->left),heightNode(a->right))+1;
    b->height = max(heightNode(b->left),heightNode(b->right))+1;

    return b;
}

Node* rightRotate(Node* b)
{
    Node* a = b->left;
    Node* temp = a->right;

    a->right = b;
    b->left = temp;

    b->height = max(heightNode(b->left),heightNode(b->right))+1;
    a->height = max(heightNode(a->left),heightNode(a->right))+1;

    return a;
}

Node* insertNode(Node* root,int v)
{
    if(root==NULL)
    {
        return(newNode(v));
    }
    if(v<root->value)
    {
        root->left = insertNode(root->left,v);
    }
    else if(v>root->value)
    {
        root->right = insertNode(root->right,v);
    }
    else
    {
        return root;
    }
    root->height = 1 + max(heightNode(root->left),heightNode(root->right));

    int balance = getBalance(root);

    if(balance>1 && v<root->left->value) // left left case
        return rightRotate(root);
    if(balance<-1 && v>root->right->value) // right right case
        return leftRotate(root);
    if(balance>1 && v>root->left->value) // left right case
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && v<root->right->value) // right left case
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

Node* minValueNode(Node* root)
{
    Node* minV = root;
    while(minV && minV->left!=NULL)
    {
        minV = minV->left;
    }
    return minV;
}

Node* deleteNode(Node* root,int v)
{
    if(root==NULL)
        return root;
    if(v<root->value)
        root->left = deleteNode(root->left,v);
    else if(v>root->value)
        root->right = deleteNode(root->right,v);
    else
    {
        if(root->left==NULL)
        {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right,temp->value);
    }

    if(root==NULL)
        return root;

    root->height = 1 + max(heightNode(root->left),heightNode(root->right));

    int balance = getBalance(root);

    if(balance > 1 && getBalance(root->left)>=0) // left left
    {
        return rightRotate(root);
    }
    else if(balance < -1 && getBalance(root->right)<=0) // right right
    {
        return leftRotate(root);
    }
    else if(balance > 1 && getBalance(root->left)<0) // left right
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if(balance < -1 && getBalance(root->right)>0) // right left
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inOrder(Node* root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout <<root->value << " ";
    inOrder(root->right);
}

void preOrder(Node* root)
{
    if(root==NULL)
        return;
    cout <<root->value << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)
{
    if(root==NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout <<root->value << " ";
}

int main()
{
    cout << "AVL Tree"<<endl;
    Node* root = NULL;
    root = insertNode(root,1);
    root = insertNode(root,2);
    root = insertNode(root,3);
    root = insertNode(root,4);
    root = insertNode(root,8);
    root = insertNode(root,7);
    root = insertNode(root,6);
    root = insertNode(root,5);
    root = insertNode(root,11);
    root = insertNode(root,10);
    root = insertNode(root,12);

    cout << "Inorder Traversal : \n";
    inOrder(root);
    cout << "\nPreorder Traversal : \n";
    preOrder(root);
}
