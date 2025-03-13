// Polygon Area by points template O(n)
// Must have the points in polar order first

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
#define F first
#define S second
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

    int n;
    cin >> n;
    ll a = 0;
    vector<pair<ll, ll>> points(n);
    rep(i, 0, n) cin >> points[i].F >> points[i].S;
    rep(i, 0, n) {
        int j = (i+1) % n;
        a += points[i].F * points[j].S - points[i].S * points[j].F;
    }   
    cout << abs(a) << nl;
}