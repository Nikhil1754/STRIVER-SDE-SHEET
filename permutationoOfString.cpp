#include<bits/stdc++.h>
using namespace std;
void permute(string &s,int ind,vector<string>&ds){
    if(ind==s.size()-1){
        ds.push_back(s);
        return;
    }
    for(int i=ind;i<s.size();i++){
        swap(s[i],s[ind]);
        permute(s,ind+1,ds);
        swap(s[i],s[ind]);
    }
}
vector<string> find_permutation(string &s){
    vector<string>ds;
    permute(s,0,ds);
    return ds;
}

int main(){
    string s;
    cin>>s;
    vector<string>ans;
    ans=find_permutation(s);
    for(auto &x:ans){
        cout<<x<<" ";
    }
    return 0;
}