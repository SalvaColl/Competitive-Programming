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
 
    int n, x;
    cin >> n >> x;
    ll MOD = 1e9 + 7;
    vi coins(n);
    rep(i, 0, n) cin >> coins[i];
    int dp[x+1] = {};
    dp[0] = 1;
    order(coins);
    for(int c : coins) {
        rep(i, 1, x+1) {
            if(i-c >= 0) dp[i] += dp[i-c];
            dp[i] %= MOD;
        }
    }
    cout << dp[x] << nl;
}