// Sparse Table template O(n log n / 1)
// For queries  

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl

struct SparseTable {
    vector<vi> st; vi lg; ll n;
    SparseTable(vi &arr) {
        n = arr.size(); ll mxlog = log2(n) + 1;
        st.assign(n, vi(mxlog)); lg.resize(n+1);
        rep(i, 2, n+1) lg[i] = lg[i/2] + 1;
        rep(i, 0, n) st[i][0] = arr[i];
        rep(j, 1, mxlog) {
            for(ll i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = combine(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    // Change the return statement for max, gcd, product, sum...
    ll combine(ll a, ll b) {return min(a, b);} // Can be changed for other operations
    ll query(ll l, ll r) {
        ll j = lg[r-l+1];
        return combine(st[l][j], st[r - (1 << j) + 1][j]);     
    }
};