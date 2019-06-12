#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    bool **tc;
    list<int> *adj;
    void DFS(int u, int v);

public:
    // constructor.
    Graph(int V);

    // adding edges in Graph.
    void addEdge(int v, int u){
        adj[v].push_back(u);
    }

    void transitiveClosure();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];

    tc = new bool* [V];
    for(int i=0; i<V; i++){
        tc[i] = new bool[V];
        memset(tc[i], false, V*sizeof(bool));
    }
}

void Graph::DFS(int u, int v){
    tc[u][v] = true;

    list<int>::iterator it;
    /* ########### VERY IMPORTANT ###########
       Here we are using the adjancy list of v and calling the function
       dfs function with u.
    */
    for(it=adj[v].begin(); it!=adj[v].end(); it++){
        if(tc[u][*it] == false)
            DFS(u, *it);
    }
}

void Graph::transitiveClosure(){
    /* the time complexity of this algo using
        DFS is O(V^2)
    */

    // calling DFS for all the nodes.
    for(int i=0; i<V; i++){
        DFS(i,i);
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cout << tc[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Transitive closure matrix is \n"; 
    g.transitiveClosure(); 

}