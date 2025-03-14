#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define size(a)   (int)a.size()
#define len(a)    (int)a.length()
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
 
    ll n;
    cin >> n;
    ll a[n];
    stack<pair<ll, int>> st;
    rep(i, 0, n) {
        cin >> a[i];
    }
    int res[n] = {};
    res[0] = 0;
    st.push({a[0], 0});
    rep(i, 1, n) {
        while(!st.empty() && st.top().first >= a[i]) {
            st.pop();
        }
        if(!st.empty()) res[i] = st.top().second + 1;
        else res[i] = 0;
        st.push({a[i], i});
    }
    rep(i, 0, n) cout << res[i] << " ";
