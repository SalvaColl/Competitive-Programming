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
 
vi adj[100001];
vector<int> visited(100001);
vector<int> parents(100001);
 
int n, m, finish; 
int start = 0; 
 
void dfs(int u) {
    visited[u] = 1;
    for(int v : adj[u]) {
        if(!visited[v]) {
            parents[v] = u;
            dfs(v);
            if(start) return;
        } else if(visited[v] == 1) {
            finish = u;
            start = v;
            return;
        }
    }
    visited[u] = 2;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n && !start; i++)  {
        if(!visited[i]) {
            dfs(i);
        }
    }  
    if(!start) {
        cout << "IMPOSSIBLE" << nl;
        return 0;
    }
    vector<int> ans;
    ans.push_back(start);
    for(int u = finish; u != start; u = parents[u]) {
        ans.push_back(u);
    }
    ans.push_back(start);
    reverse(ans.begin(), ans.end());
    int k = size(ans);
    cout << k << nl;
    rep(i, 0, k) {
        cout << ans[i] << " ";
    }
    cout << nl;
}