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
 
    int n, x;
    cin >> n >> x;
    vi coins(n);
    rep(i, 0, n) {
        cin >> coins[i];
    }
    order(coins);
    int dp[x+1];
    dp[0] = 0;
    rep(i, 1, x+1) {
        if(i < coins[0]) dp[i] = -1;
        int ways = 1e9;
        for(int c : coins){
            if(i >= c) {
                if(dp[i-c] != -1) {
                    ways = min(ways, dp[i-c]);
                }
            }
        }
        if(ways == 1e9) {
            dp[i] = -1;
        } else {
            dp[i] = 1 + ways;
        }
    }
    cout << dp[x];
}