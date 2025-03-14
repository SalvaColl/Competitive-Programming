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
 
ll MOD = 1e9+7;
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    rep(i, 0, n) {
        ll a, b, c;
        cin >> c >> a >> b;
        ll res = 1;

        // First we calculate the exponent in mod MOD-1
        // Binary exponentiation
        a %= (MOD-1);
        while(b > 0) {
            if(b % 2 == 1) res = (res * a) % (MOD-1);
            a = (a * a) % (MOD-1);
            b /= 2;
        }

        // Then just raise the base to that exponent
        ll ans = 1;
        while(res > 0) {
            if(res % 2 == 1) ans = (ans * c) % MOD;
            c = (c*c) % MOD;
            res /= 2;
        }
        cout << ans << nl;
    }
}