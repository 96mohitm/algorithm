#include <bits/stdc++.h>
//Knuth–Morris–Pratt algorithm is used for pattern searching in a string

/*
first we make lps of the pattern that we want to fing in the string
*/
using namespace std;
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

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