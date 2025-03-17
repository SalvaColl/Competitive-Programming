#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define vi vector<ll>
#define ii pair<ll, ll>
#define F first
#define S second
 
ll max_flow(vector<vi> &adj, vector<vi> &capacity, ll source, ll sink) {
    ll n = adj.size();
    vi parent(n, -1);
    auto reachable = [&]() -> bool {
        stack<ll> q; q.push(source);
        while (!q.empty()) {
            ll node = q.top(); q.pop();
            for (auto son : adj[node]) {
                ll w = capacity[node][son];
                if (w <= 0 || parent[son] != -1) continue;
                parent[son] = node;
                q.push(son);
            }
        }
        return parent[sink] != -1;
    };
 
    ll flow = 0;
    while (reachable()) {
        ll node = sink, curr_flow = LLONG_MAX;
        while (node != source) {
            curr_flow = min(curr_flow, capacity[parent[node]][node]);
            node = parent[node];
        }
        node = sink;
        while (node != source) {
            capacity[parent[node]][node] -= curr_flow;
            capacity[node][parent[node]] += curr_flow;
            node = parent[node];
        }
        flow += curr_flow;
        fill(parent.begin(), parent.end(), -1);
    }
    return flow;
}
 
void solve() {
    ll n, m; cin >> n >> m;
    vector<vi> capacity(n, vi(n, 0));
    vector<vi> adj(n);
    REP(i,0,m) {
        ll u, v, c; cin >> u >> v >> c;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += c;
    }
    cout << max_flow(adj, capacity,0,n-1) << endl;
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}