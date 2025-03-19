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
 
int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    ll a[k];
    rep(i, 0, k) cin >> a[i];
    ll ans = 0;
    
    // We iterate over every subset of the divisors using a bitmask
    for(ll i = 0; i < (1LL << k); i++) {
        vi subset; // Current subset
        for(ll j = 0; j < k; j++) {
            // We include an element if the corresponding bit is on in the mask
            if((i & (1 << j))) {
                subset.push_back(a[j]);
            }
        }
        ll prod = 1;
        for(int j = 0; j < subset.size(); j++) {
            // If prod is too big and the division will be zero, just break
            if(prod > n/subset[j]) {
                prod = n+1;
                break;
            }
            prod *= subset[j];
        }
        // We use inclusion-exclusion (like in the probability of the union of many events)
        if(subset.size() % 2 == 0) {
            ans -= n/prod;
        } else {
            ans += n/prod;
        }
    }
    // We subtracted n on the empty subset
    ans += n;
    cout << ans << nl;
}   