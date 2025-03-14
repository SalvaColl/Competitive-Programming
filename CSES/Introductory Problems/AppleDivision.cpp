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
 
vector<long long> weights;
int n;
 
long long calc(int index, long long sum1, long long sum2) {
    if(index == n) return abs(sum1-sum2);
    else {
        return min(calc(index+1, sum1 + weights[index], sum2), 
            calc(index+1, sum1, sum2  + weights[index]));
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    weights.resize(n);
    rep(i, 0, n) {
        cin >> weights[i];
    }
    cout << calc(0, 0, 0) << nl;
}