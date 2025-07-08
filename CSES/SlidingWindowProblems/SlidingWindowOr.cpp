#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
#define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define size(a)   (int)a.size()
#define len(a)    (int)a.length()
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;

    vi nums(n);
    nums[0] = x;
    rep(i, 1, n) {
        nums[i] = (a*nums[i-1]+b)%c;
    }

    int bitCount[32] = {0};
    ll total = 0;
    ll window = 0;

    int i = 0;
    int j = 0;
    while(j < n) {
        rep(bit, 0, 32) {
            if(nums[j] & (1LL << bit)) {
                bitCount[bit]++;
                if(bitCount[bit] == 1) {
                    window |= (1LL << bit);
                }
            }
        }

        if(j - i + 1 < k) ++j;
        else {
            total ^= window;
            rep(bit, 0, 32) {
                if(nums[j] & (1LL << bit)) {
                    bitCount[bit]--;
                    if(bitCount[bit] == 0) {
                        window &= ~(1LL << bit);
                    }
                }
            }
            ++i;
            ++j;
        }
    }
    cout << total << nl;
}