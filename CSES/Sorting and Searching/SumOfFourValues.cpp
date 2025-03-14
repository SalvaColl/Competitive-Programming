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
 
    ll n, x;
    cin >> n >> x;
    ll a[n];
    vector<vector<ll>> vec(n, vector<ll>(2));
    rep(i, 0, n) {
        cin >> a[i];
        vec[i][0] = a[i];
        vec[i][1] = i+1;
    }
    order(vec);

    // We fix the first two values
    for(ll ptr1 = 0; ptr1 < n-3; ptr1++) {
        for(ll ptr2 = ptr1 + 1; ptr2 < n-2; ptr2++) {
            ll ptr3 = ptr2+1;
            ll ptr4 = n-1;

            // And try to find another two to complete the sum
            while(ptr3 < ptr4) {
                ll curr = vec[ptr1][0] + vec[ptr2][0] + vec[ptr3][0] + vec[ptr4][0];
                if(curr == x) {
                    cout << vec[ptr1][1] << " "  << vec[ptr2][1] << " ";
                    cout << vec[ptr3][1] << " " << vec[ptr4][1] << nl;
                    return 0;
                } else if(curr > x) {
                    ptr4--;
                } else if(curr < x) {
                    ++ptr3;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << nl;
}