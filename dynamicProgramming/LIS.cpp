#include <bits/stdc++.h>
using namespace std;
// this n^2 complexity.
int lis(vector<int> &v){
    int n = v.size();
    vector<int> t(n,1);
    int m=0;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[i]>v[j])
                t[i] = max(t[i], t[j]+1);
        }
        if(m<t[i])
            m = t[i];
    }
    return m;
}

int ceilIndex(vector<int> &v, vector<int> &t, int end, int s){
    int start = 0;
    int middle;
    int len = end;
    while(start <= end){
        middle = (start + end)/2;
        if(middle < len && v[t[middle]] < s && s <= v[t[middle+1]])
            return middle+1;
        else if(v[t[middle]] < s)
            start = middle +1;
        else
            end = middle-1;
    }
    return -1;
}

// this is nlogn complexity.
int lis_nlogn(vector<int> &v){
    int n = v.size();
    vector<int> t(n), r(n,-1);
    t[0]=0;
    int len = 0;
    for(int i=1; i<n; i++){
        if(v[t[0]] > v[i]){
            t[0] = i;
        }
        else if(v[t[len]] < v[i]){
            len++;
            t[len] = i;
            r[i] = t[len-1];
        }
        else{
            int index = ceilIndex(v, t, len, v[i]);
            t[i] = i;
            r[i] = t[i-1];
        }
    }
    // this prints increasing subsequence in reverse order.
    cout<<"LIS\n";
    int index = t[len];
    while(index!=-1){
        cout<<v[index]<<" ";
        index = r[index];
    }
    cout<<"\n";
    return len+1;
}

int main(void){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<lis(v)<<"\n";
    cout<<lis_nlogn(v)<<"\n";
}