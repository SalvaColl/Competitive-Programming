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
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> projects;
    rep(i, 0, n) {
        ll a, b, c;
        cin >> a >> b >> c;
        projects.push_back(make_pair(b, make_pair(a, c)));
    }
    order(projects);
 
    vector<ll> dp(n+1, 0);
    rep(i, 1, n+1) {
        ll start = (projects[i-1].S).F, rew = (projects[i-1].S).S;
        ll pos = lower_bound(projects.begin(), projects.end(), make_pair(start, make_pair(0LL, 0LL))) - projects.begin();
        dp[i] = max(dp[i-1], dp[pos] + rew);
    }
    cout << dp[n] << nl;
}