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
 
    ll n, x;
    cin >> n >> x;
    vector<ll> nums(n);
    rep(i, 0, n) {
        cin >> nums[i];
    }
 
    map<ll, ll> freq;
 
    vector<ll> pref(n+1);
    pref[0] = 0;
    ++freq[0];
    ll res = 0;
    rep(i, 1, n+1) {
        pref[i] = nums[i-1] + pref[i-1];
        ll target = pref[i] - x;
        res += freq[target];
        ++freq[pref[i]];
    }
    cout << res << nl;
}
