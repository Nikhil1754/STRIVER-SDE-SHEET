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
int widthOfBinaryTree(Node* root) {
        if(root==NULL) return 0;
        queue<pair<Node*,long long>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            long long min=q.front().second;
            int first,last;
            for(int i=0;i<s;i++){
                long long curr_idx=q.front().second-min;
                Node* node=q.front().first;
                q.pop();
                if(i==0) first=curr_idx;
                if(i==s-1) last=curr_idx;
                if(node->left!=NULL) q.push({node->left,curr_idx*2+1});
                if(node->right!=NULL) q.push({node->right,curr_idx*2+2});
            }
            ans=max(ans,last-first+1);
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
  
  int w=widthOfBinaryTree(root);
  cout<<"Max Width is"<<" "<<w<<endl;
   return 0;
}