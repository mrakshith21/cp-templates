#include <bits/stdc++.h>

using namespace std;

long long int f(long long int pnt){
    // return the value of the function at this pnt
}

double f(double pnt){
    // return the value of the function at this pnt
}

double check(double val){
    // return whether val satifies the condition
}

/*

Ternary search implementation
    First two are for long long integers
    Next two are for doubles

*/

// decrease first then increase, find min val
long long int ternary_search_concave(long long int l, long long int r){
    while(r - l > 2){
        long long int m1 = l + (r - l) / 3;
        long long int m2 = r - (r - l) / 3;
        if(f(m1) < f(m2)){
            r = m2;
        }
        else{
            l = m1;
        }
    }
    long long int ans = LONG_MAX;
    for(long long int i = l; i <= r; i++)
        ans = min(ans, f(i));
    return ans;
}

// increase first then decrease, find max val
long long int ternary_search_convex(long long int l, long long int r){
    while(r - l > 2){
        long long int m1 = l + (r - l) / 3;
        long long int m2 = r - (r - l) / 3;
        if(f(m1) < f(m2)){
            l = m1;
        }
        else{
            r = m2;
        }
    }
    long long int ans = LONG_MIN;
    for(long long int i = l; i <= r; i++)
        ans = max(ans, f(i));
    return ans;
}

// decrease first then increase, find min val
double ternary_search_concave(double l, double r, double eps){
    while(r - l > eps){
        long long int m1 = l + (r - l) / 3;
        long long int m2 = r - (r - l) / 3;
        if(f(m1) < f(m2)){
            r = m2;
        }
        else{
            l = m1;
        }
    }
    return f(r); // not entirely sure
}

// increase first then decrease, find max val
double ternary_search_convex(double l, double r, double eps){
    while(r - l > eps){
        long long int m1 = l + (r - l) / 3;
        long long int m2 = r - (r - l) / 3;
        if(f(m1) < f(m2)){
            l = m1;
        }
        else{
            r = m2;
        }
    }
    return f(l);
}

/*
    * refer https://codeforces.com/blog/entry/63085
    * for increasing function
    * IT_CNT should be chosen while balancing precision and runtime
*/
void binary_search_real_values(){
    const int MIN_VAL = 0, MAX_VAL = 1e18, IT_CNT = 200, eps = 1e-9;
    double l = MIN_VAL, r = MAX_VAL;
    for(int it = 0; it < IT_CNT and r - l > eps; it++){
        double mid = l + (r - l) / 2;
        if(check(mid))
            l = mid;
        else    
            r = mid;
    }
}
