#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int parent[10000001],nodes,edges;
pair<int, pair<int, int> > G[10000001];

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_set(int x, int y){
    x = find_set(x);
    y = find_set(y);
    parent[x] = parent[y];
}

int kruskal(pair<int, pii> p[]){
    int minCost = 0;
    int x, y;
    for(int i=0; i<edges; i++){
        x = p[i].second.first;
        y = p[i].second.second;
        int cost = p[i].first;
        if(find_set(x)!=find_set(y)){
            minCost += cost;
            union_set(x, y);
            cout<<x<<y<<"\n";
        }
    }
    return minCost;
}

int main(void){
    cin >> nodes >> edges;
    for(int i=0; i<nodes; i++)
        parent[i] = i;
    int x, y, weight;
    for(int i=0; i<edges; i++){
        cin >> x >> y >> weight;
        G[i] = make_pair(weight, make_pair(x, y));
    }
    sort(G, G+edges);
    int minCost = kruskal(G);
    cout<<"Min cost:"<<minCost;
}


/*
This is a Greedy Algorithm.
In this algorithm we first sort the edges of a graph and
then keep on adding the edges untill the does not creates a cycle in the graph.
*/