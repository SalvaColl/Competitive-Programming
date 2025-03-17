// Sieve of Eratosthenes template O(n log log n)

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

vi soe(ll n) {
    vector<bool> prime(n+1, true); vi primes;
    for(ll p = 2; p*p <= n; p++) {
        if(prime[p]) {
            primes.push_back(p);
            for(ll i = p*p; i <= n; i += p) prime[i] = false;
        }
    }
    return primes;
}