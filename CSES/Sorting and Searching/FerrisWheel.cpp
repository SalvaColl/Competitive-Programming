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
 
    int n, x;
    cin >> n >> x;
    vi weights(n);
    rep(i, 0, n) {
        cin >> weights[i];
    }
    order(weights);
    int res = 0;
    int i = 0;
    int j = n-1;
    while(i <= j) {
        if(weights[i] + weights[j] <= x) {
            ++res;
            ++i;
            --j;
        } else {
            ++res;
            --j;
        }
    }
    cout << res << nl;
}