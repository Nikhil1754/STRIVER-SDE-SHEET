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

int find_sum(Node* root,int &maxi){
    if(root==NULL) return 0;
    int lsum=max(0,find_sum(root->left,maxi));
    int rsum=max(0,find_sum(root->right,maxi));
    maxi=max(maxi,root->data+lsum+rsum);
    return root->data+max(lsum,rsum);
}
int maxPathSum(Node* root){
    int maxi=INT_MIN;
    find_sum(root,maxi);
    return maxi;
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
  
  int w=maxPathSum(root);
  cout<<"Max Sum is"<<" "<<w<<endl;
   return 0;
}