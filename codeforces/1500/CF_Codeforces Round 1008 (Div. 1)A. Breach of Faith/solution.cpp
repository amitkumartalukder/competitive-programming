/**
 * AUHTOR : AKASH
 * CREATED: 11/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin>>n;

    vector<ll>a(2*n);
    for(ll i=0; i<2*n; i++)
    {
        cin>>a[i];
    }

    sort(a.begin(),a.end());

    ll a1 = a.back();
    a.pop_back();

    vector<ll>big, small;
    for(int i=0; i<n; i++)
    {
        big.push_back(a.back());
        a.pop_back();
    }

    small = a;
    ll missing = a1;
    for(int i=0; i<n-1; i++)
    {
        missing += big[i] - small[i];
    }

    missing += big[n-1];

    cout << a1 << " ";
    for (int i = 0; i < n - 1; i++)
        cout << small[i] << " " << big[i] << " ";

    cout << missing << " " << big[n - 1] << "\n";
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
