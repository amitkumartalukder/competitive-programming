/**
 * AUTHOR : AKASH
 * CREATED: 2/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,k1,k2;
    cin>>n>>k1>>k2;

    vector<int>a(n),b(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }

    ll k = k1 + k2;

    priority_queue<ll>pq;
    for(int i=0; i<n; i++)
    {
        pq.push(llabs(a[i]-b[i]));
    }

    while(k>0 && !pq.empty())
    {
        ll top = pq.top();
        pq.pop();

        if(top > 0)
        {
            top--;
            k--;
        }
        else
        {
            pq.push(top);
            break;
        }

        pq.push(top);
    }

    if(k>0 && pq.top()==0)
    {
        if(k&1)
        {
            cout<<1<<endl;
            return;
        }
        else
        {
            cout<<0<<endl;
            return;
        }
    }

    ll ans = 0;
    while (!pq.empty())
    {
        long long d = pq.top();
        pq.pop();
        ans += d * d;
    }

    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();



    return 0;
}
