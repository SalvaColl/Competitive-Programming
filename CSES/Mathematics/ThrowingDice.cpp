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
    ll mat[6][6];

    Matrix() {
        memset(mat, 0, sizeof(mat));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result = {};
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                for (int k = 0; k < 6; k++)
                    result.mat[i][j] = (result.mat[i][j] + (mat[i][k] * other.mat[k][j])%MOD)%MOD;
        return result;
    }
};

Matrix id() {
    Matrix res;
    for (int i = 0; i < 6; ++i)
        res.mat[i][i] = 1;
    return res;
}
 
Matrix power(Matrix base, ll exp) {
    Matrix result = id();
    while (exp) {
        if (exp % 2) result = (result * base);
        base = base * base;
        exp /= 2;
    }
    return result;
}
 
void solve() {
    ll n; cin >> n;
    vector<ll> base = {1, 1, 2, 4, 8, 16};
    if(n == 0) {
        cout << 1 << endl;
        return;
    }
    if(n < 6) {
        cout << base[n] << endl;
        return;
    }
    Matrix M;
    REP(i, 0, 6) {
        M.mat[0][i] = 1;
    }    
    REP(i, 1, 6) {
        M.mat[i][i-1] = 1;
    }
    Matrix Mn = power(M, n-5);
    ll res = 0;
    REP(i, 0, 6) {
        res = (res + Mn.mat[0][i] * base[5-i])%MOD;
    }
    cout << res << endl;
}
 
#define TESTCASES 0
int main() {
    if (TESTCASES) {
        ll tt;
        cin >> tt;
        while (tt--) solve();
    }
    else solve();
    return 0;
}