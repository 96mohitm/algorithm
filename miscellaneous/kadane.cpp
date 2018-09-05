/*
The most efficient algo for computing the max subarry.
Here we need to maintain two variable:
current sum and max sum.
*/

//kadane's function
#include <bits/stdc++.h>
using namespace std;
int maxsubarry(int a[], int n){
	int cs =0, ms = INT_MIN;
	for(int i=0;i<n;i++){
		cs+=a[i];
		ms = max(ms, cs);
		if(cs<0)
			cs=0;
	}
	return ms;
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int m = maxsubarry(a,n);
	printf("%d\n",m );
}