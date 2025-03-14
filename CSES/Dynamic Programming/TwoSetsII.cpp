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
 
    ll MOD = 1e9 + 7;
    ll n;
    cin >> n;
    ll sum = n*(n+1)/2;
    if(sum&1) cout << 0 <<nl;
    else {
        sum /= 2;
        ll dp[sum+1] = {};
        dp[0] = 1;
        rep(i, 2, n+1) {
            for(int j = sum; j >= i; j--) {
                dp[j] = (dp[j-i] + dp[j])%MOD;
            }
        }
        cout << dp[sum] << nl;
    }
}