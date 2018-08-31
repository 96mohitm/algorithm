#include <bits/stdc++.h>
using namespace std;

vector<bool> v; //visited vector
vector<vector<int> > g; //adjlist

void edge(int a, int b){
	g[a].push_back(b);
	//for undirected graph
	// g[b].push_back(a);
}

void bfs(int u){
	queue<int> q;

	q.push(u);
	v[u] = 1;

	while(!q.empty()){
		int f = q.front();
		q.pop();
		cout<<f<<" ";

		//enqueue all the adjacent node to f
		for(auto i = g[f].begin();i!=g[f].end();i++){
			if(!v[*i]){
				q.push(*i);
				v[*i]=1;
			}
		}
	}
}

int main(void){
	int n,e;
	cin>>n>>e;//no of nodes and edges.

	//zero based indexing.
	v.assign(n,0);
	g.assign(n,vector<int>());

	int a,b;
	for(int i=0;i<e;i++){
		cin>>a>>b;
		edge(a,b);
	}
	for(int i=0;i<n;i++){
		if(!v[i])
			bfs(i);
	}
}
