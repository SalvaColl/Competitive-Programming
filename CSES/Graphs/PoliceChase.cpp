#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define vvi vector<vi>
#define F first
#define S second
 
vii solution;
ll max_flow(vvi &adj, vvi &capacity, ll source, ll sink) {
    ll n = adj.size(); vi parent(n, -1); vector<bool> vis(n, false);
    auto reachable = [&]() -> bool {
        fill(all(vis), false);
        queue<ll> q; q.push(source); vis[source] = true;
        while (!q.empty()) {
            ll node = q.front(); q.pop();
            for (auto son : adj[node]) {
                ll w = capacity[node][son];
                if (w <= 0 || vis[son]) continue;
                vis[son] = true;
                parent[son] = node;
                q.push(son);
            }
        } return vis[sink];
    };
    ll flow = 0;
    while (reachable()) {
        ll node = sink, curr_flow = LLONG_MAX;
        while (node != source) {
            curr_flow = min(curr_flow, capacity[parent[node]][node]);
            node = parent[node];
        } node = sink;
        while (node != source) {
            capacity[parent[node]][node] -= curr_flow;
            capacity[node][parent[node]] += curr_flow;
            node = parent[node];
        } flow += curr_flow;
        fill(all(parent), -1);
    }
    REP(u,0,n) {
        if (vis[u]) {
            for (auto v : adj[u]) {
                if (!vis[v]) solution.emplace_back(u,v);
            }
        }
    }
    return flow;
}
 
 
void solve() {
    ll n, m; cin >> n >> m;
    vector<vi> capacity(n, vi(n, 0));
    vector<vi> adj(n);
    REP(i,0,m) {
        ll u, v; cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = 1;
        capacity[v][u] = 1;
    }
    cout << max_flow(adj, capacity,0,n-1) << endl;
    for (auto edge : solution) {
        cout << edge.F + 1 << " " << edge.S + 1 << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}