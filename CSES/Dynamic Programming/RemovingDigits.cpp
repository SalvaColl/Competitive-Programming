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
 
    int n;
    cin >> n;
    long long dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    rep(i, 1, n+1) {
        int digits[7] = {};
        int p = 0;
        int temp = i;
        while(temp > 0) {
            digits[p] = temp%10;
            temp /= 10;
            ++p;
        }
        long long m = 1e15;
        for(int d : digits) {
            if(d != 0) {
                if(i - d >= 0) {
                    m = min(m, dp[i-d]);
                }
            }
        }
        dp[i] = m + 1;
    }
    cout << dp[n] << nl;
}