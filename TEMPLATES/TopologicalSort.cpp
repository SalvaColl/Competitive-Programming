// Topological Sort template O(V + E)

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
vector<vi> adj(MAX_N); // Adjacency list

vi toposort(ll n) {
    ll indeg[n] = {}; queue<ll> q; vi topovec;
    rep(i, 0, n) for(auto v : adj[i]) indeg[v]++;
    rep(i, 0, n) if(indeg[i] == 0) q.push(i);
    while(!q.empty()) {
        ll node = q.front(); q.pop();
        topovec.push_back(node);
        for(int v : adj[node]) if(--indeg[v] == 0) q.push(v);
    }
    return topovec;
}