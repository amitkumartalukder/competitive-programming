/**
 * AUTHOR : AKASH
 * CREATED: 8/1/2026
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

    int g = a[0];
    for(int i=1; i<n; i++)
    {
        g =__gcd(a[i],g);
    }

    int cntg = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]==g)
        {
            cntg++;
        }
    }

    if(cntg > 0)
    {
        cout<<n - cntg<<endl;
        return;
    }

    vector<int>b(n);
    for(int i=0; i<n; i++)
    {
        b[i] = a[i]/g;
    }

    unordered_map<int,int>dp;
    for(int x: b)
    {
        unordered_map<int,int>updatedp = dp;

        if(!updatedp.count(x) || updatedp[x] > 1)
        {
            updatedp[x] = 1;
        }

        for(auto &p : dp)
        {
            int oldgcd = p.first;
            int cost = p.second;

            int  newgcd = __gcd(oldgcd,x);
            int  newcost = cost+1;
            if(!updatedp.count(newgcd) || updatedp[newgcd] > newcost)
            {
                updatedp[newgcd] = newcost;
            }

        }

        dp.swap(updatedp);
    }

    int k = dp[1];
    int ans = (k-1) + (n-1);
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

