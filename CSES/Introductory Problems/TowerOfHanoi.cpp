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
 
void solved(vector<pii>& arr, int n, int from, int to, int aux) {
    
    // BASE CASE
    if(n == 1) {
        arr.push_back({from, to});
        return;
    } 
    
    // GENERAL CASE
    else {
        // To move n disks to a stack, we move n-1 disks to an auxiliary stack
        // then move the last disk to that stack and repeat the same process
        // with the remaining n-1 disks
        solved(arr, n-1, from, aux, to);
        arr.push_back({from, to});
        solved(arr, n-1, aux, to, from);
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<pii> x;
    solved(x, n, 1, 3, 2);
    cout << size(x) << nl;
    for(auto move : x) {
        cout << move.F << " " << move.S << nl;
    }
}  