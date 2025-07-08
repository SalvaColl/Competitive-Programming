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

// Miller-Rabin primality test
bool isPrime(ll n) {
    if(n < 2) return false;
    for(ll p : {2, 3, 5, 7, 11, 13, 17}) {
        if(n % p == 0) {
            return n == p;
        }
    }

    ll d = n-1;
    int r = 0;
    while((d & 1) == 0) {
        d >>= 1;
        ++r;
    }

    for(ll a : {2, 3, 5, 7, 11}) {
        if(a >= n) continue;
        ll x = binpow(a, d, n);
        if(x == 1 || x == n-1) continue;

        bool ok = false;
        rep(i, 0, r-1) {
            x = modMul(x, x, n);
            if(x == n-1) {
                ok = true;
                break;
            }
        }
        if(!ok) return false;
    }
    return true;
}

ll nextPrime(ll n) {
    ++n;
    while(!isPrime(n)) ++n;
    return n;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        cout << nextPrime(n) << nl;
    }
}  