#include <bits/stdc++.h>
using namespace std;

int maxCross(int a[], int s, int m, int e){
	int left, right, sum;
	left = right = INT_MIN;
	sum=0;
	for(int i=m;i>=s;i--){
		sum+=a[i];
		if(sum>left)
			left=sum;
	}
	sum=0;
	for(int i=m+1;i<=e;i++){
		sum+=a[i];
		if(sum>right)
			right=sum;
	}
	return (left+right);

}

int maxsubarry(int a[], int s, int e){
	if(s==e)
		return a[s];
	
		int mid = (s+e)>>1;
	return max(
		max(maxsubarry(a,s,mid),maxsubarry(a,mid+1,e)),
		maxCross(a,s,mid,e));
}

int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int m = maxsubarry(a,0,n-1);
	printf("%d\n",m );
}