/*
Given a value N, if we want to make change for N cents, 
and we have infinite supply of each of 
S = { S1, S2, .. , Sm} valued coins, how many ways 
can we make the change? The order of coins doesn’t matter.
*/



// recursive function.



// bottom up approach
int count(vector<int> coins, int n){
	int m = coins.size();
	int dp[n+1][m];

	// for the case n=0
	for(int i=0; i<m; i++)
		dp[0][i] = 1;

	for(int i=1; i<=n; ++i){
		for(int j=0; j<m; ++j){
			// count of solutions including coins[j].
			int x = (i - coins[j] >=0)? dp[i - coins[j]][j] : 0;

			// count of solutions including coins[j].
			int y = (j >= 1) ? dp[i][j-1] : 0;

			// total count
			dp[i][j] = (x + y)% 1000007;
		}
	}
	return dp[n][m-1];
}

// bottom up space optimized.
int count(vector<int> coins, int n){
	int m = coins.size();

	vector<int> dp(n+1, 0);
	dp[0]=1;

	for(int i=0; i<m; i++)
		for(int j=coins[i]; j<=n; j++)
			dp[j] += dp[j - coins[i]];
	return dp[n];
}
#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n,m;
	cin>>n>>m;
	

}