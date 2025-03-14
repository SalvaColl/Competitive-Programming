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
 
    string s;
    cin >> s;
    vector<int> freq(28, 0);
    rep(i, 0, len(s)) freq[(s[i]-'A')]++;
    bool used = false;
    bool ans = true;
    int index = -1;
    rep(i, 0, 28) {
        if(freq[i] % 2 != 0) {
            if(used) {
                ans = false;
                break;
            } else {
                used = true;
                index = i;
            }
        }
    }
    if(ans) {
        rep(i, 0, 28) {
            int need = freq[i] / 2;
            rep(k, 0, need) {
                char a = ('A' + i);
                cout << a;
            }
        }
        if(used) {
            char b = ('A' + index);
            cout << b;
        } 
        string rev = "";
        rep(i, 0, 28) {
            int need = freq[i] / 2;
            rep(k, 0, need) {
                char a = ('A' + i);
                rev += a;
            }
        }
        reverse(rev.begin(), rev.end());
        cout << rev;
        cout << nl;
    } else {
        cout << "NO SOLUTION\n";
    }
}