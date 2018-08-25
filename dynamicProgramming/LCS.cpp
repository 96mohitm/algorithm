#include <bits/stdc++.h>
using namespace std;
int arr[100][100];

//topdown recursive approach
int lcs(char str1[], char str2[], int m, int n){
	if(m==0||n==0)
		return 0;
	if(arr[m][n]!=-1)
		return arr[m][n];
	if(str1[m-1]==str2[n-1])
		arr[m][n] = 1+lcs(str1,str2,m-1,n-1);
	else
		arr[m][n] = max(lcs(str1,str2,m-1,n), lcs(str1,str2,m,n-1));
	return arr[m][n];
}

int main(void){
	char str1[10], str2[10];
	scanf("%s",str1);
	scanf("%s",str2);
	int m = strlen(str1);
	int n = strlen(str2);
	memset(arr, -1, 10000);
	printf("%d\n",lcs(str1, str2, strlen(str1), strlen(str2)));
}
