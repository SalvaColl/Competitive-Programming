#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define size(a)   (int)a.size()
#define len(a)    (int)a.length()
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    int a[n];
    rep(i, 0, n) cin >> a[i];
    ll MOD = 1e9+7;
    ll dp[m+1][n] = {};
    if(n == 1) {
        if(a[0] != 0) cout << 1 << nl;
        else cout << m << nl;
    } else {
        if(a[0] == 0) {
            rep(i, 1, m+1) dp[i][0] = 1;
        }
        dp[a[0]][0] = 1;
        int i = 0;
        while(i < n) {
            if(a[i] != 0) {
                int up = max(a[i]-1, 1);
                int down = min(a[i]+1, m);
                for(int j = up; j <= down; j++) {
                    dp[a[i]][i] = (dp[j][i-1] + dp[a[i]][i]) % MOD;
                }
            } else {
                rep(j, 1, m+1) {
                    int up = max(j-1, 1);
                    int down = min(j+1, m);
                    for(int k = up; k <= down; k++) {
                        dp[j][i] = (dp[k][i-1] + dp[j][i]) % MOD;
                    }
                }
            }
            ++i;
        }
        ll res = 0;
        rep(i, 1, m+1) {
            res = (dp[i][n-1] + res) % MOD;
        }
        cout << res << nl;
    }
}