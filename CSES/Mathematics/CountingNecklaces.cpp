#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using str = string;
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vii = vector<pair<long long, long long>>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
#pragma GCC optimize "-O3"

const ll MOD = 1e9+7;

ll binpow(ll a, ll e) {
    ll r = 1;
    while(e) {
        if(e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n, m;
    cin >> n >> m;
    
    // Burnside's lemma
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ans = (ans + binpow(m, __gcd(i, n))) % MOD;
    }
    ans = (ans * binpow(n, MOD-2)) % MOD;
    cout << ans << endl;
}