/**
 * AUTHOR : AKASH
 * CREATED: 3/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,q;
    cin>>n>>q;

    vector<ll>a(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    vector<ll>freq(n+2,0);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        freq[l]++;
        freq[r+1]--;
    }

    for (int i = 1; i <= n; i++)
    {
        freq[i] += freq[i - 1];
    }

    sort(a.begin()+1,a.begin()+n+1);
    sort(freq.begin()+1,freq.begin()+n+1);

    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        ans += a[i] * freq[i];
    }

    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();


    return 0;
}

