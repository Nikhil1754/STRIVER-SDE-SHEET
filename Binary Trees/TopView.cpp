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
vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL) return ans;
        queue<pair<int,Node*>>q;
        map<int,int>mp;
        q.push({0,root});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto a=q.front();
                Node* n=a.second;
                int line=a.first;
                q.pop();
                if(mp.find(line)==mp.end()) mp[line]=n->data;
                if(n->left!=NULL) q.push({line-1,n->left});
                if(n->right!=NULL) q.push({line+1,n->right});
            }
        }
        for(auto x:mp){
            ans.push_back(x.second);
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
  ans=topView(root);
  for(auto x:ans){
    cout<<x<<" ";
  }
  
 
   return 0;
}