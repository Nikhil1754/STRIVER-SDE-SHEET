#include<bits/stdc++.h>
using namespace std;
int lcs(string &s1,int ind1,string &s2,int ind2){
    if(ind1<0 || ind2<0){
        return 0;
    }
    if(s1[ind1]==s2[ind2]){
        return 1+lcs(s1,ind1-1,s2,ind2-1);
    }
    else{
        return max(lcs(s1,ind1-1,s2,ind2),lcs(s1,ind1,s2,ind2-1));
    }
}

int main(){
    //string s1="acde";
    //string s2="bade";
    string s1,s2;
    cin>>s1>>s2;
    int l=0;
    int ind1=s1.size()-1;
    int ind2=s2.size()-1;
    l=lcs(s1,ind1,s2,ind2);
    cout<<l<<endl;
    return 0;
}