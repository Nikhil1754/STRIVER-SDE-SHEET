#include <bits/stdc++.h>
using namespace std;
class TreeNode{
  public:
  int val;
  TreeNode *left,*right;
  TreeNode(int x){
    val=x;
    left=right=NULL;
  }
};
 vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto a=q.front();
            TreeNode* n=a.first;
            int x=a.second.first;
            int level=a.second.second;
            q.pop();
            nodes[x][level].insert(n->val);
            if(n->left) q.push({n->left,{x-1,level+1}});
            if(n->right) q.push({n->right,{x+1,level+1}});
        }
        vector<vector<int>>ans;
        for(auto mp:nodes){
            vector<int>col;
            for(auto smp:mp.second){
                col.insert(col.end(),smp.second.begin(),smp.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }



int main() 
{
  TreeNode *root=new TreeNode(1);
  root->left= new TreeNode(2);
  root->right=new TreeNode(3);
  root->left->left=new TreeNode(4);
  root->left->right=new TreeNode(5);
  root->right->left=new TreeNode(6);
  root->right->right=new TreeNode(7);
  vector<vector<int>>ans;
  ans=verticalTraversal(root);
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  
   return 0;
}