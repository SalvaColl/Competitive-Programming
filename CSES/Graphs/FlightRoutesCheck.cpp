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
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
#define pb push_back
 
vi adj[100005][2];
bool vis[100005];
 
void dfs(int v, int x) {
	vis[v] = true;
	for (int to : adj[v][x]) {
		if (!vis[to]) { dfs(to, x); }
	}
}
 
int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u][0].pb(v);
		adj[v][1].pb(u);
	}
	dfs(0, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';
			cout << 1 << " " << i + 1 << '\n';
			return 0;
		}
	}
	memset(vis, false, sizeof(vis));  // Fill vis with false
	dfs(0, 1);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			cout << "NO" << '\n';
			cout << i + 1 << " " << 1 << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
}