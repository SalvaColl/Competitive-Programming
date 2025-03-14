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
    rep(i, 0, n) cin >> a[i];
    int i = 0;
    int j = 1;
    ll res = 0;
    int curr = a[0];
    if(curr == x) ++res;
    curr += a[1];
    while(j < n) {
        if(curr == x) {
            ++res;
            ++j;
            curr += a[j];
        } else if(curr > x) {
            if(j != i) {
                curr -= a[i];
                ++i;
            } else {
                ++j;
                ++i;
                curr = a[j];
            }
        } else {
            ++j;
            curr += a[j];
        }
    }
    cout << res << nl;
}