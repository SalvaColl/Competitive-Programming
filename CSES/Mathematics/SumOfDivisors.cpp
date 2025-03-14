#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll MOD = 1000000007;
 
// Modular multiplication function
ll modMul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}
 
// Modular addition function
ll modAdd(ll a, ll b) {
    return (a % MOD + b % MOD) % MOD;
}
 
// Modular subtraction function (handles negative results correctly)
ll modSub(ll a, ll b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}
 
// Sum of numbers from 1 to n modulo MOD
ll sumRange(ll n) {
    n %= MOD;
    return modMul(n, (n + 1) % MOD * 500000004 % MOD); // (n * (n + 1) / 2) % MOD using modular inverse of 2
}
 
// Calculation of the sum of divisors from 1 to n
ll sumOfDivisors(ll n) {
    ll result = 0;
 
    for (ll i = 1; i <= n;) {

        // How many numbers up to n share i as a divisor
        ll quotient = n / i;

        // Next i where the quotient value changes
        ll next_i = n / quotient + 1;
 
        // Sum of numbers from i to next_i - 1
        ll rangeSum = modSub(sumRange(next_i - 1), sumRange(i - 1));
 
        // Add the contribution of the current quotient
        // So the sum of the divisors that appear the same number of times
        // multiplied by how many times they appear
        result = modAdd(result, modMul(quotient, rangeSum));
 
        i = next_i;
    }
 
    return result;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n;
    cin >> n;
 
    cout << sumOfDivisors(n) << '\n';
    return 0;
}