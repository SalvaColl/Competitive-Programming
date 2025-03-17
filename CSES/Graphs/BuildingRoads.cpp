#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define size(a)   (int)a.size()
#define len(a)    (int)a.length()
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
vector<int> adj[100001] = {};
 
void dfs(int v, vector<bool>& visited) {
    if(!visited[v]) {
        visited[v] = true;
        for(int u : adj[v]) {
            if(!visited[u]) dfs(u, visited);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<bool> visited(n+1, 0);
    vector<int> roads;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n+1) {
        if(!visited[i]) {
            visited[i];
            roads.push_back(i);
            dfs(i, visited);
        }
    }
    cout << size(roads)-1 << nl;
    n = size(roads);
    rep(i, 0, n-1) {
        cout << roads[i] << " " << roads[i+1] << nl;
    }
}