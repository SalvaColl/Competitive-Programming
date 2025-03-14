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
 
    long long n;
    cin >> n;
    vector<long long> nums(n);
    ll sum = 0;
    rep(i, 0, n) {
        cin >> nums[i];
        sum += nums[i];
    }
    order(nums);
    ll avg = sum / n;
    ll median = nums[n/2];
    ll res = 0;
    rep(i, 0, n) {
        res += abs(nums[i] - median);
    }
    if(n % 2 == 0) {
        ll res2 = 0;
        median = nums[(n-1)/2];
        rep(i, 0, n) {
            res2 += abs(nums[i] - median);
        }
        res = min(res, res2);
    }
    cout << res << nl;
}