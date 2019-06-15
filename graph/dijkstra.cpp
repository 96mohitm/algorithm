#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<pii> > Graph;
typedef long long int ll;

void dijkstra(Graph &g, int s, vector<int> &prio, vector<int> &pred){
    int n = g.size();
    prio.assign(n, INT_MAX);
    prio[s] = 0;
    pred.assign(n, -1);
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(make_pair(0, s));

    while(!q.empty()){
        int d = q.top().first;
        int u = q.top().second;
        q.pop();
        if(d != prio[u])
            continue;
        for(int i=0; i<(int) g[u].size(); i++){
            int v = g[u][i].first;
            int nprio = prio[u] + g[u][i].second;
            if(prio[v] > nprio){
                prio[v] = nprio;
                pred[v] = u;
                q.push(make_pair(nprio, v));
            }
        }
    }
}

int main(void){
    Graph g(3);
    g[0].push_back(make_pair(1, 10));
    g[1].push_back(make_pair(2, -5));
    g[0].push_back(make_pair(2, 8));

    // prio is for storing the minimum distance from the source node.
    vector<int> prio;
    // pred is for storing the node through which the distance is minimum.
    vector<int> pred;

    dijkstra(g, 0, prio, pred);

    for (int i = 0; i < prio.size(); i++)
        cout << prio[i] << endl;

}