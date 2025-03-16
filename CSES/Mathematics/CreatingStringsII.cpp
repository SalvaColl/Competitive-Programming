#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
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

    string a;
    cin >> a;
    ll n = a.length();
    vector<ll> need;
    vector<ll> freq(27, 0);
    rep(i, 0, n) {
        freq[a[i]-'a']++;
    }
    rep(i, 0, 27) {
        if(freq[i] != 0) need.push_back(freq[i]);
    }
    ll base = fac[n];
    rep(i, 0, need.size()) {
        base = (base*inv[need[i]])%MOD;
    }
    cout << base << nl;
}