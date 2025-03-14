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
 
ll MOD = 1e9 + 7;
 
ll mod_inv(ll a, ll m) {
    ll res = 1, p = m - 2;
    while (p) {
        if (p & 1) res = (res * a) % m;
        a = (a * a) % m;
        p /= 2;
    }
    return res;
}
 
ll catalan(ll n) {
    ll prev = 1;
    for(ll i = 1; i <= n; i++) {
        ll now = (2*(2*i-1)*prev)%MOD;
        ll den = mod_inv(i+1, MOD);
        prev = (now*den)%MOD;
    }
    return prev;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
    if(n & 1) cout << 0 << nl;
    else {
        n /= 2;
        cout << catalan(n) << nl;
    }
}