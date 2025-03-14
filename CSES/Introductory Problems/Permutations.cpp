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
    if(n <= 3) {
        if(n == 1) cout << 1 << nl;
        else {
            cout << "NO SOLUTION" << nl;
        }
    }
    else {
        for(int i = 2; i <= n; i+=2) cout << i << " ";
        for(int i = 1; i <= n; i+=2) cout << i << " ";
        cout << nl;
    }
}