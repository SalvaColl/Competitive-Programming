// BFS template O(V + E)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<ll, ll>;
using vi = vector<ll>;
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

const int MAX_N = 1e5; // Change for problem
vi adj[MAX_N]; // Adjacency list
vector<bool> vis(MAX_N, 0);

void bfs (ll source) {
    queue<ll> q; q.push(source);
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (auto v: adj[u]) {
            q.push(v); vis[v] = true;
        }
    }
}