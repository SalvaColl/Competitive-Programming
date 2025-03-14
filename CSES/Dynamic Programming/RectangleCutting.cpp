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
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int a, b;
    cin >> a >> b;
 
    int dp[a+1][b+1] = {};
    rep(i, 1, a+1) {
        rep(j, 1, b+1) {
            dp[i][j] = 1e9;
            if(i == j) dp[i][j] = 0;
        }
    }
    rep(i, 1, a+1) {
        rep(j, 1, b+1) {
            if(i == j) continue;
            int minA = min(10000000, dp[i][j]);
            int minB = min(10000000, dp[i][j]);
            rep(k, 1, i) {
                minA = min(minA, dp[k][j]+dp[i-k][j]);
            }
            rep(k, 1, j) {
                minB = min(minB, dp[i][k]+dp[i][j-k]);
            }
            dp[i][j] = 1 + min(minA, minB);
        }
    }
    cout << dp[a][b] << nl;
}