/**
 * AUTHOR : AKASH
 * CREATED: 2/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;

    vector<pair<pair<ll,ll>,int>>seg;
    seg.reserve(n);

    for(int i=0; i<n; i++)
    {
        ll l, r;
        cin>>l>>r;
        seg.push_back({{l,r},i+1});
    }

    sort(seg.begin(), seg.end(), [](const auto &a, const auto &b)
    {
        if (a.first.first != b.first.first)
            return a.first.first < b.first.first;
        return a.first.second > b.first.second;
    });


    ll maxr = -1;
    ll maxidx = -1;
    bool yes = true;

    for(int i=0; i<n; i++)
    {
        ll l = seg[i].first.first;
        ll r = seg[i].first.second;

        ll idx = seg[i].second;


        if(r <= maxr)
        {
            cout<< idx <<" "<<maxidx<<endl;
            yes =false;
            break;
        }

        if(r > maxr)
        {
            maxr = r;
            maxidx = idx;
        }
    }
    if(yes)
    {
        cout << "-1 -1\n";
    }


}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();



    return 0;
}
