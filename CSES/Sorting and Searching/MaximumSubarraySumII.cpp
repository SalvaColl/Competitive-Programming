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
 
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<ll> pref(n+1);
    pref[0] = 0;
    rep(i, 1, n+1) {
        int a;
        cin >> a;
        pref[i] = pref[i-1] + a;
    }
 
    ll res = -1e9*(b+1);
    multiset<ll> ms;
 
    for(int i = a; i <= n; i++) {
        if(i > b) {
            ms.erase(ms.find(pref[i-b-1]));  
        }
        ms.insert(pref[i-a]);
        res = max(res, pref[i]-*ms.begin());
    }
    cout << res << nl;
}