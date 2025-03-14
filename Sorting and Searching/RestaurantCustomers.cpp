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
 
    int n;
    cin >> n;
    vi arrivals(n);
    vi leaving(n);
    int curr = 0;
    int best = 0;
    rep(i, 0, n) {
        cin >> arrivals[i] >> leaving[i];
    }
    order(arrivals);
    order(leaving);
    int ar = 0;
    int lv = 0;
    while(ar < n) {
        if(arrivals[ar] < leaving[lv]) {
            ++curr;
            ++ar;
            best = max(best, curr);
        } else {
            ++lv;
            --curr;
            best = max(best, curr);
        }
    }
    best = max(best, curr);
    cout << best << nl;
}