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
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
#pragma GCC optimize "O3"
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll x, n; cin >> x >> n;
    set<pair<ll, ll>> ranges;
    multiset<ll> dist;
    ranges.insert(make_pair(0, x));
    dist.insert(x);
 
    rep(i, 0, n) {
        ll pos; cin >> pos;
        auto it = ranges.upper_bound(make_pair(pos, -1));
        pair<ll, ll> cur = *(--it);
        ll start = cur.F, end = cur.S;
        
        ranges.erase(it);
        dist.erase(dist.find(end-start));
 
        ranges.insert(make_pair(start, pos));
        dist.insert(pos - start);
 
        ranges.insert(make_pair(pos, end));
        dist.insert(end - pos);
 
        cout << ((*(--dist.end()))) << " ";
    }
}