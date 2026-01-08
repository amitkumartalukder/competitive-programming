/**
 * AUTHOR : AKASH
 * CREATED: 8/1/2026
 **/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;

    vector<ll> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    ll ans = 1;

    for (int i = 0; i + 1 < n; i++)
    {
        ll g = std::gcd(b[i], b[i + 1]);
        ll need = b[i] / g;
        ans = std::lcm(ans, need);
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
