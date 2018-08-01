#include <bits/stdc++.h>
using namespace std;
//checking the particular cell is safe or not.
bool issafe(int n, int b[][10], int row, int col){
	//checking for vertical upward.
	for(int i=row-1;i>=0;i--){
		if(b[i][col]) return false;
	}
	//checking for diagonally upward left
	int i=row-1,j=col-1;
	while(i>=0&&j>=0){
		if(b[i][j]) return false;
		i--;j--;
	}
	//checking for diagonally upward right
	i=row-1;j=col+1;
	while(i>=0 && j<n){
		if(b[i][j]) return false;
		i--;
		j++;
	}
	return true;
}
// resursive function for backtracking, crow = current row
bool queen(int n, int b[][10], int crow){
	//base case when we have inserted queens in all the rows.
	if(n==crow){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(b[i][j]==0) printf("_ ");
				else printf("Q ");
			}
			printf("\n");
		}
		printf("\n");
		//changing this to ture will print only the first comfiguration of board.
		return false;
	}
	for(int i=0;i<n;i++){
		if(issafe(n, b, crow, i)){
			b[crow][i] = 1;
			if(queen(n,b,crow+1))
				return true;

			b[crow][i]=0;
		}
	}
	return false;
}

int main(void){
	//n is the size of chess board.
	int n;
	printf("Enter the size of chess board.\n");
	scanf("%d",&n);
	int b[n][10] = {0};
	queen(n, b, 0);
}