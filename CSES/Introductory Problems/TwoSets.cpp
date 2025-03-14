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
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    if(n % 4 == 1 || n % 4 == 2) {
        cout << "NO\n";
    } else {
        if(n % 4 == 0) {
            cout << "YES\n";
            cout << n/2 << nl;
            rep(i, 1, n+1) {
                if(i % 4 == 1 ||i % 4 == 0) cout << i << " ";
            }
            cout << nl;
            cout << n/2 << nl;
            rep(i, 1, n+1) {
                if(i % 4 == 2 ||i % 4 == 3) cout << i << " ";
            }
            cout << nl;
        } else {
            if(n == 3) {
                cout << "YES\n";
                cout << "2\n";
                cout << "1 2" << nl;
                cout << 1 << nl;
                cout << 3 << nl;
            } else {
                cout << "YES\n";
                cout << n/2 + 1 << nl;
                cout << "1 2 4 7 ";
                rep(i, 8, n+1) {
                    if(i % 4 == 0 ||i % 4 == 3) cout << i << " ";
                }
                cout << nl;
                cout << n/2 << nl;
                cout << "3 5 6 ";
                rep(i, 8, n+1) {
                    if(i % 4 == 1 ||i % 4 == 2) cout << i << " ";
                }
                cout << nl;
            }
        }
    }
}