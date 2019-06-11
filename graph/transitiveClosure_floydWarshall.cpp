#include <bits/stdc++.h>
using namespace std;

#define V 4

// Utility function to print solution.
void printSolution(int dist[][V])  
{  
    cout<<"Following matrix is transitive closure of the given graph\n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            cout<<dist[i][j]<<"  ";  
        }  
        cout<<endl;  
    }  
}  

// this uses floyd Warshall algorithm.
void transitive_closure(int graph[][V]){
    int reach[V][V],i,j,k;

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            reach[i][j] = graph[i][j];

    // the V^3 actual loop of the algo.
    for(k=0; k<V; k++){
        for(i=0; i<V; i++){
            for(j=0; j<V; j++){
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    printSolution(reach);
}



int main(void){
    // here we will be using adjancey matrix.
    int graph[V][V] {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    // solution
    transitive_closure(graph);
}