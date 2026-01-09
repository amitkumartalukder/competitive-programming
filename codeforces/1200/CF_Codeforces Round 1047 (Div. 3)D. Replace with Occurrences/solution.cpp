/**
 * AUTHOR : AKASH
 * CREATED: 9/1/2026
 **/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++)
        cin >> b[i];

    // store positions of each value
    map<int, vector<int>> pos;
    for(int i = 0; i < n; i++)
        pos[b[i]].push_back(i);

    // validity check: freq[x] must be multiple of x
    for(auto &it : pos)
    {
        int x = it.first;
        int cnt = it.second.size();
        if(cnt % x != 0)
        {
            cout << -1 << "\n";
            return;
        }
    }

    vector<int> a(n);
    int z = 1;

    // construct array a
    for(auto &it : pos)
    {
        int x = it.first;
        auto &indices = it.second;

        for(int i = 0; i < (int)indices.size(); i += x)
        {
            // assign same value z to x positions
            for(int j = 0; j < x; j++)
            {
                a[indices[i + j]] = z;
            }
            z++;
        }
    }

    // output
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
