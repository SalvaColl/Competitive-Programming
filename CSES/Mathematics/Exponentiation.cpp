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
 
    ll MOD = 1e9+7;
    int n;
    cin >> n;
    rep(i, 0, n) {
        ll a, b;
        cin >> a >> b;
        ll res = 1;
        a %= MOD;
        if(b == 0) cout << 1 << nl;
        else if(a == 0) cout << a << nl;
        else {
            while(b > 0) {
                if(b % 2 == 1) {
                    res = (res * a) % MOD;
                }
                b /= 2;
                a = (a*a) % MOD;
            }
            cout << res << nl;
        }
    }
}