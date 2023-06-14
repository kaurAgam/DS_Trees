#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define COUNT 10 // for print

class Node{
    public:
    int data;
    Node *left, *right;
};

Node* insert(Node* node,int val){
    if(node==NULL){
        Node* newnode=new Node();
        newnode->data=val;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if(val <= node->data){
        node->left=insert(node->left,val);
    }
    if(val > node->data){
        node->right=insert(node->right,val);
    }
    return node;
}
void search(Node* root,int val){

    if(root==NULL){
        cout<<val<<" NOT found! X"<<endl;
        return;}

    else if(root->data==val){
        cout<<val<<" FOUND! \xfb "<<endl;
        return;}

    else if(val<=root->data){
        return search(root->left,val);}

    else if(val>root->data){
        return search(root->right,val);}

}
void print2DUtil(Node* root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";

    cout << root->data << "\n";
    print2DUtil(root->left, space);
}
 
void print2D(Node* root)
{
    print2DUtil(root, 0);
}

int findmin(Node* root){
    if(root->left==NULL){
        return root->data; }
    else{
        return findmin(root->left);}
}

int findmax(Node* root){
    if(root->right==NULL){
        return root->data; }
    else{
        return findmax(root->right);}
}

int findh(Node* root,int h){
    if(root==NULL){
        return h;
    }
    h++;
    int a=findh(root->left,h);
    int b=findh(root->right,h);
    if(a>=b){
        return a;
    }
    else{
        return b;
    }   
}

void findheight(Node* root){
    cout<<"Height of BST is:"<<findh(root,-1)<<endl;
}

int main() {
    Node* root=NULL;
    root=insert(root,34);
    root=insert(root,19);
    root=insert(root,76);
    root=insert(root,60);
    root=insert(root,69);
    root=insert(root,4);
    root=insert(root,9);
    root=insert(root,78);
    root=insert(root,97);
    root=insert(root,70);
    root=insert(root,80);
    root=insert(root,89);
    print2D(root);

    search(root,12);
    search(root,9);
    cout<<"Max: "<< findmax(root)<<endl;
    cout<<"Min: "<< findmin(root)<<endl;
    findheight(root);


return 0;
}


/*
                              97

                                                  89

                                        80

                    78

          76

                                        70

                              69

                    60

34

          19

                              9

                    4
12 NOT found! X
9 FOUND! √
Max: 97
Min: 4
Height of BST is:5

*/