#include <bits/stdc++.h>
//Knuth–Morris–Pratt algorithm is used for pattern searching in a string

/*
first we make lps of the pattern that we want to fing in the string
*/
using namespace std;
vector<int> prefix_function(string s){
	int n = (int)s.length();
	vector<int> pi(n);
	for(int i =1;i<n;i++){
		int j=pi[i-1];
		while(j>0 && s[i]!=s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i]=j;
	}
	return pi;
}

void kmp(string pat, string txt){
	int m = pat.length();
	int n = txt.length();

	vector<int> lps = prefix_function(pat);
	int i=0,j=0;
	while(i<n){
		if(pat[j]==txt[i]){
			i++;
			j++;
		}
		if(j==m){
			printf("Found pattern at index at %d\n",i-j);
			j = lps[j-1];
		}
		//mismatch after j matches
		else if(i<n && pat[j]!=txt[i]){
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
	}
}

int main(void){
	int t;
	cin>>t;
	while(t--){
		string pat,txt;
		cin>>pat>>txt;
		kmp(pat, txt);
	}
}