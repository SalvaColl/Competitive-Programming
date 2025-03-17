// Extended GCD O(log(min(a,b)))
// Finds GCD(a, b) and also the coefficients x and y
// that satisfy ax + by = gcd(a, b)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl

ll exGCD(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = exGCD(b, a%b, x1, y1);
    x = y1; y = x1 - (a / b) * y1;
    return gcd;
}