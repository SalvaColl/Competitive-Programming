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
 
    int n, x;
    cin >> n >> x;
    int a[n];
    set<int> exist;
    rep(i, 0, n) {
        cin >> a[i];
        exist.insert(a[i]);
    }
    rep(i, 0, n) {
        int target = x - a[i];
        if(exist.find(target) != exist.end()) {
            rep(k, i+1, n) {
                if(a[k] == target) {
                    cout << i+1 << " " << k+1 << nl;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << nl;
}