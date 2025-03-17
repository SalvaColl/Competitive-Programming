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
 
bool visited[1001][1001] = {};
 
int res = 0;
 
void dfs(int i, int j, vector<vector<char>>& grid, int n, int m) {
    if(visited[i][j]) return;
    visited[i][j] = true;
    if(i+1 < n && grid[i+1][j] != '#') dfs(i+1, j, grid, n, m);
    if(i-1 >= 0 && grid[i-1][j] != '#') dfs(i-1, j, grid, n, m);
    if(j+1 < m && grid[i][j+1] != '#') dfs(i, j+1, grid, n, m);
    if(j-1 >= 0 && grid[i][j-1] != '#') dfs(i, j-1, grid, n, m);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n);
    rep(i, 0, n) {
        rep(j, 0, m) {
            char a;
            cin >> a;
            grid[i].push_back(a);
        }
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(!visited[i][j] && grid[i][j] != '#') {
                ++res;
                dfs(i, j, grid, n, m);
            }
        }
    }
    cout << res << nl;
}