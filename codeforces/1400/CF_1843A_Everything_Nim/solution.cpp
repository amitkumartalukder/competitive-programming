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
    cin >> n;

    vector<ll>a(n);
    for(ll i=0; i<n; i++)
    {
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    ll b = 1;

    for(ll i=0; i<n; i++)
    {
        if(a[i]==b)
        {
            b++;
        }

        if(a[i]>b)
        {
            break;
        }
    }

    if(b>a[n-1])
    {
        if(a[n-1] & 1)
        {
            cout<<"Alice"<<endl;
        }
        else
        {
            cout<<"Bob"<<endl;
        }
    }
    else
    {
        if(b & 1)
        {
            cout<<"Alice"<<endl;
        }
        else
        {
            cout<<"Bob"<<endl;
        }
    }
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
