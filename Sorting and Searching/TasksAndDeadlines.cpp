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
 
    ll n;
    cin >> n;
 
    vector<vector<ll>> a(n, vector<ll> (2));
    rep(i, 0, n) {
        cin >> a[i][0];
        cin >> a[i][1];
    }
    order(a);
    ll score = 0;
    ll time = 0;
    rep(i, 0, n) {
        time += a[i][0];
        score += a[i][1] - time;
    }
    cout << score << nl;
}