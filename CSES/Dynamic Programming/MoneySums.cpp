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
    vector<ll> coins(n);
    rep(i, 0, n) cin >> coins[i];
    order(coins);
    bitset<100001> dp = {};
    dp[0] = 1;
    for(ll coin : coins) {
        for(int j = 100001; j >= coin; j--) {
            dp[j] = (dp[j-coin] | dp[j]);
        }
    }
    cout << dp.count()-1 << nl;
    rep(i, 1, 100001) {
        if(dp[i]) cout << i << " ";
    }
}