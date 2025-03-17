// Euler's Totient Function O(n log n)
// Returns the number of numbers that are coprime with n up to n

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

ll phi(ll n) {
    double res = n;
    for(ll p = 2; p*p <= n; p++) {
        if(n % p) continue;
        while(n % p == 0) {
            n /= p;
        }
        res *= (1.0-(1.0/(double)p));
    }
    if(n > 1) {
        res -= res/n;
    }
    return (int)res;
}