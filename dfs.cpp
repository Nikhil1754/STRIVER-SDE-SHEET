#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&sdfs){
        sdfs.push_back(node);
        vis[node]=1;
        for(auto x:adj[node]){
            if(vis[x]==0){
                dfs(x,vis,adj,sdfs);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>storedfs;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                dfs(i,vis,adj,storedfs);
            }
        }
        return storedfs;
    }

int main() 
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
      cout<<i<<"is connnected=>";
      for(auto &x:adj[i]){
        cout<<x<<" ";
      }
      cout<<endl;
    }
    vector<int>res;
    res=dfsOfGraph(n,adj);
    for(auto &x:res){
      cout<<x<<" ";
    }
    
}