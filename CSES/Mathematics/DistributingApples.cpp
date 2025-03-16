#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define size(a)   (int)a.size()
#define len(a)    (int)a.length()
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define YN(v) cout << ((v) ? "YES" : "NO") << nl

const int MAXN = 2e6+1;
const ll MOD = 1e9+7;

vector<ll> fac(MAXN, 1);
vector<ll> inv(MAXN, 1);

ll binpow(ll x, ll n) {
    x %= MOD;
    ll res = 1;
    while(n > 0) {
        if(n % 2) res = (res*x)%MOD;
        x = (x*x)%MOD;
        n /= 2; 
    }
    return res;
}

ll binom(int n, int k) {
    return fac[n] * inv[k]%MOD * inv[n-k]%MOD;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    rep(i, 2, MAXN) {
        fac[i] = (i * fac[i-1])%MOD;
    }

    // Little fermat theorem
    inv[MAXN-1] = binpow(fac[MAXN-1], MOD-2);

    // Mod inverse of factorials with factorial definition
    // inv[i] = inverse of i! mod MOD
    for(int i = MAXN-2; i > 0; i--) {
        inv[i] = ((i+1)*inv[i+1])%MOD;
    }

    ll n, m;
    cin >> n >> m;

    cout << binom(n+m-1, n-1) << nl;
}