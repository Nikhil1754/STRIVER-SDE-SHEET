#include <bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int x){
    data=x;
    left=right=NULL;
  }
};
bool isCheck(Node* root1,Node* root2){
        if(root1==NULL || root2==NULL) return root1==root2;
        if(root1->data!=root2->data) return false;
        return isCheck(root1->left,root2->right)&&isCheck(root1->right,root2->left);
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(Node* root)
    {
	    // Code here
	    return root==NULL || isCheck(root->left,root->right);
    }

int main() 
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right->left=new Node(4);
    root->right->right=new Node(3);
    if(isSymmetric(root)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    
     
    return 0;
}