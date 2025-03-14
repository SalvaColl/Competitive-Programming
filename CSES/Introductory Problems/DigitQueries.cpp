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
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // Precalculate powers of 10
    vector<ll> powers(19, 1);
    rep(i, 1, 19) {
        powers[i] = powers[i-1] * 10;
    }
 
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n; // Position of the digit in the infinite sequence
 
        ll numDig = 0; // Number of digits of the number that has the nth digit
        ll digits = 0; // Total digits counted
        ll prevDig = 0; // Total digits before the current range
        rep(i, 1, 19) {
            digits += (powers[i] - powers[i-1])*i; // Total digits in numbers of i digits
            if(digits >= n) {
                numDig = i;
                break;
            }
            prevDig = digits;
        }
        
        // Binary search to find the exact number that has the nth digit
        ll low = powers[numDig-1]; // Lowest number with numDig digits
        ll high = powers[numDig] - 1; // Highest number with numDig digits
        ll ans = 0; // The number that contains the nth digit
        ll startPosAns = 0; // Position where ans starts
        
        while(low <= high) {
            ll mid = (low + high) / 2;
            ll startPos = (mid - powers[numDig-1]) * numDig + prevDig + 1;
 
            if(startPos <= n) { // If the mid number contains or is before the nth digit
                if(mid > ans) {
                    ans = mid; // Update answer to highest valid number found
                    startPosAns = startPos;
                }
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
 
        string number = to_string(ans);
        cout << number[n-startPosAns] << nl; // Print nth digit
    }
}