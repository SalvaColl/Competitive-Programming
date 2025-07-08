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

const ll MOD = 1e9+7;

ll modInv(ll a, ll m) {
    ll res = 1, p = m - 2;
    while (p) {
        if (p & 1) res = (res * a) % m;
        a = (a * a) % m;
        p /= 2;
    }
    return res;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
        a[i]--;
    }
    vi vis(n, 0);
    ll ans = 1;
    rep(i, 0, n) {
        if(!vis[i]) {
            int cur = i, len = 0;
            do {
                vis[cur] = 1;
                cur = a[cur];
                ++len;
            } while(cur != i);
            ll g = gcd(ans, len);
            ans = ans*modInv(g, MOD)%MOD;
            ans = ans * (len % MOD) % MOD;
        }
    }
    cout << ans << nl;
}