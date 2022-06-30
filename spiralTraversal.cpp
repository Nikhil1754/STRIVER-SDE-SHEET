#include <bits/stdc++.h>
using namespace std;
vector<int> spiralTraverse(vector<vector<int>>&matrix){
  vector<int>v;
   int top=0,left=0,bottom=matrix.size()-1,right=matrix[0].size()-1;
   while(left<=right && top<=bottom){
     for(int i=left;i<=right;i++){
       v.push_back(matrix[top][i]);
     }
     top++;
     for(int j=top;j<=bottom;j++){
       v.push_back(matrix[j][right]);
     }
     right--;
     if(left<=right){
       for(int i=right;i>=left;i--){
         v.push_back(matrix[bottom][i]);
       }
       bottom--;
     }
     if(top<=bottom){
       for(int i=bottom;i>=top;i--){
         v.push_back(matrix[i][left]);
       }
       left++;
     }
   }
   return v;
}
int main() 
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
      vector<int>temp;
      for(int j=0;j<m;j++){
        int ele;
        cin>>ele;
        temp.push_back(ele);
      }
      v.push_back(temp);
    }
    vector<int>res;
    res=spiralTraverse(v);
    for(auto &x:res){
      cout<<x<<" ";
    }
    
    return 0;
}