#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define F first
#define S second
 
vii solution;
ll max_flow(vector<vi> &adj, vector<vi> &capacity, ll source, ll sink) {
    ll n = adj.size();
    vi parent(n, -1);
    solution.clear();
 
    auto reachable = [&]() -> bool {
        queue<ll> q; q.push(source);
        while (!q.empty()) {
            ll node = q.front(); q.pop();
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
 
    vector<bool> vis(n, false); vis[source] = true;
    queue<ll> q; q.push(source);
    while (!q.empty()) {
        ll node = q.front(); q.pop();
        for (auto son : adj[node]) {
            if (capacity[node][son] <= 0 || vis[son]) continue;
            vis[son] = true; q.push(son);
        }
    }
    REP(u,0,n) {
        if (!vis[u]) continue;
        for (auto v : adj[u]) {
            if (!vis[v]) solution.emplace_back(u,v);
        }
    }
    return flow;
}
 
void solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll part = n+1, total = n+m+2;
    vector<vi> capacity(total, vi(total, 0));
    vector<vi> adj(total);
    ll source = 0, drain = total - 1;
 
    REP(i,0,k) {
        ll boy, girl; cin >> boy >> girl;
        if (capacity[boy][n + girl] == 1) continue;
        adj[boy].push_back(n + girl);
        adj[n + girl].push_back(boy);
        capacity[boy][n + girl] = 1;
    }
    REP(boy,1,part) {
        adj[source].push_back(boy);
        capacity[source][boy] = 1;
    }
    REP(girl,part,drain) {
        adj[girl].push_back(drain);
        capacity[girl][drain] = 1;
    }
 
    cout << max_flow(adj, capacity, source, drain) << endl;
    REP(boy,1,part) {
        for (auto girl : adj[boy]) {
            if (capacity[boy][girl] == 0) {
                cout << boy << " " << girl - n << endl;
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}