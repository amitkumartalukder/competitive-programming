/**
 * AUTHOR : AKASH
 * CREATED: 12/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;

    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    //step-1  first find out divisor of  n
    vector<int>k;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            k.push_back(i);

            if( i != n/i)
            {
                k.push_back(n/i);
            }
        }
    }

    int ans = 0;
    for(int x : k)
    {
        int G =0;
        for(int j=0 ; j<x ; j++)
        {
            int base = a[j];
            int g = 0;

            for(int i=j+x ; i<n ; i+=x)
            {
                g = __gcd(g, abs(a[i]-base));
            }

            G = __gcd(G,g);
        }

        if(G != 1)
        {
            ans++;
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
