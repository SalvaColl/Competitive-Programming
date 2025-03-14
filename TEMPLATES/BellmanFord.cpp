// Bellman-Ford template O(VE)
// Finds shortest distances from one node to the rest
// Slower than dijkstra but can detect negative cycles

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl

const int MAX_N = 1e5; // Change for problem
vi dist(MAX_N, 1e9); // Initialize every distance to infinite

void bellford(vector<vi> &edges, ll n, ll src) {
    dist[src] = 0;
    rep(i, 0, n) {
        for(vi edge : edges) {
            ll u = edge[0], v = edge[1], wt = edge[2];
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                if(i == n-1) dist[0] = -1; // Negative cycle detected
                dist[v] = dist[u] + wt;
            }
        }
    }
}