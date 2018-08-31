#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool v[10];

void addEdge(int u, int v){
	adj[u].push_back(v);
	//its a undirected graph
	adj[v].push_back(u);
}
//initializing the visited array to false.
void intialize(){
	for(int i=0;i<10;++i)
		v[i] = 0;
}
//recursive function.
void dfs(int s){
	v[s] = 1;
	printf("%d\n",s );
	for(int i=0;i<adj[s].size(); ++i){
		if(!v[adj[s][i]])	//if not visited.
			dfs(adj[s][i]);
	}
}

int main(void){
	int n, e, x, y;
	scanf("%d%d",&n,&e);//nodes & edeges
	for(int i=0;i<e;i++){
		scanf("%d%d",&x,&y);
		addEdge(x,y);
	}
	intialize();
	for(int i=0;i<n;++i){
		if(!v[i])
			dfs(i);
	}
}