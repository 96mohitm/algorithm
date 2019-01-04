#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V; //no of vertices

	// pointer to an array containing adjacency lists
	list<int> *adj;

	void DFS(int v, bool visited[]);
public:
	Graph(int V); //constructor
	void addEdge(int v, int w);
	void connectedComponents();
};

void Graph::DFS(int v, bool visited[]){
	//Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";

	// Recur for all the vertices
	// adjacent to this verticecs 
	list<int>::iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); ++i)
		if(!visited[*i])
			DFS(*i, visited);
}

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::connectedComponents(){
	bool *visited = new bool[V];
	for(int v = 0; v<V; v++)
		visited[v] = false;
	for(int v=0; v<V; v++){
		if(!visited[v]){
			DFS(v,visited);
			cout<<"\n";
		}
	}
}
int main(void){
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	cout<<"Following are connected Components \n";
	g.connectedComponents();
}