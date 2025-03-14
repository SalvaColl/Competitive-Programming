#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define ii pair<ll, ll>
#define F first
#define S second

// Cross product to determine the position of obj with respect to the line
ll collinear(ii p1, ii p2, ii obj) {
    return 1LL*(p1.S - p2.S)*(obj.F - p2.F) - 1LL*(p1.F - p2.F)*(obj.S - p2.S);
}
 
void solve() {
    ii p1, p2, obj;
    cin >> p1.F >> p1.S >> p2.F >> p2.S >> obj.F >> obj.S;
    ll result = collinear(p1,p2,obj);
    if (result) {
        if (result < 0) cout << "RIGHT" << endl;
        else cout << "LEFT" << endl;
    } else cout << "TOUCH" << endl;
}
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}