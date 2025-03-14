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
 
    int n;
    cin >> n;
    ll MOD = 1e9 + 7;
    long long dp[n][n] = {};
    char mp[n][n];
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> mp[i][j];
        }
    }
    dp[0][0] = 1;
    rep(i, 0, n) {
        rep(j, 0, n) {
            if(i-1 >= 0 && mp[i-1][j] != '*') dp[i][j] += dp[i-1][j];
            dp[i][j] %= MOD;
            if(j-1 >= 0 && mp[i][j-1] != '*') dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    if(mp[n-1][n-1] == '*') cout << 0 << nl;
    else cout << dp[n-1][n-1] << nl;
}