// Longest Increasing Subsequence with Binary Search
// O(n log n)

// Can also be solved in O(n^2) with Dynamic Programming

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<long long>;
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
    ll a[n];
    rep(i, 0, n) cin >> a[i];
    vector<ll> list;
    for(ll x : a) {
        auto it = lower_bound(list.begin(), list.end(), x);
        if(it == list.end()) list.push_back(x);
        else *it = x;
    }
    cout << size(list) << nl;
}