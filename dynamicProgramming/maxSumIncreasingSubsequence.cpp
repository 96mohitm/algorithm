#include <bits/stdc++.h>
using namespace std;

int maxSumIS(vector<int> a){
	int n = a.size();
	vector<int> dp(n);
	dp[0] = a[0];
	for(int i=1; i<n; i++){
		int r =a[i];
		for(int j=0; j<i; j++){
			if(a[i]>a[j]){
				r = max(a[i], a[i] + dp[j]);
			}
		}
		dp[i] = r;
	}
	return *max_element(dp.begin(), dp.end());
}

int main(void){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<maxSumIS(a)<<"\n";
}
/*
Input:
7
1 101 2 3 100 4 5
*/