// with no duplicates.
#include <bits/stdc++.h>
using namespace std;

void permute(string s, int l, int r){
    if(l==r){
        cout<<s<<"\n";
    }
    else{
        for(int i=l; i<=r; i++){
            swap(s[l], s[i]);
            permute(s, l+1, r);
            swap(s[i], s[l]);
        }
    }
}
void right_rotate(string &s, int l, int r){
    if(l==r) return;
    char c = s[r];
    for(int i=l; i<=r; i++){
        char temp = s[i];
        s[i] = c;
        c = temp;
    }
}
void left_rotate(string &s, int l, int r){
    if(l==r) return;
    char c = s[l];
    for(int i=r; i>=l; i--){
        char temp = s[i];
        s[i] = c;
        c = temp;
    }
}
void permute_lexi(string &s, int l, int r){
    if(l==r)
        cout<<s<<"\n";
    else{
        for(int i=l; i<=r; i++){
            right_rotate(s, l,i);
            permute_lexi(s, l+1, r);
            left_rotate(s, l, i);
        }
    }
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    permute(s, 0, n-1);
    permute_lexi(s, 0, n-1);
}

// ABC
// BAC
// ABC
// ACB
// ABC
// BAC
// BCA
// BCA
// CBA
// CAB