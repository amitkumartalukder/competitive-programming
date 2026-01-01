/**
 * AUTHOR : AKASH
 * CREATED: 1/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n,k;
    cin>>n>>k;

    // Case n == 1
    if (n == 1)
    {
        cout << k << "\n";
        return;
    }

    ll x = 0;
    while((1ll<<(x+1))<=k)
    {
        x++;
    }
    int first = (1ll<<x)-1;
    int second = k - first;

    cout<<first<<" "<<second<<" ";

    for (int i = 3; i <= n; i++)
    {
        cout << " 0";
    }
    cout << "\n";
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
