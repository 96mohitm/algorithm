#include <bits/stdc++.h>
using namespace std;

int n; // number of nodes.
vector<vector<int> > adj;

vector<bool> vis; // visited array.
// tin : time of entry into node, low: lowestest time.
vector<int> tin, low;
int timer;

void dfs(int u, int p=-1){
    vis[u] = true;
    tin[u] = low[u] = timer++;
    int children = 0;
    for(int to: adj[u]){
        if(to == p) continue;
        if(vis[to]){
            low[u] = min(low[u], tin[to]);
        }
        else{
            dfs(to, u);
            low[u] = min(low[u], low[to]);
            if(low[to] >= tin[u] && p!=-1)
                printf("%d",u);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        printf("%d",u);
}

void find_cutpints(){
    timer=0;
    vis.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for(int i=0; i < n; i++){
        if(!vis[i])
            dfs(i);
    }
}

int main(void){
    // initialize the graph
    // then call the function
    // find_cutpints();
    // this will print all the cutpoints/articulation points.
}