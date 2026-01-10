/**
 * AUTHOR : AKASH
 * CREATED: 10/1/2026
 **/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // suffix greedy (backward match)
    vector<int> suf(m);
    int ptr = n - 1;
    for (int i = m - 1; i >= 0; i--)
    {
        while (ptr >= 0 && a[ptr] < b[i])
            ptr--;
        suf[i] = ptr;
        ptr--;
    }

    // prefix greedy (forward match)
    vector<int> pre(m);
    ptr = 0;
    for (int i = 0; i < m; i++)
    {
        while (ptr < n && a[ptr] < b[i])
            ptr++;
        pre[i] = ptr;
        ptr++;
    }

    // if no deletion needed
    if (pre[m - 1] < n)
    {
        cout << 0 << '\n';
        return;
    }

    int ans = INF;

    // try deleting each b[i]
    for (int i = 0; i < m; i++)
    {
        int leftmatch  = (i == 0)     ? -1 : pre[i - 1];
        int rightmatch = (i == m - 1) ?  n : suf[i + 1];

        if (rightmatch > leftmatch)
        {
            ans = min(ans, b[i]);
        }
    }

    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
