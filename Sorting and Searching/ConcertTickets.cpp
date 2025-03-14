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
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    multiset<int> prices;
    int h, t;
    rep(i, 0, n) {
        cin >> h;
        prices.insert(h);
    }
    rep(i, 0, m) {
        cin >> t;
        auto it = prices.upper_bound(t);
		if (it == prices.begin()) {
			cout << -1 << "\n";
		} else {
			cout << *(--it) << "\n";
			prices.erase(it);
		}
    }
}