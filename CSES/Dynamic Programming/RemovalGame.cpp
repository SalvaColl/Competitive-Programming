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
 
    ll n;
    cin >> n;
    ll arr[n];
    rep(i, 0, n) cin >> arr[i];
    pair<ll, ll> dp[n][n];
    rep(i, 0, n) dp[i][i] = make_pair(arr[i], 0);
    rep(i, 1, n) {
        for(int j = 0; i+j < n; j++) {
            int r = i+j;
            int l = j;
            dp[l][r] = max(make_pair(arr[r] + dp[l][r-1].S, dp[l][r-1].F), 
                            make_pair(arr[l] + dp[l+1][r].S, dp[l+1][r].F));
        }
    }
    cout << dp[0][n-1].F << nl;
}