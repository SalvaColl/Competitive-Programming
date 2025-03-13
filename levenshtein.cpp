// Levenshtein distance with Dynamic Programming from CSES

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

    string a, b;
    cin >> a >> b;
    int n = len(a);
    int m = len(b);
    int dp[n+1][m+1];
    rep(i, 0, n+1) {
        dp[i][0] = i;
    }
    rep(j, 0, m+1) {
        dp[0][j] = j;
    }
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            if(a[i-1] != b[j-1]) {
                dp[i][j] = 1 + min((dp[i-1][j-1]), min(dp[i-1][j], dp[i][j-1]));
            } else {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    cout << dp[n][m] << nl;
}