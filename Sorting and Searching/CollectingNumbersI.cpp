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
    vi pos(n+1);
    vi nums(n);
    rep(i, 0, n) {
       cin >> nums[i];
       pos[nums[i]] = i; 
    }
    int res = 1;
    int curr = pos[1];
    rep(i, 1, n+1) {
        if(pos[i] < curr) {
            ++res;
            curr = pos[i];
        } else {
            curr = pos[i];
        }
    }
    cout << res << nl;
}