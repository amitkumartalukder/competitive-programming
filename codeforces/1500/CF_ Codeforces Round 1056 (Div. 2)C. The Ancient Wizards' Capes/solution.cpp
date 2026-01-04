/**
 * AUTHOR : AKASH
 * CREATED: 4/1/2026
 **/

#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 676767677;
bool validar(const vector<int>& x, const vector<int>& a, int n)
{
    int visibles = 1;

    // visibles at position 1
    for (int i = 2; i <= n; i++)
    {
        if (x[i] == 1) visibles++;
    }

    if (visibles != a[1]) return false;

    // move from i -> i+1
    for (int i = 1; i < n; i++)
    {
        if (x[i] == 1 && x[i + 1] == 1)
            visibles--;
        else if (x[i] == 0 && x[i + 1] == 0)
            visibles++;

        if (visibles != a[i + 1])
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;

    // 1-based indexing
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1)
    {
        cout << 2 << "\n";
        return;
    }

    // difference check
    for (int i = 1; i < n; i++)
    {
        if (abs(a[i + 1] - a[i]) > 1)
        {
            cout << 0 << "\n";
            return;
        }
    }

    // diff also 1-based
    vector<int> diff(n + 1);
    for (int i = 1; i < n; i++)
        diff[i] = a[i + 1] - a[i];

    int answer = 0;

    for (int start = 0; start <= 1; start++)
    {
        vector<int> cape(n + 1);
        cape[1] = start;

        for (int i = 1; i < n; i++)
        {
            if (diff[i] == 0)
                cape[i + 1] = 1 - cape[i];
            else if (diff[i] == 1)
                cape[i + 1] = 0;
            else
                cape[i + 1] = 1;
        }

        if (validar(cape, a, n))
            answer++;
    }

    cout << answer % MOD << "\n";
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
