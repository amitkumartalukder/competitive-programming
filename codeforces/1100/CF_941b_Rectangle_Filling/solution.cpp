/**
 * AUTHOR : AKASH
 * CREATED: 31/12/2025
 **/
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    // Check top row
    bool topSame = true;
    for (int j = 1; j < m; j++)
    {
        if (grid[0][j] != grid[0][0])
        {
            topSame = false;
            break;
        }
    }

    // Check bottom row
    bool bottomSame = true;
    for (int j = 1; j < m; j++)
    {
        if (grid[n-1][j] != grid[n-1][0])
        {
            bottomSame = false;
            break;
        }
    }

    // Check left column
    bool leftSame = true;
    for (int i = 1; i < n; i++)
    {
        if (grid[i][0] != grid[0][0])
        {
            leftSame = false;
            break;
        }
    }

    // Check right column
    bool rightSame = true;
    for (int i = 1; i < n; i++)
    {
        if (grid[i][m-1] != grid[0][m-1])
        {
            rightSame = false;
            break;
        }
    }

    // Apply final decision rules
    bool impossible = false;

    if (topSame && bottomSame && grid[0][0] != grid[n-1][0])
    {
        impossible = true;
    }

    if (leftSame && rightSame && grid[0][0] != grid[0][m-1])
    {
        impossible = true;
    }

    cout << (impossible ? "NO\n" : "YES\n");
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


