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
using ii = pair<long long, long long>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
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
 
ll MAX_N = 100005;
vi dist(MAX_N, LLONG_MAX);
 
void dijkstra(vector<vii> &adj, ll n, ll src) {
    priority_queue<ii, vii, greater<ii>> pq;
    pq.emplace(0, src); dist[src] = 0;
    while(!pq.empty()) {
        ll u = pq.top().S; 
        ll curr = pq.top().F;
        pq.pop();
 
        if(curr != dist[u]) continue;
 
        for(auto x : adj[u]) {
            ll v = x.F;
            ll weight = x.S;
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m;
    cin >> n >> m;
 
    vector<vii> adj(n+1);
 
    rep(i, 0, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
 
    dijkstra(adj, n, 1);
 
    rep(i, 1, n+1) {
        cout << dist[i] << " ";
    }
    cout << nl;
}