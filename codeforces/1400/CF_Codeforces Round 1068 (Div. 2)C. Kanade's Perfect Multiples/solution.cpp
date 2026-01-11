/**
 * AUHTOR : AKASH
 * CREATED: 11/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n,k;
    cin>>n>>k;

    vector<ll>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    unordered_map<ll,ll>freq;
    for(int i=0; i<n; i++)
    {
        freq[a[i]]++;
    }

    vector<ll>v;
    {
        unordered_set<ll>temp;
        for(ll x : a)
        {
            temp.insert(x);
        }

        for(ll x : temp)
        {
            v.push_back(x);
        }
    }

    sort(v.begin(),v.end());

    unordered_map<ll,bool>finished;
    vector<ll>B;

    for(ll x: v)
    {
        if(finished[x])
        {
            continue;
        }

        B.push_back(x);

        for(ll i = x; i<=k ; i+=x)
        {
            if(freq[i]==0)
            {
                cout<<-1<<endl;
                return;
            }

            finished[i] = true;

        }
    }

    // output
    cout << B.size() << '\n';
    for (ll x : B)
        cout << x << ' ';
    cout << '\n';



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


