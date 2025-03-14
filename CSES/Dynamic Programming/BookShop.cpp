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
    int prices[n];
    int pages[n];
    rep(i, 0, n) cin >> prices[i];
    rep(i, 0, n) cin >> pages[i];
    int dp[n+1][x+1] = {};
    rep(i, 1, n+1) {
        rep(j, 0, x+1) {
            if(j - prices[i-1] >= 0) {
                dp[i][j] = max(dp[i-1][j-prices[i-1]] + pages[i-1], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][x] << nl;
}