#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
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
    vector<pair<ll, ll>> movies(n);
    rep(i, 0, n) {
        cin >> movies[i].S >> movies[i].F;
    }
    order(movies);
    ll res = 0;
    multiset<ll> watching; // Stores the end times of currently watched movies
    rep(i, 0, n) {
        auto it = watching.upper_bound(movies[i].S); // Find the first movie that ends before movies[i] starts
 
        if (it != watching.begin()) {  
            // A movie can be replaced, remove the one that ends the earliest
            watching.erase(--it);
        }
        if (watching.size() < k) {  
            // If we have space, watch this movie
            watching.insert(movies[i].F);
            ++res;
        }
    }
    cout << res << nl;
}