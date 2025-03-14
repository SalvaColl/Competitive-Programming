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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<vi> movies(n, vi(3));
    rep(i, 0, n) {
        int a;
        int b;
        cin >> a >> b;
        movies[i][0] = (b-a);
        movies[i][1] = a;
        movies[i][2] = b;
    }
    sort(movies.begin(), movies.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    int res = 1;
    int curr = movies[0][2];
    rep(i, 0, n-1) {
        if(movies[i+1][1] >= curr) {
            ++res;
            curr = movies[i+1][2];
        }
    }
    cout << res << nl;
}