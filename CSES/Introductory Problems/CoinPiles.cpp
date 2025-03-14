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
 
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if((a == 0 && b != 0) || (a != 0 && b == 0)) cout << "NO\n";
        else if(a > 2*b || b > 2*a) cout << "NO\n";
        else if(a % 3 == 0 && b % 3 == 0) cout << "YES\n";
        else if((a % 3 == 1 && b % 3 == 2)||(a % 3 == 2 && b % 3 == 1)) cout << "YES\n";
        else cout << "NO\n";
    }
}