/**
 * AUTHOR : AKASH
 * CREATED: 4/1/2026
 **/

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // frequency count
    unordered_map<int, int> freq;
    for (int x : a)
    {
        freq[x]++;
    }

    int ans = 0;

    // count polygons
    for (auto &it : freq)
    {
        ans += it.second / 3;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

