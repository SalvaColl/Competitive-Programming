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
 
    int n, m;
    cin >> n >> m;
    vi pos(n+1);
    vi nums(n);
    rep(i, 0, n) {
       cin >> nums[i];
       pos[nums[i]] = i; 
    }
    int res = 1;
    int curr = pos[1];
    rep(i, 1, n+1) {
        if(pos[i] < curr) {
            ++res;
            curr = pos[i];
        } else {
            curr = pos[i];
        }
    }
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        int temp = max(a, b);
        a = min(a, b);
        b = temp;
        --a;
        --b;
        if(abs(nums[a] - nums[b]) == 1) {
            if(nums[a] > nums[b]) --res;
            else ++res;
        } 
        if(pos[nums[a]] < pos[nums[a]-1] && b > pos[nums[a]-1]) --res;
        if(pos[nums[a]] > pos[nums[a]+1] && b < pos[nums[a]+1]) --res;
        if(pos[nums[a]] < pos[nums[a]+1] && b > pos[nums[a]+1]) ++res;
        if(pos[nums[a]] > pos[nums[a]-1] && b < pos[nums[a]-1]) ++res;
 
        if(pos[nums[b]] < pos[nums[b]-1] && a > pos[nums[b]-1]) --res;
        if(pos[nums[b]] > pos[nums[b]+1] && a < pos[nums[b]+1]) --res;
        if(pos[nums[b]] < pos[nums[b]+1] && a > pos[nums[b]+1]) ++res;
        if(pos[nums[b]] > pos[nums[b]-1] && a < pos[nums[b]-1]) ++res;
 
        pos[nums[a]] = b;
        pos[nums[b]] = a;
        temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
 
        cout << res << nl;
    }
}