#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity of the optimization.
its same for both the approach size and rank.
time complexity(per operation) is O(α(n)),where α(n) is
the inverseAckerman function,
which grows very slowly. In fact it grows so slowly,
that it doesn't exceed 4 for all reasonable n (approximately n<10^600).

Also, it's worth mentioning that DSU with union by size / rank,
but without path compression works in O(logn) time per query.

*/
//optimization 
void make_set(int v){
	parent[v] = v;
	size[v] 1;
	//for rank based optimization.
	rank[0]=0;
}

int find_set(int v){
	if(v==parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
//optimazations using sizes
void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(size[a] < size[b])
			swap(a,b);
		parent[b] = a;
		size[a] +=size[b];
	}
}
// optimization using rankings
void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a!=b){
		if(rank[a] < rank[b])
			swap(a,b);
		parent[b] = a;
		if(rank[a] == rank[b])
			rank[a]++;
	}
}

int main(void){
	
}