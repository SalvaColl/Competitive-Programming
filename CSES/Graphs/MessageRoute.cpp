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
 
vector<int> adj[100001];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    vector<bool> visited(n+1, false);
 
    rep(i, 0, m) {
        int u;
        int v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
 
    deque<int> queue;
    queue.push_back(1);
    visited[1] = true;
 
    vector<int> parents(n+1, -1);
 
    while(!queue.empty()) {
        int curr = queue.front();
        queue.pop_front();
        if(curr == n) {
            break;
        } else {
            for(int v : adj[curr]) {
                if(!visited[v]) {
                    visited[v] = true;
                    queue.push_back(v);
                    parents[v] = curr;
                }
            }
        }
    }
    if(!visited[n]) cout << "IMPOSSIBLE" << nl;
    else {
        vi path;
        for(int curr = n; curr != 1; curr = parents[curr]) {
            path.push_back(curr);
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        cout << size(path) << nl;
        for(int v : path) {
            cout << v << " ";
        }
        cout << nl;
    }
}