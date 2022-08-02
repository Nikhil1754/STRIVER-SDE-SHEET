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

bool isLeaf(Node* root){
       if(root->left==NULL && root->right==NULL) return true;
       else return false;
   }
    void addLeft(Node *root,vector<int>&ds){
        Node* cur=root->left;
        while(cur){
            if(!isLeaf(cur)) ds.push_back(cur->data);
            if(cur->left!=NULL) cur=cur->left;
            else{
                cur=cur->right;
            }
        }
    }
    void addright(Node *root,vector<int>&ds)
    {
        Node * cur=root->right;
        vector<int>temp;
        while(cur){
            if(!isLeaf(cur)) temp.push_back(cur->data);
            if(cur->right!=NULL) cur=cur->right;
            else{
                cur=cur->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            ds.push_back(temp[i]);
        }
    }
    void addLeaves(Node* root,vector<int>&ds){
        if(isLeaf(root)){
            ds.push_back(root->data);
            return;
        }
        if(root->left!=NULL) addLeaves(root->left,ds);
        if(root->right!=NULL) addLeaves(root->right,ds);
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>res;
        if(root==NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeft(root,res);
        addLeaves(root,res);
        addright(root,res);
        return res;
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
  ans=boundary(root);
  for(auto x:ans){
    cout<<x<<" ";
  }
  
 
   return 0;
}