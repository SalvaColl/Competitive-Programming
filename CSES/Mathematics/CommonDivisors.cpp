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
 
const int maxVal = 1e6;
 
int divisors[maxVal + 1];
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    rep(i, 0, n) {
        int num;
        cin >> num;
        const int up = (int) sqrt(num);
        for(int i = 1; i <= up; i++) {
            if(num % i == 0) {
                divisors[i]++;
                if(i != num / i) {
                    divisors[num/i]++;
                }
            }
        }
    }
    for(int i = maxVal; i >= 1; i--) {
        if(divisors[i] >= 2) {
            cout << i << nl;
            break;
        }
    }
}