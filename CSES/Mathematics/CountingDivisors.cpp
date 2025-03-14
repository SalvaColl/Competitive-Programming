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
 
    int t;
    cin >> t;
    ll dp[1000001] = {};
    while(t--) {
        ll n;
        cin >> n;
        ll temp = n;
        if(dp[n] != 0) cout << dp[n] << nl;
        else {
            ll total = 1;
            for(ll i = 2; i*i <= n; i++) {
                if(n % i == 0) {
                    ll e = 0;
                    do {
                        e++;
                        n /= i;
                    } while (n % i == 0);
                    total *= e + 1;
                }
            }
            if(n > 1) {
                total *= 2;
            }
            dp[temp] = total;
            cout << total << nl;
        }
    }
}