#include <bits/stdc++.h>
using namespace std;
int sum(int a[], int s, int e){
	int r=0;
	for(int i=s;i<=e;i++){
		r = (r+a[i])%100;
	}
	return r;
}
int matrixChain(int p[], int n){
	int dp[n][n];
	int i,j,k,l,q;

	// cost is zero when multiplying one matrix
	for(i=0;i<n;i++)
		dp[i][i]=0;

	// l is the chain length
	for(l=2; l<=n; l++){
		for(i=0; i<n-l+1; i++){
			j = i+l-1;
			dp[i][j] = INT_MAX;
			for(k=i;k<=j-1;k++){
				q = dp[i][k] + dp[k+1][j] + sum(p,i,k)*sum(p,k+1,j);
				printf("q=%d\n",q );
				if(q<dp[i][j])
					dp[i][j]=q;
			}
		}
	}
	return dp[1][n-1];
}

int main(void){
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int a[n];
		for(int i =0;i<n;i++) scanf("%d",&a[i]);
		printf("%d\n",matrixChain(a, n));
	}
}