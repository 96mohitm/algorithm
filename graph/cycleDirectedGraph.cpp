#include <bits/stdc++.h>
using namespace std;
/*
* This is code for dectection of cycle in
* a given directed graph.
*/
class Graph{
	int V; // no of vertices.
	vector<vector<int>> adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs);
public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
};

// contructor.
Graph::Graph(int V){
	this->V = V;
	adj.assign(V, vector<int>());
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}

bool Graph::isCyclicUtil(int v, bool visited[], bool *resStack){
	if(visited[v]==false){

		visited[v] = true;
		resStack[v] = true;

		for(auto i = adj[v].begin(); i != adj[v].end(); ++i){
			if(!visited[*i] && isCyclicUtil(*i, visited, resStack))
				return true;
			else if(resStack[*i])
				return true;
		}
	}
	resStack[v] = false;
	return false;
}

bool Graph::isCyclic(){
	bool *visited = new bool[V];
	bool *resStack = new bool[V];
	for(int i=0; i<V; ++i)
		visited[i] = resStack[i] = false;

	for(int i=0; i<V; ++i)
		if(isCyclicUtil(i, visited, resStack))
			return true;

	return false;
}

int main(){

    // Create a graph given in the above diagram 
    Graph g(4); 
    // g.addEdge(0, 1); 
    // g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    // g.addEdge(3, 3); 
  
    if(g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
    return 0; 
} 
