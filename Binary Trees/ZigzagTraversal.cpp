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
vector<int> findSpiral(Node *root)
{
    //Your code herez
    vector<int>ans;
    if(root==NULL) return ans;
    queue<Node*>q;
    q.push(root);
    bool leftToright=false;
    int k=0;
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            Node* node=q.front();
            q.pop();
            ans.push_back(node->data);
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        if(leftToright==false){
            reverse(ans.begin()+k,ans.end());
            leftToright=true;
            
        }
        else{
            leftToright=false;
        }
        k+=s;
    }
    
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
  ans=findSpiral(root);
  for(auto x:ans){
    cout<<x<<" ";
  }
  
 
   return 0;
}