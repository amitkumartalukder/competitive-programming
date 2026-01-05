/**
 * AUTHOR : AKASH
 * CREATED: 5/1/2025
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, k, l, r;
    cin >> n >> k >> l >> r;

    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int>v;
    for(int i=1; i<=n; i++)
    {
        v.push_back(a[i]);
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }


    int m = v.size();
    vector<int>cntx(m,0), cnty(m,0);

    int disx = 0, disy = 0;

    ll ans =0 ;
    int x = 0;
    int y = 1;

    for(int i=1; i<=n; i++)
    {
        //Move x: reach exactly k distinct
        while(x+1<=n && disx<k)
        {
            if(cntx[a[x+1]]==0)
            {
                disx++;
            }
            cntx[a[x+1]]++;
            x++;
        }


        while (y <= n)
        {
            if (cnty[a[y]] == 0 && disy == k)
                break;

            if (cnty[a[y]] == 0)
                disy++;

            cnty[a[y]]++;
            y++;
        }



        // Count valid subarrays
        if (disx == k)
        {
            int left = max(x, i + l - 1);
            int right = min(y - 1, i + r - 1);
            if (left <= right)
                ans += (right - left + 1);
        }

        // Remove a[i] from both windows
        cntx[a[i]]--;
        cnty[a[i]]--;
        if (cntx[a[i]] == 0) disx--;
        if (cnty[a[i]] == 0) disy--;
    }

    cout << ans << "\n";
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
