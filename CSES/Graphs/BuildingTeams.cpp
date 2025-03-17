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
vector<bool> visited(100001);
vector<bool> team(100001);
bool possible = true;
 
void dfs(int u, int p = 0) {
    for(int v : adj[u]) {
        if(v != p) {
            if(!visited[v]) {
                team[v] = !team[u];
                visited[v] = true;
                dfs(v, u);
            } else if(team[v] == team[u]) {
                possible = false;
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n+1) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i);
        }
    }
    if(!possible) cout << "IMPOSSIBLE" << nl;
    else {
        rep(i, 1, n+1) {
            team[i] ? cout << 1 : cout << 2;
            cout << " ";
        }
        cout << nl;
    }
}