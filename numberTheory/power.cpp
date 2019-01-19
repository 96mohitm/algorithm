#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long int

// iterative method 
int power(int x, unsigned int y){ 
    int res = 1;     // Initialize result 
   
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = res*x; 
   
        // n must be even now 
        y = y>>1; // y = y/2 
        x = x*x;  // Change x to x^2 
    } 
    return res; 
}



// recursive method
ll fastexp(ll base, ll power){
    if(power == 0)
        return 1;
    ll smallerAns = fastexp(base, power/2);
    smallerAns *= smallerAns;
    if(power&1)
        smallerAns*=base;
    smallerAns%=MOD;
    return smallerAns;
}
