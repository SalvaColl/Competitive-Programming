#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define size(a)   (int)a.size()
#define len(a)    (int)a.length()
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    int inI;
    int inJ;
    int bI;
    int bJ;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                inI = i;
                inJ = j;
            } else if(grid[i][j] == 'B') {
                bI = i;
                bJ = j;
            } else if(grid[i][j] == '#') {
                visited[i][j] = 1;
            }
        }
    }
 
    queue<pair<int, int>> queue;
    queue.push({inI, inJ});
    visited[inI][inJ] = true;
 
    vector<vector<pair<int, int>>> parents(n, vector<pair<int, int>>(m));
 
    while(!queue.empty()) {
        pair<int, int> curr = queue.front();
        queue.pop();
        if(curr.F == bI && curr.S == bJ) {
            break;
        } else {
            if(curr.F + 1 < n && !visited[curr.F+1][curr.S]) {
                visited[curr.F+1][curr.S] = 1;
                queue.push({curr.F+1, curr.S});
                parents[curr.F+1][curr.S] = {curr.F, curr.S};
            }
            if(curr.F - 1 >= 0 && !visited[curr.F-1][curr.S]) {
                visited[curr.F-1][curr.S] = 1;
                queue.push({curr.F-1, curr.S});
                parents[curr.F-1][curr.S] = {curr.F, curr.S};
            }
            if(curr.S + 1 < m && !visited[curr.F][curr.S+1]) {
                visited[curr.F][curr.S+1] = 1;
                queue.push({curr.F, curr.S+1});
                parents[curr.F][curr.S+1] = {curr.F, curr.S};
            }
            if(curr.S - 1 >= 0 && !visited[curr.F][curr.S-1]) {
                visited[curr.F][curr.S-1] = 1;
                queue.push({curr.F, curr.S-1});
                parents[curr.F][curr.S-1] = {curr.F, curr.S};
            }
        }
    }
    if(!visited[bI][bJ]) cout << "NO" << nl;
    else {
        cout << "YES" << nl;
        int currX = bI;
        int currY = bJ;
        string res = "";
        while(currX != inI || currY != inJ) {
            if(parents[currX][currY].F == currX + 1) {
                res += 'U';
                ++currX;
            } else if(parents[currX][currY].F == currX - 1) {
                res += 'D';
                --currX;
            }  else if(parents[currX][currY].S == currY + 1) {
                res += 'L';
                ++currY;
            }  else if(parents[currX][currY].S == currY - 1) {
                res += 'R';
                --currY;
            } 
        }
        cout << res.length() << nl;
        reverse(res.begin(), res.end());
        cout << res << nl;
    }
}