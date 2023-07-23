/*
    Author: Rakshith Mohan
    CF Profile - https://codeforces.com/profile/rakshith21mohan

    This is my template file for competitive programming
*/

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#include <bits/stdc++.h>
using namespace std;
 
#define mk(x, y) make_pair(x, y)
#define iloop(n) for(int i = 0; i < n; i++)
#define jloop(n) for(int j = 0; j < n; j++)
#define vin(v, n) iloop(n) { cin >> v[i]; }
#define endl '\n'
#define all(x) (x).begin(), (x).end()
 
void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cout << '{';
    __print(x.first);
    cout << ", ";
    __print(x.second);
    cout << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cout << '{';
    for (auto &i : x)
        cout << (f++ ? ", " : ""), __print(i);
    cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cout << ", ";
    _print(v...);
}
#ifdef DEBUG
#define dbg(x...)                  \
    cout << " [" << #x << "] = ["; \
    _print(x);                     \
    cout << endl;
#else
#define dbg(x)
#endif
 
typedef long long int ll;
typedef vector<vector<int>> vvi ;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
 
const int SHIFTS[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
const ll rem = 998244353;
const int nax = 2e5 + 1;
const int INF = 2e9;
const ll LINF = 1e18;
 
 
void init_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
ll binpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res = (res * a) % rem;
        }
        b >>= 1;
        a = (a * a) % rem;
    }
    return res;
}
 
 
/*
    Combinatorics
*/
 
/*
 
// make nCr table
ll nCr[nax][nax];
void make_nCr(){
    for(int i = 0; i < nax; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) nCr[i][j] = 1;
            else nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % rem;
        }
    }
}
*/
 

/*
ll fact[nax];
void make_fact(){
    fact[0] = 1;
    for(int i = 1; i < nax; i++){
        fact[i] = (fact[i - 1] * i) % rem;
    }
}
 
ll inv(ll x){
    return binpow(x, rem - 2);
}
 
ll comb(ll n, ll r){
    return fact[n] * inv(fact[n - r]) % rem * inv(fact[r]) % rem;
}
*/
 
/*
    Graphs, DFS
*/
 
/*
vi adj[nax];
int visited[nax];
 
void dfs(int i){
    visited[i] = 1;
    for(int j : adj[i]){
        if(!visited[j]){
            dfs(j);
        }
    }
}
*/
 
/*
    Prime sieve
*/
 
/*
int is_prime[nax];
vi primes;
 
void make_sieve(){
    iloop(nax) is_prime[i] = 1;
    is_prime[1] = 0;
    is_prime[0] = 0;
    for(ll i = 2; i < nax; i++){
        if(is_prime[i]){
            primes.emplace_back(i);
            for(ll j = i * i; j < nax; j += i){
                is_prime[j] = 0;
            }
        }
    }
}
*/

void solve(){
    
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}
