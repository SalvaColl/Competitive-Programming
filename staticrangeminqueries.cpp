// Sparse table Template for Static Range Minimum Queries (CSES)
// Preprocessing O(n log n)
// Query O(1)

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

const int MAX_N = 200005;
const int LOG = 18;
int m[MAX_N][LOG];
int a[MAX_N];

// QUERIES
int query(int L, int R) {
    int length = R - L + 1;
    int k = 31 - __builtin_clz(length);
    return min(m[L][k], m[R-(1<<k)+1][k]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    int q;
    cin >> q;

    rep(i, 0, n) {
        cin >> a[i];
        m[i][0] = a[i];
    }

    // PROCESSING SPARSE TABLE
    for(int k = 1; k < LOG; k++) {
        for(int i = 0; i + (1 << k) - 1 < n; i++) {
            m[i][k] = min(m[i][k-1], m[i + (1<<(k-1))][k-1]);
        }
    }

    // PROCESSING QUERIES
    rep(i, 0, q) {
        int L, R;
        cin >> L >> R;
        --L;
        --R;
        cout << query(L, R) << nl;
    }
}