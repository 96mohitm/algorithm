#include <bits/stdc++.h>
using namespace std;

/*
Simple recusive function
m is the number of different types of coins.
*/
int minCoin(int coins[], int m, int n){
	if(n==0)
		return 0;
	int result = INT_MAX;
	for(int i=0;i<m;i++){
		if(coins[i]<=n){
			int sub_res = 1 + minCoin(coins, m, n - coins[i]);
			if(sub_res< result)
				result = sub_res;
		}
	}
	return result;
}

// topdown approach
int arr[10000001];
int mincointd(int coins[], int m, int n){
	//base case
	if(n==0)
		return 0;
	if(arr[n]!=-1)
		return arr[n];
	int result = INT_MAX;
	for(int i=0;i<m;i++){
		if(n>=coins[i]){
			int sub_res = 1 + mincointd(coins,m,n-coins[i]);
			if(sub_res < result)
				result = sub_res;
		}
	}
	arr[n] = result;
	return arr[n];
}
//BottomUp DP
int coinsNeededDP(int coins[], int n, int amount){
	int dp[amount+1];
	for(int i=0;i<=amount;i++)
		dp[i]=INT_MAX;
	dp[0]=0;
	for(int i=1;i<=amount;i++){
			// dp[i] =INT_MAX;
		for(int j=0;j<n;j++){
			if(i>=coins[j]){
				int smallerAns = dp[i-coins[j]]+1;

				if(smallerAns<dp[i]){
					dp[i] = smallerAns;
				}
			}
		}
	}
	return dp[amount];
}
int main(void){
	int us_coins[] = {1,7,10};
	int n=3;//no of types of coins.
	int amount =15;
	memset(arr,  -1, 10000001);
	// for(int i=0;i<10;i++)
	// 	printf("%d\n",arr[i] );
	printf("%d\n",mincointd(us_coins,3,amount) );
	printf("%d\n",coinsNeededDP(us_coins,3,amount) );
	int ind[] = {1,2,5,10,50};
	printf("%d\n",coinsNeededDP(ind,5,30) );
	printf("%d\n",coinsNeededDP(ind,5,39) );
}

/*
Valid OUTPUT:
3
3
3
6
*/