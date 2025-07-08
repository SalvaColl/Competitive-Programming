#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using str = string;
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vii = vector<pair<long long, long long>>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
#define ll unsigned long long

const ll MOD = 1e9+7;

ll modMul(ll a, ll b, ll MOD) {
    ll r = 0;
    a %= MOD;
    b %= MOD;
    while(b) {
        if(b & 1) {
            r = (r + a) % MOD;
        }
        a = (a+a)%MOD;
        b >>= 1;
    }
    return r;
}

ll binpow(ll a, ll e, ll MOD) {
    ll r = 1;
    a %= MOD;
    while(e) {
        if(e & 1) r = modMul(r, a, MOD);
        a = modMul(a, a, MOD);
        e >>= 1;
    }
    return r;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll n;
    cin >> n;
    ll a = binpow(2, n*n, MOD);
    ll b;
    ll c;
    if(n % 2 == 0) {
        b = binpow(2, n*n/4, MOD);
        c = binpow(2, n*n/2, MOD);
    } else {
        b = (binpow(2, (n*n-1)/4, MOD) * 2) % MOD;
        c = (binpow(2, (n*(n-1))/2, MOD) * binpow(2, n/2 + 1, MOD)) % MOD;
    }
    ll d = b;
    cout << (a+b+c+d) % MOD * 250000002 % MOD << nl;
}  