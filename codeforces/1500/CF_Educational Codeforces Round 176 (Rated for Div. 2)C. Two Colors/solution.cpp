/**
 * AUHTOR : AKASH
 * CREATED: 11/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n,m;
    cin>>n>>m;

    vector<int>a(m);
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }

    sort(a.begin(),a.end());
    ll ans = 0;
    for(int k=1;k<n;k++)
    {
        int idx = lower_bound(a.begin(),a.end(),k) - a.begin();
        ll x = m - idx;

        int idx1 = lower_bound(a.begin(),a.end(),n-k) - a.begin();
        ll y = m - idx1;

        ans += (x*y)-min(x,y);
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

