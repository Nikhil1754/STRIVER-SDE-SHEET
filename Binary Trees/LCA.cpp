#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node *left,*right;
  Node(int x){
    data=x;
    left=right=NULL;
  }
};
Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(root==NULL || root->data==n1 || root->data==n2){
           return root;
       }
       Node* left=lca(root->left,n1,n2);
       Node* right=lca(root->right,n1,n2);
       if(left==NULL) return right;
       else if(right==NULL) return left;
       else return root;
    }



int main() 
{
  Node *root=new Node(1);
  root->left= new Node(2);
  root->right=new Node(3);
  root->left->left=new Node(4);
  root->left->right=new Node(5);
  root->right->left=new Node(6);
  root->right->right=new Node(7);
  Node* n=lca(root,4,7);
  cout<<"lca is=>"<<n->data<<endl;
  
  
   return 0;
}