/**
 * AUTHOR : AKASH
 * CREATED: 30/12/2025
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin>>n;

    vector<ll>a(n),b(n);
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(ll i=0; i<n; i++)
    {
        cin>>b[i];
    }


    int base = 0;
    map<pair<ll,ll>,int>freq;
    for(ll i=0; i<n; i++)
    {
        if (a[i] == 0)
        {
            if (b[i] == 0) base++;
            continue;
        }

        ll x = -b[i];
        ll y = a[i];

        ll g = __gcd(llabs(x), llabs(y));

        x/= g;
        y /=g;

        if(y<0)
        {
            x = -x;
            y = -y;
        }

        freq[ {x,y}]++;


    }

    int mx = 0;
    for(auto &it : freq)
    {
        mx = max(mx, it.second);
    }

    cout<<mx+base<<endl;


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
