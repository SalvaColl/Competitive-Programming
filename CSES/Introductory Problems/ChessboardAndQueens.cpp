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
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
ll ways = 0;
 
bool col[16], diag1[16], diag2[16], reserved[8][8];
 
void search(ll r) {
    if(r == 8) {
        ways++;
        return;
    }

    // Try placing a queen in each column of the current row
    for(ll c = 0; c < 8; c++) {
        // If it is not valid
        if(col[c] || diag1[r+c] || diag2[r-c+7] || reserved[r][c]) {
            continue;
        } 
        
        // Mark as occupied
        col[c] = diag1[r+c] = diag2[r-c+7] = true;

        // Search next row
        search(r+1);

        // Backtracking to unmark the column and diagonals
        col[c] = diag1[r+c] = diag2[r-c+7] = false;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    rep(i, 0, 16) {
        col[i] = diag1[i] = diag2[i] = false;
    }
    string x;
    rep(j, 0, 8) {
        cin >> x;
        rep(k, 0, 8) {
            reserved[j][k] = (x[k] != '.');
        }
    }
 
    search(0);
    cout << ways;
}