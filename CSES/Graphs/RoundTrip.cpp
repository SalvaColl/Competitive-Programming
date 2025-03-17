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
vector<int> res;
vector<int> parents(100001);
 
int n, m;
bool possible = false;
 
void dfs(int u, int parent = 0) {
    if(possible) return;
    for(int v : adj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            parents[v] = u;
            dfs(v, u);
        } else if(v != parent) {
            if(possible) return;
            parents[v] = u;
            res.push_back(v);
            possible = true;
            return;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n+1) {
        if(!visited[i] && !possible) {
            visited[i] = true;
            dfs(i);
        }
    }    
    if(!possible) cout << "IMPOSSIBLE" << nl;
    else {
        vector<int> ans;
        ans.push_back(res[0]);
        ans.push_back(parents[res[0]]);
        int curr = parents[res[0]];
        while(curr != res[0]) {
            ans.push_back(parents[curr]);
            curr = parents[curr];
        }
        int l = size(ans);
        cout << l << nl;
        for(int i = l-1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << nl;
    }
}