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
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, t;
    cin >> n >> t;
    vector<ll> k(n);
    rep(i, 0, n) {
        cin >> k[i];
    }
 
    ll mmin = *min_element(k.begin(), k.end());
    ll low = 1, mid, high = t*mmin;
    ll res = LLONG_MAX;
 
    while(low <= high) {
        mid = (low+high)/2;
        ll total = 0;
        rep(i, 0, n) {
            total += mid/k[i];
        }
        if(total < t) {
            low = mid+1;
        } else {
            res = min(res, mid);
            high = mid-1;
        }
    }
    cout << res << nl;
}