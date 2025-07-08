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
    vi nums(n);
    rep(i, 0, n) cin >> nums[i];
    
    map<ll, ll> freq;

    int i = 0;
    int j = 1;

    freq[nums[i]]++;

    ll dist = 1;

    while(j < n) {
        freq[nums[j]]++;
        if(freq[nums[j]] == 1) ++dist;
        if(j - i + 1 < k) {
            ++j;
        } else if(j - i + 1 == k) {
            cout << dist << " ";
            freq[nums[i]]--;
            if(freq[nums[i]] == 0) --dist;
            i++;
            ++j;
        }
    }
}