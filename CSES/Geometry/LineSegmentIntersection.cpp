#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define ii pair<ll, ll>
#define F first
#define S second

// Checks if they are collinear (if the result is 0 )
ll crossProduct(ii p1, ii p2, ii p3) {
    ii p12 = {p2.F-p1.F, p2.S-p1.S};
    ii p13 = {p3.F-p1.F, p3.S-p1.S};
    return p12.F * p13.S - p12.S * p13.F;
}

// To compare two points
bool comparePoints(const ii &a, const ii &b) {
    return (a.F == b.F) ? (a.S < b.S) : (a.F < b.F);
}

// Checks if p3 lies in the segment p1 -> p2
bool isInMid(ii p1, ii p2, ii p3) {
    vector<ii> v = {p1, p2, p3};
    sort(v.begin(), v.end());
    return (v[1] == p3);
}

// Get the sign of a number
int sign(ll x) {
    return (x > 0LL) - (x < 0LL);
}

bool intersect(ii pA, ii pB, ii pC, ii pD) {

    // Check if 3 of the points are collinear
    ll cproduct1 = crossProduct(pA, pB, pC);
    ll cproduct2 = crossProduct(pA, pB, pD);
    ll cproduct3 = crossProduct(pC, pD, pA);
    ll cproduct4 = crossProduct(pC, pD, pB);

    // If they are, check if the one that does not belong to one of the segments
    // is between the other two
    if(cproduct1 == 0 && isInMid(pA, pB, pC)) {
        return true;
    }
    if(cproduct2 == 0 && isInMid(pA, pB, pD)) {
        return true;
    }
    if(cproduct3 == 0 && isInMid(pC, pD, pA)) {
        return true;
    }
    if(cproduct4 == 0 && isInMid(pC, pD, pB)) {
        return true;
    }

    // Also check if A and B are in different sides of the segment C -> D
    // and if C and D are in different sides of the segment A -> B
    if(sign(cproduct1) != sign(cproduct2) && sign(cproduct3) != sign(cproduct4)) {
        return true;
    }
    
    return false;
}
 
void solve() {
    ii pA, pB, pC, pD;
    cin >> pA.F >> pA.S >> pB.F >> pB.S >> pC.F >> pC.S >> pD.F >> pD.S;

    cout << (intersect(pA, pB, pC, pD) ? "YES" : "NO") << endl;
}
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}