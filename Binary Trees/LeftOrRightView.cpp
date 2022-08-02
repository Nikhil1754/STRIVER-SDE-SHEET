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
void find_right(vector<int>&ds,Node *root,int level){
    if(root==NULL) return;
    if(ds.size()==level) ds.push_back(root->data);
    find_right(ds,root->right,level+1);
    find_right(ds,root->left,level+1);
}
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       find_right(ans,root,0);
       return ans;
       
    }
void find_left(vector<int>&ds,Node *root,int level){
    if(root==NULL) return;
    if(ds.size()==level) ds.push_back(root->data);
    find_left(ds,root->left,level+1);
    find_left(ds,root->right,level+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   find_left(ans,root,0);
   return ans;
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
  vector<int>ans;
  ans=leftView(root);
  for(auto x:ans){
    cout<<x<<" ";
  }
  cout<<endl;
  vector<int>res;
  res=rightView(root);
  for(auto x:res){
    cout<<x<<" ";
  }
  
 
   return 0;
}