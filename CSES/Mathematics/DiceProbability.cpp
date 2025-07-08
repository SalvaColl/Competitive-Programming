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
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    double dp[n+1][b+1] = {};
    dp[0][0] = 1.00;
    rep(i, 1, n+1) {
        rep(j, 1, b+1) {
            rep(k, 1, 7) {
                if(j - k >= 0) {
                    dp[i][j] += dp[i-1][j-k]*(1.00/6);
                }
            }
        }
    }
    double ans = 0;
    rep(i, a, b+1) ans += dp[n][i];
    cout << setprecision(6) << fixed << ans << nl;
}