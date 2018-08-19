//the number of ways in which we can reach the top.
#include <bits/stdc++.h>
using namespace std;
// simple recursive function.
// he can jump atmost 3 steps at a time.
int ways(int n){
	// ground.
	if(n==0)
		return 1;
	// lower than ground.
	if(n<0)
		return 0;
	int ans = ways(n-1) + ways(n-2) + ways(n-3);
	return ans;
}

vector<int> dptop(100000, -1);
// dp[0] =1;
//Top Down DP
int waystd(int n){
	// ground.
	if(n==0)
		return 1;
	// lower than ground.
	if(n<0)
		return 0;

	if(dptop[n]!=-1)
		return dptop[n];

	dptop[n] = waystd(n-1) + waystd(n-2) + waystd(n-3);
	return dptop[n];
}
// Simple recursive approach
// he can jump atmost k steps at a time
int ways2(int n, int k){
	// ground.
	if(n==0)
		return 1;
	// lower than ground.
	if(n<0)
		return 0;
	int ans =0;
	for(int i=1;i<=k;i++)
		ans+=ways2(n-i,k);
	return ans;
}

// Bottom Up DP
//dp[n] denotes the number of ways to reach the nth step.
//T.C = O(k*n)
int waysBu(int n, int k){
	int *dp = new int[n+1];
	dp[0]=1;
	for(int step =1;step<=n;step++){
		dp[step]=0;

		for(int j=0;j<=k;j++){
			if(step-j>=0)
				dp[step]+=dp[step-j];
		}
	}
	return dp[n];
}
// We can also implement the bottom Up function in T.C O(n)

int main(void){
	int n= 4;
	printf("%d\n",ways(n));// for n=4 no of ways must be 7.
	printf("%d\n",waystd(n) );//7
	printf("%d\n",ways2(3,2) );//3
	printf("%d\n",ways2(4,3) );//7
	printf("%d\n",ways2(5,4) );//15
	printf("%d\n",waysBu(5,4 ) );
}