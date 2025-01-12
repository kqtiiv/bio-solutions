#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

typedef long long ll;

void fastIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

set<vector<ll>> vis;

void solve()
{
    ll j, n; cin >> j>>n;
    vector<ll> capacities(j);
    vector<ll> initState(j, 0);
    queue<pair<vector<ll>, ll>> q;
    for (ll i=0; i<j; i++) cin>>capacities[i];

    q.push({initState, 0});
    vis.insert(initState);

    while (!q.empty()) {
        vector<ll>state = q.front().first;
        ll steps = q.front().second;
        q.pop();
        for (ll y: state) {
            if (y==n) {
                cout << steps << "\n";
                return;
            }
        }
        for (ll i=0; i<j; i++) {
            vector<ll> newState = state;
            newState[i] = capacities[i];
            if (vis.find(newState) == vis.end()) {
                vis.insert(newState);
                q.push({newState, steps+1});
            }
            newState = state;
            newState[i] = 0;
            if (vis.find(newState)==vis.end()) {
                vis.insert(newState);
                q.push({newState, steps+1});
            }
            for (ll k=0; k<j; k++) {
                if (i != k) {
                    newState = state;
                    ll amount = min(newState[i], capacities[k]-newState[k]);
                    newState[i] -= amount;
                    newState[k] += amount;
                    if (vis.find(newState)==vis.end()) {
                        vis.insert(newState);
                        q.push({newState, steps+1});
                    }
                }
            }
        }
    }
    return;
}


int main()
{
    fastIO();
    solve();
    return 0;
}
