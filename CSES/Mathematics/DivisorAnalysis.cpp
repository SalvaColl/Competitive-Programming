#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<int, int>;
using vi = vector<int>;
#define dbg(v) cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define YN(v) cout << ((v) ? "YES" : "NO") << nl

const ll MOD = 1e9+7;
const ll PHI = MOD-1;

ll binpow(ll x, ll n) {
    x %= MOD;
    ll res = 1;
    while(n > 0) {
        if(n % 2) res = (res*x)%MOD;
        x = (x*x)%MOD;
        n /= 2; 
    }
    return res % MOD;
}

ll inv(ll x) {
    return binpow(x, MOD-2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    // We use mod 2*Phi to conserve parity and then be able to reduce it to phi
    // and use it as an exponent
    vector<ll> factors(n);
    vector<ll> exponents(n);
    vector<ll> eMod2Phi(n); 

    ll num = 1;
    ll divisors = 1;
    ll divisorsMod2Phi = 1;
    ll sumOfDivisors = 1;

    rep(i, 0, n) {
        cin >> factors[i] >> exponents[i];

        num = (num*binpow(factors[i], exponents[i])) % MOD;
        divisors = (divisors*(exponents[i]+1)) % MOD;
        divisorsMod2Phi = (divisorsMod2Phi*(exponents[i]+1)) % (2*PHI);

        ll numerator = (binpow(factors[i], exponents[i] + 1) - 1 + MOD) % MOD;
        ll denominator = inv((factors[i]-1+MOD)%MOD);
        sumOfDivisors = (sumOfDivisors * ((numerator * denominator) % MOD)) % MOD;
    }
    ll productOfDivisors = binpow(num, divisorsMod2Phi/2);
    bool oddDivisors = (divisorsMod2Phi % 2 == 1);
    if(oddDivisors) {
        ll sqrtNum = 1;
        rep(i, 0, n) {
            sqrtNum = (sqrtNum * binpow(factors[i], (((exponents[i]%(2*PHI))/2)%PHI))) % MOD;
        }
        productOfDivisors = (productOfDivisors * sqrtNum) % MOD;
    }
    cout << divisors << " " << sumOfDivisors << " " << productOfDivisors << nl;
}