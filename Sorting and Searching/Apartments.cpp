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
    int k;
    cin >> k;
    vi desired(n);
    vi sizes(m);
    rep(i, 0, n) {
        cin >> desired[i];
    }
    rep(i, 0, m) {
        cin >> sizes[i];
    }
    order(desired);
    order(sizes);
    int i = 0;
    int j = 0;
    int res = 0;
    while(i < n && j < m) {
        if(abs(desired[i]-sizes[j]) <= k) {
            ++res;
            ++i;
            ++j;
        } else {
            if(sizes[j] > desired[i]) ++i;
            else ++j;
        }
    }
    cout << res << nl;
}