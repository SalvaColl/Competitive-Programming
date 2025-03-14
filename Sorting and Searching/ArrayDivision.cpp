#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPV(i, a, b) for (ll i = a-1; i >= b; i--)
#define PRINT(a) cout << a << endl
#define PRINTS(a) cout << a << " "
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
#define F first
#define S second
#define key first
#define val second
#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
 
#pragma GCC optimize "-O3"
 
bool valid(const vi &a, ll n, ll k, ll sum) {
    ll cursum = 0, cnt = 1;
    REP(i,0,n) {
        if (a[i] > sum) return false;
        if (a[i] + cursum <= sum) cursum += a[i];
        else {
            cnt++;
            cursum = a[i];
        }
    }
    return cnt <= k;
}
 
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    REP(i, 0, n) cin >> nums[i];
    ll low = 1, mid, high = LLONG_MAX;
    while(low <= high) {
        mid = (low + high)/2;
        if (valid(nums, n, k, mid)) high = mid - 1;
        else low = mid + 1;
    }
    PRINT(low);
}
 
#define TESTCASES 0
int main() {
    if (TESTCASES) {
        ll tt;
        cin >> tt;
        while (tt--) solve();
    }
    else solve();
    return 0;
}