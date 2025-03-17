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
 
void floyd(vector<vi>& g) {
    ll n = size(g);
    rep(k, 1, n) {
        rep(i, 1, n) {
            rep(j, 1, n) {
                if((g[i][j] == -1 || g[i][j] > (g[i][k] + g[k][j])) 
                    && (g[k][j] != -1 && g[i][k] != -1)) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m, q;
    cin >> n >> m >> q;
 
    vector<vi> g(n+1, vi(n+1, -1));
 
    rep(i, 1, n+1) {
        g[i][i] = 0;
    }
 
    rep(i, 0, m) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u][v] = (g[u][v] == -1) ? w : min(g[u][v], w);
        g[v][u] = (g[v][u] == -1) ? w : min(g[v][u], w);
    }
 
    floyd(g);
 
    rep(i, 0, q) {
        ll a, b;
        cin >> a >> b;
        cout << g[a][b] << nl;
    }
}