#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using str = string;
using pii = pair<long long, long long>;
using vi = vector<long long>;
using vii = vector<pair<long long, long long>>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define rep(i, a, n) for(int i = a; i < n; i++)
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
 
    int n;
    cin >> n;
    vi ans(n);
    vector<pair<pii, ll>> v(n);
    rep(i, 0, n) {
        cin >> v[i].F.F >> v[i].F.S;
        v[i].S = i;
    }
    order(v);
 
    ll last = 0;
    // {departure, room}
    priority_queue<pii> pq; // We use negative values to make top be the minimum instead of the maximum
    rep(i, 0, n) {
        if(pq.empty() || -pq.top().F >= v[i].F.F) {
            // If the room is empty or no one is leaving
            last++;
            pq.emplace(-v[i].F.S, last);
            ans[v[i].S] = last;
        } else {
            // Replace the one leaving (put someone in the same room)
            pii mn = pq.top();
            pq.pop();
            pq.emplace(-v[i].F.S, mn.S);
            ans[v[i].S] = mn.S;
        }
    }
    cout << last << nl;
    rep(i, 0, n) cout << ans[i] << " ";
    cout << nl;
}