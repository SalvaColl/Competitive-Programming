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
    vi nums(n-1);
    rep(i, 0, n-1) cin >> nums[i];
    order(nums);
    if(n == 2) {
        if(nums[0] == 1) cout << 2 << nl;
        else cout << 1 << nl;
    } else {
        rep(i, 0, n-2) {
            if(nums[i]+1 != nums[i+1]) {
                cout << nums[i]+1 << nl;
                break;
            } 
            else if(i == n-3) {
                if(nums[0] == 1) cout << nums[n-2]+1 << nl;
                else cout << 1 << nl;
            }
        }
    }
}