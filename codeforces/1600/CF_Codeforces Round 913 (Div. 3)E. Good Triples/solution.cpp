/**
 * AUTHOR : AKASH
 * CREATED: 12/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>ways(10,0);
void pre()
{
    for(int a = 0; a <= 9; a++)
    {
        for(int b = 0; b <= 9; b++)
        {
            for(int c = 0; c <= 9; c++)
            {
                int sum = a+b+c;

                if(sum<=9)
                {
                    ways[sum]++;
                }
            }
        }
    }
}
void solve()
{
    int n;
    cin>>n;

    if(n==0)
    {
        cout<<ways[0]<<endl;
        return;
    }

    ll ans = 1;
    while(n>0)
    {
        int digit = n % 10;
        ans *= ways[digit];
        n /= 10;
    }

    cout<<ans<<endl;


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }



    return 0;
}

