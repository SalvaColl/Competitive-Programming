#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
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
 
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vll nums(n);
    nums[0] = x;
    rep(i, 1, n) {
        nums[i] = (a*nums[i-1]+b)%c;
    }

    vll pref(n);
    rep(i, 0, n) {
        if(i % k == 0) {
            pref[i] = nums[i];
        } else {
            pref[i] = pref[i-1] | nums[i];
        }
    }

    vll suff(n);
    for(int i = n-1; i >= 0; i--) {
        if(i == n-1 || i % k == k-1) {
            suff[i] = nums[i];
        } else {
            suff[i] = suff[i+1] | nums[i];
        }
    }

    ll total = 0;
    for(int i = 0; i+k-1 < n; i++) {
        ll window = suff[i] | pref[i+k-1];
        total ^= window;
    }
    cout << total << nl;
}