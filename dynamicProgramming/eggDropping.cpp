#include <bits/stdc++.h>
using namespace std;

// top-down approach.
int eggDrop(int n, int k){
	// if 1 floor or no floor.
	if(k == 1 || k==0)
		return k;
	// if only 1 egg is left.
	if(n==1)
		return k;

	int m = INT_MAX, x, r;

	for(x=1; x<=k; x++){
		r = max(eggDrop(n-1, x-1), eggDrop(n, k-x));
		m = min(r, m);
	}
	return m + 1;
}

// bottom up approach.
int eggDropBottomup(int n, int k){
	int dp[n+1][k+1];
	int r;
	int i, j, x;

	// If 1 floor or no floor.
	for(i=0; i<=n; i++){
		dp[i][0] = 0;
		dp[i][1] = 1;
	}

	// If only only 1 egg is left.
	for(j=0; j<=k; j++)
		dp[1][j] = j;

	for(int i=2; i<=n; i++){
		for(int j=2; j<=k; j++){
			dp[i][j] = INT_MAX;
			for(int x = 1; x<=j; x++){
				r = 1 + max(dp[i-1][x-1], dp[i][j-x]);
				if(r<dp[i][j])
					dp[i][j] = r;
			}
		}
	}
	return dp[n][k];
}

int main(void){
	int n, k; // n-no of eggs, k-no of floors.
	cin>>n>>k;
	cout<<eggDrop(n,k)<<"\n";
	cout<<eggDropBottomup(n,k)<<"\n";
}