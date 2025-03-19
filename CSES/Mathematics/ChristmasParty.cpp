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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    // A derangement is a permutation where no element is in its initial position
    ll derangements[n+1];
    derangements[1] = 0;
    derangements[2] = 1;
    for(ll i = 3; i <= n; i++) {
        derangements[i] = (((derangements[i-1] + derangements[i-2]) % MOD) * (i-1)) % MOD;
    }
    cout << derangements[n] << nl;
}