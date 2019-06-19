#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > adj;

vector<bool> vis;
vector<int> tin, low;
int timer;

void dfs(int u, int p=-1){
    vis[u] = true;
    tin[u] = low[u] = timer++;
    for(int to: adj[u]){
        if(to==p) continue;
        if(vis[to]){
            low[u] = min(low[u], tin[to]);
        }
        else{
            dfs(to, u);
            low[u] = min(low[u], low[to]);
            if(low[to] > tin[u]){
                printf("%d - %d\n",u,to);
            }
        }
    }
}

void find_bridges(){
    timer = 0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(i);
    }
}
int main(void){
    find_bridges();
}