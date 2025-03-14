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
 
    int n;
    cin >> n;
    vi curr(n, 1e9+1);
    vi process(n);
    int res = 1;
    cin >> process[0];
    curr[0] = process[0];
    rep(i, 1, n) {
        cin >> process[i];
        auto it = upper_bound(curr.begin(), curr.end(), process[i]);
        if((it-curr.begin()) >= res) {
            curr[res] = process[i];
            ++res;
        } else {
            curr[it-curr.begin()] = process[i];
        }
    }
    cout << res << nl;
}