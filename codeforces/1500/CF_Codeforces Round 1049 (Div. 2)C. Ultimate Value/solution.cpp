/**
 * AUTHOR : AKASH
 * CREATED: 7/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin>>n;

    vector<ll>a(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    ll sum = 0;
    for(ll i = 1; i <= n; i++)
    {
        if(i % 2 == 0) sum -= a[i];
        else sum += a[i];
    }

    //case-1 if we swap even even and odd odd;
    ll ans = sum;
    for(int i=1; i<=n; i++)
    {
        ans = max(ans, sum + (i-1)-((i-1)&1));
    }


    ll mineven = LLONG_MAX / 2;
    ll minodd  = LLONG_MAX / 2;

    for (int i = 1; i <= n; i++)
    {
        ll idx = i - 1;

        if (idx & 1)
        {
            ans = max(ans, sum + idx + 2 * a[i] - mineven);
            minodd = min(minodd, idx - 2 * a[i]);
        }
        else
        {
            ans = max(ans, sum + idx - 2 * a[i] - minodd);
            mineven = min(mineven, idx + 2 * a[i]);
        }
    }


    cout<<ans<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}
