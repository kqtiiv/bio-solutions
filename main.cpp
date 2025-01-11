#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

typedef long long ll;
const ll INF = LLONG_MAX;

void fastIO()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    string n;
    cin >> n;
    auto start = high_resolution_clock::now();

    string sorted_n = n;
    sort(sorted_n.begin(), sorted_n.end());
    vector<ll> ans;
    for (ll i=2; i<10; i++) {
        string perm = to_string(stoll(n)*i);
        sort(perm.begin(), perm.end());
        if (sorted_n==perm) {
            ans.push_back(i);
        }
    }
    if (ans.size()==0) {
        cout << "NO" << "\n";
    } else {
        for (ll i: ans) {
            cout << i << "\n";
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "execution time: " << duration.count() << "ms" << "\n";

}


int main()
{
    fastIO();

    solve();


    return 0;
}
