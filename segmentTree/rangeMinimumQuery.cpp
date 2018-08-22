#include <bits/stdc++.h>
using namespace std;
//Segment Tree is stored in a array tree[].
int tree[400005] = {0};
int arr[100005];
/*
Function for building the segment tree.
node - index of tree[] array
start and end is the starting and ending index of the arr[] array.
*/
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
/*
Function for computing the result of the given query.
*/
int query(int node, int start, int end, int qstart, int qend){
	//No overlap
	if(start > end || qstart > end || qend < start)
		return INT_MAX;
	//Complete Overlap
	if(qstart <= start && qend >= end)
		return tree[node];
	//Partial overlap
	int mid = (start + end) >> 1;
	int q1 = query(2*node, start, mid, qstart, qend);
	int q2 = query(2*node + 1, mid+1, end, qstart, qend);
	return min(q1, q2);
}
/*
Update function for changing the value of given array.
*/
void update(int node, int start, int end, int i, int val){
	//No overlap.
	if(start > end|| i < start || i > end)
		return;
	//leave node
	if(start == end){
		//Here the value of the array is replaced with the given val.
		tree[node] = val;
		return;
	}
	int mid = (start + end) >> 1;
	update(2*node, start, mid, i, val);
	update(2*node + 1, mid + 1, end, i, val);
	tree[node] = min(tree[2*node], tree[2*node + 1]);
}
/*
Function for updating the value of the given range.
This is very slow. The optimization to this is lazy propagation.
*/
void updateRange(
	int node, int start, int end, int qstart, int qend, int val){
	//No overlap
	if(start > end || start > qend || end < qstart)
		return;
	//leaf node
	if(start == end){
		tree[node] = val;
		return;
	}
	int mid = (start + end) >> 1;
	updateRange(2*node, start, mid, qstart, qend, val);
	updateRange(2*node + 1, mid+1,end, qstart, qend, val);
	tree[node] = min(tree[2*node], tree[2*node + 1]);
}

int main(void){
	//n is the size of array
	int n;
	scanf("%d",&n);
	int i;
	for(i = 1; i <= n; i++)
		scanf("%d",&arr[i]);
	//Let's build the segment tree.
	build_tree(1, 1, n);
	int q, t, x, y;
	// q is the number of query.
	scanf("%d",&q);
	/*
	Two types of query are possible.
	1 l r
	2 i val
	*/
	for(i = 0; i < q; i++){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)
			printf("%d\n",query(1, 1, n, x, y) );
		else if(t==2)
			update(1, 1, n, x, y);
	}
}
/*
Input:
6
1 3 2 -5 6 4
6
1 1 1
1 1 2
1 1 3
1 1 4
2 4 5
1 4 5
Output:
1
1
1
-5
5
*/
