/* LCS: Longest Common Subsequence.
	eg. for AGGTAB, GXTXAYB : lcs is 4 and the string is: GTAB
*/

#include <bits/stdc++.h>
using namespace std;
int arr[100][100];

//topdown recursive approach
int lcs(char str1[], char str2[], int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	if (arr[m][n] != -1)
		return arr[m][n];
	if (str1[m - 1] == str2[n - 1])
		arr[m][n] = 1 + lcs(str1, str2, m - 1, n - 1);
	else
		arr[m][n] = max(lcs(str1, str2, m - 1, n), lcs(str1, str2, m, n - 1));
	return arr[m][n];
}

// bottom up approach the efficient one.
int lcs_bottomup(char str1[], char str2[])
{
	int l1 = strlen(str1);
	int l2 = strlen(str2);
	int temp[l1 + 1][l2 + 1];
	int m = 0;
	for (int i = 0; i <= l1; i++)
		temp[i][0] = 0;
	for (int i = 0; i <= l2; i++)
		temp[0][i] = 0;

	for (int i = 1; i <= l1; i++)
	{
		for (int j = 1; j <= l2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				temp[i][j] = temp[i - 1][j - 1] + 1;
			else
				temp[i][j] = max(temp[i - 1][j], temp[i][j - 1]);
			if (m < temp[i][j])
				m = temp[i][j];
			
		}
	}
	return temp[l1][l2];
}

int main(void)
{
	char str1[10], str2[10];
	scanf("%s", str1);
	scanf("%s", str2);
	int m = strlen(str1);
	int n = strlen(str2);
	memset(arr, -1, 10000);
	printf("%d\n", lcs(str1, str2, strlen(str1), strlen(str2)));
	printf("%d\n", lcs_bottomup(str1, str2));
}
