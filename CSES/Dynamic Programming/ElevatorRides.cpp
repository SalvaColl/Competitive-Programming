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
 
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    rep(i, 0, n) cin >> arr[i];
 
    ll N = 1 << n;
 
    vector<pair<ll, ll>> dp(N, make_pair(LLONG_MAX, LLONG_MAX));
    dp[0] = {0, 0};
    rep(mask, 0, N) {
        rep(i, 0, n) {
            ll elem = 1 << i;
            ll newMask = mask | elem;
            if(mask & elem) continue;
            if(arr[i] + dp[mask].second <= x) {
                dp[newMask] = min(dp[newMask], {dp[mask].first, dp[mask].second + arr[i]});
            } else {
                dp[newMask] = min(dp[newMask], {dp[mask].first + 1, arr[i]});
            }
        }
    }
    cout << dp[N-1].first + 1 << nl;
}