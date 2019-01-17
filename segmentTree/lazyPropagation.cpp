#include <bits/stdc++.h>
using namespace std;
/*
Here the updates are incremental
Pending updates or lazy propagation.
*/
int tree[400005] = {0};
int lazy[400005] = {0};
int arr[100005];

void build_tree(int node, int start, int end){
	//initialing the leaves.
	if(start == end){
		tree[node] = arr[start];
		return;
	}
	//recursively initialize the segment tree in bottom up manner.
	int mid = (start + end) >> 1;
	build_tree(2*node , start, mid);
	build_tree(2*node + 1, mid + 1, end);
	tree[node] = min(tree[2*node], tree[2*node + 1]);
}

void updateRangeLazy(
	int node, int start, int end, int qstart, int qend, int val){
	//first step - Never go down if we have lazy value at node,
	//first resolve it
	if(lazy[node] != 0){
		tree[node] += lazy[node];
		//if its not a leaf node
		if(start != end){
			lazy[2*node] += lazy[index];
			lazy[2*node + 1] += lazy[index];
		}
		//now we have resolved the lazy value
		lazy[node] = 0;
	}
	//No overlap
	if(start > end || start > qend || end < qstart)
		return;
	//Complete overlap
	if(start >= qstart && end <= qend){
		tree[node] += val;
		//pass the lazy value to its child if its not a leaf
		if(start != end){
			lazy[2*node] += val;
			lazy[2*node +1] += val;
		}
		return;
	}
	//Partial overlap
	int mid = (start + end) >> 1;
	updateRangeLazy(2*node, start, mid, qstart, qend, val);
	updateRangeLazy(2*node +1, mid +1, end, qstart, qend, val);
	tree[node] = min(tree[2*node], tree[2*node +1]);
}
//Same as previous query + resolving the lazy value.
int queryLazy(int node, int start, int end, int qstart, int qend){
	//first step - resolve the lazy value
	if(lazy[node]!=0){
		tree[node] += lazy[node];
		//if its not a leaf node
		if(start != end){
			lazy[2*node] += lazy[node];
			lazy[2*node +1] += lazy[node];
		}
		lazy[node] = 0;
	}
	//no overlap
	if(start > end || start > qend || end < qstart)
		return;
	//complete overlap
	if(start >= qstart && end <= qend)
		return tree[node];
	//partial overlap
	int mid = (start + end) >> 1;
	int left = queryLazy(2*node, start, mid, qstart, qend);
	int right = queryLazy(2*node, mid+1, end, qstart, qend);
	return min(left, right);
}
int main(void){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	build_tree(1,1,n);
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i<n)
}