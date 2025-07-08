#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define size(a)   (int)a.size()
#define len(a)    (int)a.length()
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi freq(k+1, 0);
    set<ll> s;
    rep(i, 0, k+1) {
        s.insert(i);
    }
    rep(i, 0, k) {
        if(a[i] <= k) {
            ++freq[a[i]];
            if(freq[a[i]] == 1) {
                s.erase(a[i]);
            }
        }
    }

    cout << *s.begin() << " ";

    rep(i, k, n) {
        if(a[i] <= k) {
            ++freq[a[i]];
            if(freq[a[i]] == 1) {
                s.erase(a[i]);
            }
        }
        ll out = a[i-k];
        if(out <= k) {
            freq[out]--;
            if(freq[out] == 0) {
                s.insert(out);
            }
        }
        cout << *s.begin() << " ";
    }
}