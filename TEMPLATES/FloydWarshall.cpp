// Floyd-Warshall O(V^3)
// Finds shortest distance between every pair of vertices

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

void floyd(vector<vi> &g) {
    ll n = g.size();
    rep(k, 0, n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                if((g[i][j] == -1 || g[i][j] > (g[i][k] + g[k][j]))
                    && (g[k][j] != -1 && g[i][k] != -1)) {
                        g[i][j] = g[i][k] + g[k][j];
                    }
            }
        }
    }
}