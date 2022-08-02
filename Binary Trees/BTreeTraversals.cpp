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

void levelOrder(Node *root){
  queue<Node*>q;
  q.push(root);
  while(!q.empty()){
    int s=q.size();
    for(int i=0;i<s;i++){
      Node* nw=q.front();
      q.pop();
      if(nw->left!=NULL) q.push(nw->left);
      if(nw->right!=NULL) q.push(nw->right);
      cout<<nw->data<<" ";
    }
  }
}

void inorder(Node *root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
void preorder(Node *root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  inorder(root->left);
  inorder(root->right);
}
void postorder(Node *root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  inorder(root->right);
  cout<<root->data<<" ";
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
  inorder(root);
  cout<<endl;
  preorder(root);
  cout<<endl;
  postorder(root);
  cout<<endl;
  cout<<"level order"<<endl;
  levelOrder(root);
  cout<<endl;
   return 0;
}