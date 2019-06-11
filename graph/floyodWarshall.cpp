#include <bits/stdc++.h>
using namespace std;

#define inf 9999
#define V 4

void printSolution(int dist[][V])  
{  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == inf)  
                cout<<"INF"<<"   ";  
            else
                cout<<dist[i][j]<<"  ";  
        }  
        cout<<endl;  
    }  
}  

void floyd_warshall(int graph[][V]){
    int dist[V][V],i,j,k;

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            dist[i][j] = graph[i][j];

    // the V^3 actual loop of the algo.
    for(k=0; k<V; k++){
        for(i=0; i<V; i++){
            for(j=0; j<V; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}



int main(void){
    // here we will be using adjancey matrix.
    int graph[V][V] {
        {0, 5, inf, 10},
        {inf, 0, 3, inf},
        {inf, inf, 0, 1},
        {inf, inf, inf, 0}
    };

    // solution
    floyd_warshall(graph);
}