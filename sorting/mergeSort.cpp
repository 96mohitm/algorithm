#include <bits/stdc++.h>
using namespace std;
//Function for merging two sorted array.
void merge(int arr[], int start, int mid, int end){
	int i,j,k;
	int l = mid-start+1;
	int r = end - mid;
	int left[l+1], right[r+1];
	//Intializing the left array.
	for(i=0;i<l;i++)
		left[i] = arr[start + i];
	left[i] = INT_MAX;
	//Intialinging the right array.
	for(j=0;j<r;j++)
		right[j] = arr[mid + j + 1];
	right[j] = INT_MAX;
	
	i=0;j=0;
	for(k=start;k<=end;k++){
		if(left[i]<right[j])
			arr[k] = left[i++];
		else
			arr[k] = right[j++];
	}
}

void mergeSort(int arr[], int start, int end){
	if(start < end){
		int mid = (start + end) >> 1;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main(void){
	int n;
	// scanf("%d",&n);
	int arr[6] = {0,5,4,3,2,1};
	// for(i=1;i<=n;i++){
	// 	scanf("%d",&arr[i]);
	// }
	mergeSort(arr,1,5);
	for(int i=1;i<6;i++) printf("%d\n",arr[i] );
}
