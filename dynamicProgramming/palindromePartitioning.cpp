#include <bits/stdc++.h>
using namespace std;
/*
TC : O(n^2)
SC : O(n^2)
*/
int minPartition(string s){
	int n = s.size();

	int c[n][n];
	bool p[n][n];
	for(int i=0; i<n; i++){
		c[i][i] = 0;
		p[i][i] = true;
	}
	for(int l=2; l<=n; l++){
		for(int i=0; i<n-l+1; i++){
			int j = i + l - 1;

			if(l==2)
				p[i][j] = (s[i] == s[j]);
			else
				p[i][j] = (s[i] == s[j]) && p[i+1][j-1];

			if(p[i][j])
				c[i][j] = 0;
			else{
				c[i][j] = INT_MAX;
				for(int k = i; k < j; k++)
					c[i][j] = min(c[i][j], c[i][k] + c[k+1][j] +1);
			}
		}
	}
	return c[0][n-1];
}

// Optimization
int minPartitionOptimize(string s){
	int n = s.size();

	int c[n];
	c[0]=0;
	bool p[n][n];
	for(int i=0; i<n; i++)
		p[i][i] = true;
	for(int l=2; l<=n; l++){
		for(int i=0; i<n-l+1; i++){
			int j = i + l - 1;

			if(l==2)
				p[i][j] = (s[i] == s[j]);
			else
				p[i][j] = (s[i] == s[j]) && p[i+1][j-1];
		}
	}
	for(int i=0; i<n; i++){
		if(p[0][i])
			c[i]=0;
		else{
			c[i] = INT_MAX;
			for(int j = 0; j<i; j++){
				if(p[j+1][i] && c[j] + 1 < c[i])
					c[i] = c[j]+1;
			}
		}
	}
	return c[n-1];

}

int main(void){
	string s;
	cin>>s;
	cout<<minPartition(s)<<"\n";
	cout<<minPartitionOptimize(s)<<"\n";
}
