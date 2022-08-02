#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int x){
    data=x;
    left=right=NULL;
  }
};
void PreOrder(Node* root){
  stack<Node*>s;
  s.push(root);
  while(!s.empty()){
    Node* n=s.top();
    s.pop();
    cout<<n->data<<" ";
    if(n->right!=NULL) s.push(n->right);
    if(n->left!=NULL) s.push(n->left);
  }
}

void Inorder(Node* root){
  stack<Node*>s;
  Node* node=root;
  while(true){
    if(node!=NULL){
      s.push(node);
      node=node->left;
    }
    else{
      if(s.empty()==true)
      node=s.top(); 
      s.pop();
      cout<<node->data<<" ";
      node=node->right;
      
    }
  }
}
//postOrder using two stack
void PostOrder(Node* root){
  stack<Node*>s1;
  stack<Node*>s2;
  s1.push(root);
  while(!s1.empty()){
    root=s1.top();
    s1.pop();
    s2.push(root);
    if(root->left!=NULL) s1.push(root->left);
    if(root->right!=NULL) s1.push(root->right);
  }
  while(!s2.empty()){
    cout<<s2.top()->data<<" ";
    s2.pop();
  }
}

int main() 
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    PreOrder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    PostOrder(root);
     
    return 0;
}