#include <bits/stdc++.h>
using namespace std;
int min3(int x, int y, int z){
	return min(x, min(y, z));
}
// this is top-down recursive approach.
int minCostPath(vector<vector<int> > A, int n, int m){
	if(n<0||m<0)
		return INT_MAX;
	else if(n==0&&m==0)
		return A[n][m];
	else{
		return A[n][m] + min3(minCostPath(A, n-1, m-1),
								minCostPath(A, n-1, m), 
								minCostPath(A, n, m-1));
	}
}

// this is bottom-up approach.
int minCostPath_bottom_up(vector<vector<int> > A){
	int n = A.size(); // row.
	int m = A[0].size(); // column.
	vector<vector<int> > dp(n, vector<int>(m, 0));

	dp[0][0] = A[0][0];
	for(int i=1; i<n; i++)
		dp[i][0] = dp[i-1][0] + A[i][0];
	for(int j=1; j<m; j++)
		dp[0][j] = dp[0][j-1] + A[0][j];
	for(int i=1; i<n; i++){
		for(int j=1; j<n; j++){
			dp[i][j] = A[i][j] + min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n-1][m-1];
}
int main(void){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > A(n, vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>A[i][j];
		}
	}
	cout<<minCostPath(A, n-1, m-1)<<"\n";
	cout<<minCostPath_bottom_up(A)<<"\n";
}
/*
input:
3 3
1 2 3
4 8 2
1 5 3
*/