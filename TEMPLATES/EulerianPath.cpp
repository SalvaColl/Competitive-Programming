// Eulerian Path template O(E)
// Creates a path that visits every edge exactly once

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;
using pii = pair<ll, ll>;
using vi = vector<ll>;
#define rep(i, a, n) for(int i = a; i < n; i++)
#define nl        '\n'
#define order(a)   sort(a.begin(), a.end())
#define rorder(a)  sort(a.rbegin(), a.rend())
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define YN(v) cout << ((v) ? "YES" : "NO") << nl

const int MAX_N = 1e5; // Change for problem
vector<vi> adj(MAX_N); // Adjacency list

int oddDegreeCount() {
    int oddCount = 0;
    for (int i = 1; i < MAX_N; i++) {
        if (adj[i].size() % 2 == 1) {
            oddCount++;
        }
    }
    return oddCount;
}

void eulpath() {
    
    // Check if the graph can have an Eulerian path
    int oddCount = oddDegreeCount();
    if(oddCount != 0 && oddCount != 2) {
        cout << "NO PATH" << nl;
        return;
    }

    ll source = 1;
    stack<ll> path; vi eulerianPath; path.push(1);
    while(!path.empty()) {
        ll cur = path.top();
        if(!adj[cur].empty()) {
            ll next = adj[cur].back(); adj[cur].pop_back();
            for(auto it = adj[next].begin(); it != adj[next].end(); ++it) {
                if(*it == cur) {
                    adj[next].erase(it);
                    break;
                }
            }
            path.push(next);
        } else {
            eulerianPath.push_back(cur);
            path.pop();
        }
    }

    // Output the path
    reverse(eulerianPath.begin(), eulerianPath.end());
    for(auto node : eulerianPath) {
        cout << node << " ";
    }
    cout << nl;
}