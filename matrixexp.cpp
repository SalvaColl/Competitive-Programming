// This is a dynamic programming problem (CSES Counting Towers)
// But it can also be solved in this way, using matrix exponentiation, in O(log n)

#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ll long long
#define REP(i, a, b) for (ll i = a; i < b; i++)
#define REPV(i, a, b) for (ll i = a-1; i >= b; i--)
#define PRINT(a) cout << a << endl
#define PRINTS(a) cout << a << " "
#define MOD (ll)(1e9+7)
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
#define F first
#define S second
#define key first
#define val second
#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>
 
#define ordered_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
 
 
#pragma GCC optimize "-O3"
 
 
struct Matrix {
    ll mat[2][2];
 
    Matrix operator*(const Matrix& other) const {
        Matrix result = {};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    result.mat[i][j] = (result.mat[i][j] + (mat[i][k] * other.mat[k][j])%MOD)%MOD;
        return result;
    }
};
 
Matrix power(Matrix base, ll exp) {
    Matrix result = {1, 0, 0, 1};  // Identity matrix
    while (exp) {
        if (exp % 2) result = result * base;
        base = base * base;
        exp /= 2;
    }
    return result;
}
 
void solve() {
    ll n; cin >> n;
    Matrix M = {4,1,1,2};
    Matrix Mn = power(M, n-1);
    PRINT((Mn.mat[0][0] + Mn.mat[0][1] + Mn.mat[1][0] + Mn.mat[1][1])%MOD);
}
 
#define TESTCASES 1
int main() {
    if (TESTCASES) {
        ll tt;
        cin >> tt;
        while (tt--) solve();
    }
    else solve();
    return 0;
}
