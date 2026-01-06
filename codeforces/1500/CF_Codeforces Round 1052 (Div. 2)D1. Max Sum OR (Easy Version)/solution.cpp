/**
 * AUTHOR : AKASH
 * CREATED: 6/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int l,r;
    cin>>l>>r;


    long long ans = 0;

    vector<int>a(r+1);
    vector<bool>used(r+1, false);


    int mask = 1 ;
    while(mask < r)
    {
        mask = (mask<<1) | 1;
    }

    for(int i=r; i>=l; i--)
    {
        while(mask-i < l || mask-i > r || used[mask-i])
        {
            mask = mask >> 1;
        }
        a[i] = mask - i;
        used[a[i]] = true;
        ans += (i | a[i]);
    }

    // Output
    cout << ans << "\n";
    for (int i = l; i <= r; i++)
    {
        cout << a[i] << " ";
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
