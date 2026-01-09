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

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    // Compress consecutive equals
    vector<int> b;
    b.push_back(a[0]);
    for(int i = 1; i < n; i++)
    {
        if(a[i] != a[i-1])
            b.push_back(a[i]);
    }

    int m = b.size();
    int cnt = 0;

    if(m == 1)
    {
        cout<<1<<endl;
        return;
    }

    // First element
    if(b[0] > b[1]) cnt++;

    // Middle elements
    for(int i = 1; i < m-1; i++)
    {
        if(b[i-1] < b[i] && b[i] > b[i+1])
            cnt++;
    }

    // Last element
    if(b[m-1] > b[m-2]) cnt++;

    cout << cnt << '\n';
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

