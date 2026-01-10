/**
 * AUTHOR : AKASH
 * CREATED: 10/1/2026
 **/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n,k;
    cin>>n>>k;

    vector<ll>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    ll ans = 0;
    for(ll i=0; i<n; i++)
    {
        int bits = __builtin_popcountll(a[i]);

        ans +=bits;
    }

    vector<int>cnt(61,0);
    for(int x : a)
    {
        for(int bits=0; bits<=60; bits++)
        {
            if( (x & (1LL << bits)) == 0 )

            {
                cnt[bits]++;
            }
        }

    }

    //cost calculation
    for(int bits=0; bits<=60; bits++)
    {
        ll cost = (1ll<<bits);

        while(cnt[bits] > 0 && k >= cost)
        {
            ans++;
            k -= cost;
            cnt[bits]--;
        }
    }


    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
