/*
Partition problem is to determine whether a given set
can be partitioned into two subsets such that
the sum of elements in both subsets is same.
*/
#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<(#x)<<" "<<x<<"\n";
/*
This function check whether a subset of given vector
sum upto total.
*/
bool subsetSum(vector<int> &a, int total){
	int n = a.size();
	bool dp[n+1][total+1]; // row: 0 to n & col: 0 to sum.
	// initializing to true for sum 0.
	for(int i=0; i<=n; i++)
		dp[i][0] = true;
	// initializing to false for sum > 0 and no element.
	for(int j=1; j<=total; j++)
		dp[0][j] = false;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=total; j++){
			if(j >= a[i-1])
				dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i-1]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][total];
}

bool ispartition(vector<int> &a){
	int n = a.size();
	int sum = accumulate(a.begin(), a.end(), 0);
	if(sum&1)
		return false;
	sum = sum/2;
	// return sum;
	return subsetSum(a, sum);
}

int main(void){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<ispartition(a)<<"\n";
}
