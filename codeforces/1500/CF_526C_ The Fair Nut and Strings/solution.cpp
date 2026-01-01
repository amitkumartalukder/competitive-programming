/**
 * AUTHOR : AKASH
 * CREATED: 1/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
static const long long mod = 10000000007;
void solve()
{
    string s;
    cin>>s;

    int ans = 1;
    int cnta = 0;
    for(char c : s)
    {
        if(c=='a')
        {
            cnta++;
        }
        else if(c=='b')
        {
            ans = (ans * (cnta+1))%mod;
            cnta = 0;
        }
    }

    ans = (ans * (cnta+1))%mod;

    ans = (ans-1)%mod;
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    solve();


    return 0;
}
