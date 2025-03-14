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
#define all(a) a.begin(), a.end()
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define YN(v) cout << ((v) ? "YES" : "NO") << nl

// The idea is to generate the strings of length n by reversing the strings
// of length n-1 and adding a 1 at the start of them 
// and a 0 at the start of the original ones 
vector<string> generateGrayCode(int n) {
    // BASE CASE
    if(n == 1) {
        return {"0", "1"};
    } else {
        // CALCULATE THE STRINGS FOR N-1 LENGTH
        vector<string> prevGrayCode = generateGrayCode(n-1);
 
        // REVERSE THE PREVIOUS STRINGS OF N-1 LENGTH
        vector<string> reversedPrevGrayCode = prevGrayCode;
        reverse(all(reversedPrevGrayCode));
 
        int prevSize = size(reversedPrevGrayCode);
        int index = 0;
        while(index < prevSize) {
 
            // PREPEND 0 AT START OF PREV GRAY CODES
            string appendedZero = "0" + prevGrayCode[index];
 
            // PREPEND 1 AT START OF REVERSED PREV GRAY CODES
            prevGrayCode[index] = "1" + reversedPrevGrayCode[index];
            prevGrayCode.push_back(appendedZero);
            index++;
        }
        return prevGrayCode;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<string> grayCode = generateGrayCode(n);
    for(string a : grayCode) {
        cout << a << nl;
    }
}