/*
Given two strings str1 and str2 and below operations
that can performed on str1. 
Find minimum number of edits (operations) required
to convert ‘str1’ into ‘str2’.

1. Insert
2. Remove
3. Replace
All of the above operations are of equal cost.

*/
#include <bits/stdc++.h>
using namespace std;

int min3(int x,int y,int z){
    return min(min(x,y),z);
}
// bottom-up approach.
int edit_distance(string s1, string s2, int n, int m){
    if(n==0)
        return m;
    else if(m==0)
        return n;
    else if(s1[n-1] == s2[m-1])
        return edit_distance(s1,s2,n-1,m-1);
    else{
        return 1 + min3(edit_distance(s1,s2,n-1,m),
                        edit_distance(s1,s2,n,m-1),
                        edit_distance(s1,s2,n-1,m-1));
    }
}

// top-down approach.
int edit_distance_topdown(string s1, string s2, int l1, int l2){
    int dp[l1+ 1][l2+1];
    for(int i=0; i<=l1; i++){
        for(int j=0; j<=l2; j++){
            if(i==0)
                dp[i][j] = j;
            else if(j==0)
                dp[i][j] = i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1 + min3(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    return dp[l1][l2];
}
int main(void){
    string s1, s2;
    cin>>s1>>s2;
    // cout<<s1<<s2;
    int l1,l2;
    l1=s1.length();
    l2=s2.length();
    cout<<edit_distance(s1,s2,l1,l2)<<"\n";
    cout<<edit_distance_topdown(s1,s2,l1,l2)<<"\n";
}
