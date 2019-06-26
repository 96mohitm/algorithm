#include <bits/stdc++.h>
using namespace std;

int n; // no of vertices
vector<vector<int> > adj;
vector<bool> vis;
vector<int> ans;

void dfs(int v){
    vis[v] = true;
    for(int u: adj[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
    ans.push_back(v);
}

void topological_sort(){
    vis.assign(n, false);
    ans.clear();
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
}


int main(void){

}