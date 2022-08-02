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
int heightUsing_recur(Node* root){
  if(root==NULL){
    return 0;
  }
  int lh=heightUsing_recur(root->left);
  int rh=heightUsing_recur(root->right);
  return 1+max(lh,rh);
}
int heightUsing_level_order(Node* root){
  queue<Node*>q;
  q.push(root);
  int h=0;
  while(!q.empty()){
    int s=q.size();
    for(int i=0;i<s;i++){
      Node* nw=q.front();
      q.pop();
      if(nw->left!=NULL) q.push(nw->left);
      if(nw->right!=NULL) q.push(nw->right);
    }
    h++;
  }
  return h;
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
  
  int h=heightUsing_recur(root);
  cout<<"height is"<<" "<<h<<endl;
  cout<<"height is"<<" "<<heightUsing_level_order(root)<<endl;
   return 0;
}