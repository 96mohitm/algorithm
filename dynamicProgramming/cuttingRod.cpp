#include <bits/stdc++.h>
using namespace std;

// top down approach
int cutRod(vector<int> v, int n){
	if(n<=0)
		return 0;
	int max_val = INT_MIN;

	for(int i=0; i<n; i++)
		max_val = max(max_val, v[i] + cutRod(v, n-i-1));
	
	return max_val;
}

// bottom up approach
int cutRodBottomup(vector<int> v, int n){
	int dp[n+1];
	dp[0] = 0;

	for(int i=1; i<=n; i++){
		int max_val = INT_MIN;
		for(int j=0; j<i; j++)
			max_val = max(max_val, v[j] + dp[i-j-1]);

		dp[i] = max_val;
	}
	return dp[n];
}

int main(void){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];
	cout<<cutRod(v, n)<<"\n";
	cout<<cutRodBottomup(v, n)<<"\n";
}

/*
Input:
8
1 5 8 9 10 17 17 20
Output:
22
*/