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
Node* Building(vector<int>&in,int ins,int ine,vector<int>&po,int pos,int poe,map<int,int>&mp){
        if(ins>ine || pos>poe) return NULL;
        Node* root=new Node(po[poe]);
        int inroot=mp[root->data];
        int numLeft=inroot-ins;
        root->left=Building(in,ins,inroot-1,po,pos,pos+numLeft-1,mp);
        root->right=Building(in,inroot+1,ine,po,pos+numLeft,poe-1,mp);
        return root;
        
    }
    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        Node* root=Building(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        return root;
    }
void inorderTraversal(Node* root){
  if(root==NULL) return;
  inorderTraversal(root->left);
  cout<<root->data<<" ";
  inorderTraversal(root->right);
}
int main(){
    vector<int>inorder={9,3,15,20,7};
    vector<int>postorder={9,15,7,20,3};
    Node* root=NULL;
    root=buildTree(inorder,postorder);
    inorderTraversal(root);

}