// Dijkstra template O((V + E) logV)
// Finds shortest distance from one node to the rest

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
vector<vector<pii>> adj(MAX_N); // Adjacency list
vi dist(MAX_N, LLONG_MAX); // Start every distance to infinite

void dijkstra(ll n, ll src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, src); dist[src] = 0;
    while(!pq.empty()) {
        ll u = pq.top().S; pq.pop();
        for(auto x : adj[u]){
            ll v = x.F;
            ll weight = x.S;
            if(dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.emplace(dist[v], v);
            }
        } 
    }
}