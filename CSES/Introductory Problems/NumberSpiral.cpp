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
 
    int t;
    cin >> t;
    while(t--) {
        long long y, x;
        cin >> y >> x;
        long long res;
        if(x > y) {
            res = (x-1)*(x-1);
            if(x % 2 == 0) res += y;
            else res += (2*x-y);
        } else {
            res = (y-1)*(y-1);
            if(y % 2 != 0) res += x;
            else res += (2*y-x);
        }
        cout << res << nl;
    }
}