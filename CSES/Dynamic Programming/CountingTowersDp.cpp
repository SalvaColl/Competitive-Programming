// Check CountingTowersMatrixExp for a faster solution
// This one is O(n)
// With matrix exponentiation it is O(log n)

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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll MOD = 1e9 + 7;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long dp1[n+1] = {};
        dp1[0] = 0;
        dp1[1] = 1;
        long long dp2[n+1] = {};
        dp2[0] = 0;
        dp2[1] = 1;
        rep(i, 2, n+1) {
            dp1[i] = 4*dp1[i-1]+dp2[i-1];
            dp2[i] = 2*dp2[i-1]+dp1[i-1];
            dp1[i] %= MOD;
            dp2[i] %= MOD;
        }
        cout << (dp1[n]+dp2[n])%MOD << nl;
    }
}