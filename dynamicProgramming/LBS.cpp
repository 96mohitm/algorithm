#include <bits/stdc++.h>
using namespace std;

int lbs(vector<int> a){
	int n = a.size();
	vector<int> lis(n, 1), lds(n,1);

	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(a[i] > a[j])
				lis[i] = max(lis[i], lis[j] + 1);
		}
	}

	for(int i=n-2; i>=0; i--){
		for(int j=n-1; j>i; j--){
			if(a[i] > a[j])
				lds[i] = max(lds[i], lds[j] + 1);
		}
	}

	transform(lis.begin(), lis.end(), lds.begin(), lis.begin(), plus<int>());

	int r = *max_element(lis.begin(), lis.end()) - 1;

	return r;
}

int main(void){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<lbs(a)<<"\n";
}

/*
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
*/
