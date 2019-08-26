/*
Finding nCr,
C(n, r) = C(n-1, r-1) + C(n-1, k)
C(n, 0) = C(n, n) = 1
*/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
// top down approach.
int binomialCoeff(int n, int k){
	// base case
	if(k==0||n==k){
		dp[n][k]=1;
		return 1;
	}

	else if(dp[n][k] !=-1)
		return dp[n][k];

	dp[n][k] = binomialCoeff(n-1, k-1) +
			binomialCoeff(n-1, k);

	return dp[n][k];
}
// bottom up approach.
int binomialCoeffBottomup(int n, int k){
	int i,j;
	for(int i=0; i<=n; i++){
		for(int j=0; j<=min(i,k); j++){
			// base case
			if(j==0||j==i)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i-1][j-1] +
							dp[i-1][j];
		}
	}
	return dp[n][k];
}

// bottom up with linear space complexity.
int bottomupLinearSpace(int n, int k){
	vector<int> dp(k+1, 0);
	dp[0]=1;
	for(int i=1; i<=n; i++){
		for(int j= min(i,k); j>0; j--)
			dp[j] = dp[j] + dp[j-1];
	}
	return dp[k];
}

int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}


int main(void){
	int n,k;
	cin>>n>>k;
	dp.assign(n+1,vector<int>(k+1,-1));
	// cout<<binomialCoeff(n,k)<<"\n";
	// cout<<binomialCoeffBottomup(n,k)<<"\n";
	// cout<<bottomupLinearSpace(n,k)<<"\n";
	cout<<C(n, k)<<"\n";
}