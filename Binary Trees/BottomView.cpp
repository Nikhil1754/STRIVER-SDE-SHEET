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
vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto a=q.front();
            Node* node=a.first;
            int x=a.second;
            mp[x].push_back(node->data);
            q.pop();
            if(node->left) q.push({node->left,x-1});
            if(node->right) q.push({node->right,x+1});
        }
        vector<int>ans;
        for(auto k:mp){
            ans.push_back(k.second[k.second.size()-1]);
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
  ans=bottomView(root);
  for(auto x:ans){
    cout<<x<<" ";
  }
  
  
 
   return 0;
}