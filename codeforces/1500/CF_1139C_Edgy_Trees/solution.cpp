/**
 * AUTHOR : AKASH
 * CREATED: 30/12/2025
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MOD = 1000000007;
const ll MAXN = 200005;

vector<int>red[MAXN];
bool visited[MAXN];

ll modpow(ll a, ll b)
{
    if(b==0)
    {
        return 1; // base case
    }

    ll res = modpow(a,b/2);
    res = (res * res) % MOD;
    if(b&1)
    {
        return (res * a)%MOD;
    }

    return res;
}

int dfs(int u)
{
    visited[u] = true;
    int cnt = 1;

    for(int v : red[u])
    {
        if(!visited[v])
        {
            cnt += dfs(v);
        }
    }

    return cnt;
}


void solve()
{
    ll n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++)
    {
        red[i].clear();
        visited[i] = false;
    }

    for(int i=0; i<n-1; i++)
    {
        int u,v,x;
        cin>>u>>v>>x;

        if(x==0)
        {
            red[u].push_back(v);
            red[v].push_back(u);
        }
    }

    ll total = modpow(n,k);


    //count bad
    ll bad = 0;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            int sz = dfs(i);
            bad = (bad + modpow(sz, k)) % MOD;
        }
    }

    ll good = (total - bad + MOD) % MOD;
    cout << good << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

   solve();

    return 0;
}
