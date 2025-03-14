#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
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
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    map<ll, ll> mp;
    ll diff = 0;
    ll i = 0;
    ll j = 0;
    ll res = 0;
    while(j < n) {
        if(mp.find(a[j]) == mp.end() || mp[a[j]] == 0) ++diff;
        ++mp[a[j]];
        while(diff > x) {
            mp[a[i]]--;
            if(mp[a[i]] == 0) --diff;
            ++i;
        }
        res += j-i+1;
        ++j;
    }
    cout << res << nl;
