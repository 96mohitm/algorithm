#include <iostream>
using namespace std;

int A[32] = {0};
void binary(int n, int k){
	if(k==n){
		for(int i=0; i<n; i++)
			cout<<A[i];
		cout<<"\n";
		return;
	}
	nbits(n, k+1);
	A[k] = 1;
	nbits(n, k+1);
	A[k] = 0;
}
int main() {
	binary(3, 0);
	return 0;
}
/*
Output:

000
001
010
011
100
101
110
111

*/