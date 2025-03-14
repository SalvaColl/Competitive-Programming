// Disjoint Set Union template  

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
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl
 
struct DSU {
    vi p, rank, setSize;
    ll numSets;
    DSU(ll N) {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        rep(i, 0, N) p[i] = i;
    }
    ll find(ll i) {return p[i] = (p[i] == i ? i : find(p[i]));}
    void merge(ll i, ll j) {
        ll x = find(i), y = find(j);
        if(x == y) return;
        numSets--;
        if(rank[x]>rank[y]) {
            p[y] = x;
            setSize[x] += setSize[y];
        } else {
            p[x] = y;
            setSize[y] += setSize[x];
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
    ll sizeOfSet(ll i) {return setSize[find(i)];}
    ll getNumSets() {return numSets;}
};  