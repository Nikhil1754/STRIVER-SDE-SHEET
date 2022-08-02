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
int checkBalance(Node *root){
    if(root==NULL) return 0;
    int lh=checkBalance(root->left);
    if(lh==-1) return -1;
    int rh=checkBalance(root->right);
    if(rh==-1) return -1;
      if(abs(lh-rh)>1) return -1;
    return 1+max(lh,rh);
}
bool isBalanced(Node* root){
    return checkBalance(root)!=-1;
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
  if(isBalanced(root)) cout<<"Yes"<<endl;
  else cout<<"NoT";
   return 0;
}