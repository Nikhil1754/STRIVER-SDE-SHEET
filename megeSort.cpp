#include <bits/stdc++.h>
using namespace std;

void merg(vector<int>&a,int l,int m,int r){
  int n1=m-l+1;
  int n2=r-l;
  vector<int> left(n1),right(n2);
  for(int i=0;i<n1;i++){
    left[i]=a[l+i];
  }
  for(int j=0;j<n2;j++){
    right[j]=a[m+1+j];
  }
  int i=0,j=0,k=l;
  while(i<n1 && j<n2){
    if(left[i]<=right[j]){
      a[k]=left[i];
      i++;
    }
    else if(left[i]>=right[j]){
      a[k]=right[j];
      j++;
    }
    k++;
  }
  while(i<n1){
    a[k]=left[i];
    i++;
    k++;
  }
  while(j<n2){
    a[k]=right[j];
    j++;
    k++;
  }
}
void merge_sort(vector<int>&a,int l,int r){
  if(l<r){
  int m=((r-l)/2+l);
  merge_sort(a,l,m);
  merge_sort(a,m+1,r);
  merg(a,l,m,r);
  }
}

int main() 
{
    vector<int>v={3,5,6,1,9};
    int n=v.size()-1;
    merge_sort(v,0,n);
    //sort(v.begin(),v.end());
    for(auto &x:v){
      cout<<x<<" ";
    }
    
    return 0;
}