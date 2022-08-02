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

bool path(Node* root,vector<int>&ds,int B){
     if(root==NULL) return false;
     ds.push_back(root->data);
     if(root->data==B){
        return true;
    }
    if(path(root->left,ds,B) || path(root->right,ds,B)) return true;
    ds.pop_back();
    return false;
    
   
 }
vector<int> solve(Node* A, int B) {
    vector<int>ans;
    path(A,ans,B);
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
  vector<int>ans=solve(root,6);
 for(auto x:ans){
    cout<<x<<" ";
 } 
   return 0;
}