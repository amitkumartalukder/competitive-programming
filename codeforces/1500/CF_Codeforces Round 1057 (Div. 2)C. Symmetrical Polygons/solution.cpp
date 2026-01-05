/**
 * AUTHOR : AKASH
 * CREATED: 5/1/2025
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;

    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(n==3)
    {
        if (a[0] + a[1] > a[2] && (a[0] == a[1] || a[1] == a[2]))
        {
            cout<<a[0]+a[1]+a[2]<<endl;

        }
        else
        {
            cout<<0<<endl;

        }

        return;
    }

    ll pairsum  = 0;
    ll paircount = 0;
    vector<ll>oddlist;

    for(int i=0; i<n; )
    {
        int j = i;
        while(j<n && a[j]==a[i])
        {
            j++;
        }

        ll freq = j - i;
        ll pairs = freq/2;

        pairsum += pairs * 2 * a[i];
        paircount += pairs;

        if(freq&1)
        {
            oddlist.push_back(a[i]);
        }

        i = j;
    }

    if(paircount==0)
    {
        cout<<0<<endl; // no pairs exist
        return;
    }

    ll ans = 0;

    // Case 1: axis intersects 0 sticks
    if(paircount>=2)
    {
        ans = max(ans, pairsum);
    }

    // Case 2: axis intersects exactly 1 stick
    for(ll x: oddlist)
    {
        if(x < pairsum)
        {
            ans = max(ans, pairsum+x);
        }
    }

    // Case 3: axis intersects exactly 2 sticks
    sort(oddlist.begin(),oddlist.end());

    for(int i=1; i<oddlist.size(); i++)
    {
        ll u = oddlist[i-1];
        ll v = oddlist[i];

        if(v-u < pairsum)
        {
            ans = max(ans, pairsum+u+v);
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
