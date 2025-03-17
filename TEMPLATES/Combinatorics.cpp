// Some useful Combinatorics templates

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

#define MOD ((ll)(1e9+7))
const ll MAXN = 1e6 + 5;

ll fac[MAXN + 1]; // Factorials
ll inv[MAXN + 1]; // Inverses of factorials

// Binary exponentiation O(log n)
ll exp(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) res = res*x % m;
        x = x * x % m;
        n /= 2;
    }
    return res;
}

// Calculate factorials O(n)
void factorial() {
    fac[0] = 1;
    for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
}

// Calculate inverses of factorials O(n)
void inverses() {
    inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);
    for (int i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
}

// Combinatorics choose operation O(1) after precalculating in O(n)
// If n is very high and x very small, calculate numerator with first x factors of factorial
ll choose(int n, int x) {
  return fac[n] * inv[x] % MOD * inv[n - x] % MOD;
}
