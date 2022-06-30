#include<bits/stdc++.h>
using namespace std;
void subset(vector<int>&v,vector<int>ds,int ind,vector<vector<int>>&res){
    //first we have to store the empty one
    res.push_back(ds);
    for(int i=ind;i<(int)v.size();i++){
        //check fro duplicates
        if(i!=ind && v[i]==v[i-1]) continue;
        ds.push_back(v[i]);
        subset(v,ds,i+1,res);
        ds.pop_back();
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<int>>res;
    vector<int>ds;
    subset(v,ds,0,res);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}