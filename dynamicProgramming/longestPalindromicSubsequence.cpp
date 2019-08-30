#include <bits/stdc++.h>
using namespace std;

// top down approach
int longestPalindromicSubsequence(string s, int i, int j){
	if(i==j)
		return 1;
	
	if(s[i] == s[j] && i+1 == j)
		return 2;

	if(s[i] == s[j])
		return longestPalindromicSubsequence(s, i+1, j-1)+2;

	return max(longestPalindromicSubsequence(s, i+1,j), longestPalindromicSubsequence(s, i, j-1));
}

// bottom up approach
int lps(string s){
	int n = s.length();
	int i,j;
	int dp[n][n];

	for(i=0; i<n; i++)
		dp[i][i] = 1;

	for(int d=1; d<n; d++){ // the difference.
		for(i=0; i<n-d; i++){ // the row index.
			j = i+d;
			if(s[i] == s[j] && d == 1)
				dp[i][j] = 2;
			else if(s[i] == s[j])
				dp[i][j] = dp[i+1][j-1] + 2;
			else
				dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
		}
	}

	return dp[0][n-1];
}

int main(void){
	string s;
	cin>>s;
	int l = s.length();
	cout<<longestPalindromicSubsequence(s, 0, l-1)<<"\n";
	cout<<lps(s)<<"\n";
}
