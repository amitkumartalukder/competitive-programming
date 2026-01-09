/**
 * AUTHOR : AKASH
 * CREATED: 8/1/2026
 **/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll NEG = -(ll)1e13;
void solve()
{
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector<ll> a(n);
    for(ll i = 0; i < n; i++)
        cin >> a[i];

    //replace all value 0 with large negative number
    ll pos = -1;
    for(ll i=0; i<n; i++)
    {
        if(s[i]=='0')
        {
            pos = i;
            a[i] =NEG;
        }
    }



    //kadane algorithm to cheak the impossible case

    ll cur = 0, mx = 0;
    for(ll i=0; i<n; i++)
    {
        cur = max(cur+a[i], a[i]);
        mx = max(cur,mx);
    }


    if( mx > k || (mx !=k && pos == -1))
    {
        cout<<"NO"<<endl;
        return;
    }


    // if there is at least one zero, fix it
    if (pos != -1)
    {
        ll leftmax = 0, rightmax = 0;

        cur = 0;
        for (ll i = pos + 1; i < n; i++)
        {
            cur += a[i];
            leftmax = max(leftmax, cur);
        }

        cur = 0;
        for (ll i = pos - 1; i >= 0; i--)
        {
            cur += a[i];
            rightmax = max(rightmax, cur);
        }

        a[pos] = k - leftmax - rightmax;
    }

    cout << "YES\n";
    for (ll i = 0; i < n; i++)
    {
        cout << a[i] << (i + 1 < n ? ' ' : '\n');
    }



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


