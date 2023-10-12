#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#define PI 3.14
using namespace std;
//Binary Search Tree by using object oriented programming
/*
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
    private:
        node* root;
        void inOrderTraverse(node*);
        void preOrderTraverse(node*);
        void postOrderTraverse(node*);
    public:
        BST();
        BST(BST&);
        BST& operator=(BST);
        bool isEmpty();
        void inorder();
        void preorder();
        void postorder();
        void insert(int);
        node*search(int);
        void deleteNode(int);
        void rootNode();
        void copyInorder(BST&,node*);
        ~BST();

};
BST::BST()
{
    root=NULL;
}
BST::BST(BST &A)
{
    node*t=A.root;
    root=NULL;
    if(A.root)
    {
        A.copyInorder(*this,A.root);
    }
}
BST& BST::operator=(BST A)
{
    while(root)
    {
        deleteNode(root->item);
    }
    root=NULL;
    if(A.root)
        A.copyInorder(*this,A.root);
    cout<<"Copy Assignment Operator"<<endl;
    return *this;
    
}
void BST::copyInorder(BST &B,node* root1)
{
    if(root1)
    {
        copyInorder(B,root1->left);
        B.insert(root1->item);
        copyInorder(B,root1->right);
    }
}
void BST::insert(int data)
{
    bool flag=true;
    node*t=root;
    node* n=new node();
    n->item=data;
    n->left=NULL;
    n->right=NULL;

    while(flag)
    {
        if(root==NULL)
        {
            root=n;
            flag=false;
        }
        else
        {
            if(t->item==data)
            {
                cout<<"Duplicate Value"<<endl;
                delete n;
                break;
            }
            if(t->item < n->item)
            {
                if(t->right==NULL)
                {
                    t->right=n;
                    flag=false;
                }
                else
                    t=t->right;
            }
            else
            {
                if(t->left==NULL)
                {
                    t->left=n;
                    flag=false;
                }
                else
                    t=t->left;
            }
        }
    }
}
void BST::inorder()
{
    inOrderTraverse(root);
}
void BST::inOrderTraverse(node* root1)
{
    if(root1)
    {
        inOrderTraverse(root1->left);
        cout<<root1->item<<"  ";
        inOrderTraverse(root1->right);
    }
}
bool BST::isEmpty()
{
    if(root)
        return false;
    return true;
}
void BST::preOrderTraverse(node* root1)
{
    if(root1)
    {
        cout<<root1->item<<"  ";
        preOrderTraverse(root1->left);
        preOrderTraverse(root1->right);
    }
}
void BST::preorder()
{
    preOrderTraverse(root);
}
void BST::postOrderTraverse(node* root1)
{
    if(root1)
    {
        postOrderTraverse(root1->left);
        postOrderTraverse(root1->right);
        cout<<root1->item<<"  ";
    }
}
void BST::postorder()
{
    postOrderTraverse(root);
}
void BST::deleteNode(int data)
{
    node*parptr=NULL;
    node*ptr=root;
    if(root==NULL)
    {
        cout<<"Can't delete anything "<<endl;
        throw 1;
    }
    else
    {
        while (ptr)
        {
            if(ptr->item==data)
                break;
            else if(ptr->item > data)
            {
                parptr=ptr;
                ptr=ptr->left;
            }
            else
            {
                parptr=ptr;
                ptr=ptr->right;
            }
        }
        if(ptr==NULL)
        {
            cout<<"Data didn't match"<<endl;
            throw 2;
        }
        else
        {
            if(ptr==root)       //when root to be deleted
            {
                if(ptr->left==NULL && ptr->right==NULL )
                {
                    delete ptr;
                    root=NULL;
                }
                else if(ptr->left && ptr->right) //two children 
                {
                    node*sec, *parsec;
                    sec=ptr->right;
                    parsec=ptr;
                    while(sec->left)
                    {
                        parsec=sec;
                        sec=sec->left;
                    }
                    ptr->item=sec->item;//exception
                    if(sec == parsec->left)
                        parsec->left=sec->right;
                    else
                        parsec->right=sec->right;
                    delete sec;
                }
                else                            //one child case
                {
                    if(ptr->left)
                        root=ptr->left;
                    else
                        root=ptr->right;
                    delete ptr;
                }
                
            }
            else 
            {
                if(ptr->left==NULL && ptr->right==NULL ) //when node doesn't have any child
                {
                    if(parptr->left==ptr)
                        parptr->left=NULL;
                    else
                        parptr->right=NULL;
                    delete ptr;
                }
                else if(ptr->left && ptr->right)        //when node has two children
                {
                    node*sec, *parsec;
                    sec=ptr->right;
                    parsec=NULL;
                    while(sec->left)
                    {
                        parsec=sec;
                        sec=sec->left;
                    }
                    ptr->item=sec->item;
                    parsec->left=sec->right;
                    delete sec;
                }
                else                                //when node has only one child
                {
                    if(parptr->left==ptr)
                    {
                        if(ptr->left)
                            parptr->left=ptr->left;
                        else
                            parptr->left=ptr->right;
                        delete ptr;
                    }
                    else
                    {
                        if(ptr->left)
                            parptr->right=ptr->left;
                        else
                            parptr->right=ptr->right;
                        delete ptr;
                    }
                }
            }
        }
    }
}
node* BST::search(int data)
{
    node*t=root;
    while(t)
    {
        if(t->item==data)
            return t;
        else if(t->item < data)
            t=t->right;
        else
            t=t->left;
    }
    return NULL;
}
void BST::rootNode()
{
    cout<<"root node is "<<root->item<<"  ";
}
BST::~BST()
{
    while(root)
    {
        deleteNode(root->item);
    }
}
int main()
{
    BST A;
    A.insert(50);
    A.insert(40);
    A.insert(60);
    A.insert(39);
    A.insert(45);
    A.insert(55);
    BST B;
    B=A;
    // A.insert(65);
    // A.insert(64);
    // A.insert(63);
    // A.insert(62);
    // A.insert(61);
    // A.insert(38);
    // A.deleteNode(50);
    B.inorder();
    cout<<endl;
    A.inorder();
    return 0;
}
*/
//Binary Tree
class Node
{
    public:
        int item;
        Node* left;
        Node* right;
    Node(int d)
    {
        this->item=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* BuildTree(Node* root)
{
    cout<<"Enter the data for node "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1)
        return NULL;
    
    cout<<"Enter the value to insert left of "<<data<<endl;
    root->left=BuildTree(root->left);
    cout<<"Enter the value to insert right of "<<data<<endl;
    root->right=BuildTree(root->right);
    return root;

}
void levelorder(Node* root)
{
    queue<Node*>s;
    s.push(root);
    s.push(NULL);
    while(!s.empty())
    {
        Node*temp=s.front();
        s.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!s.empty())
                s.push(NULL);
        }
        else
        {
            cout<<temp->item<<"  ";
            if(temp->left!=NULL)
                s.push(temp->left);
            if(temp->right!=NULL)
                s.push(temp->right);
        }
    }
}
void inorder(Node* root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->item<<"  ";
        inorder(root->right);
    }
}
/*
// Binary Search Tree
Node* BuildBST(Node* root)
{
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1)
        return NULL;
    Node*temp=NULL;
    if(temp==NULL)
    {
        temp=root;
    }
    cout<<"Enter the value to insert left of "<<data<<endl;
        Node*t==BuildTree(root->left);
    if(temp->item < t->item)
    {
        cout<<"You entered wrong value \n Enter Again"<<endl;
        t==BuildTree(root->left);
    }
    else
        root->left=BuildTree(root->left);

    cout<<"Enter the value to insert right of "<<data<<endl;
    if(root->item > root->right->item)
    {
        cout<<"You entered wrong value \n Enter Again"<<endl;
        root->right=BuildTree(root->right);
    }
    else
        root->right=BuildTree(root->right);
}
*/
//Height of binary tree by using loop[level order traversal]
int TreeHeightL(Node*root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);Node*temp=NULL;int height=0;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();

        if(temp == NULL)
        {
            height++;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return height;
}
//Height of binary tree by using recursion
int TreeHeightR(Node*root)
{
    if(root == NULL)
        return 0;
    int left=TreeHeightR(root->left);
    int right=TreeHeightR(root->right);
    
    int ans = max (left,right) +1;
    return ans;
}

int main()
{
    Node* root=NULL;
    root=BuildTree(root);
    cout<<"Level order Tree : "<<endl;
    levelorder(root);
    cout<<"\nHeight is "<<TreeHeightR(root);
    return 0;
}