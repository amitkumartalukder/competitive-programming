/**
 * AUTHOR : AKASH
 * CREATED: 3/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;

    vector<pair<int,int>>seg;
    for(int i=0; i<n; i++)
    {
        int l,r;
        cin>>l>>r;
        seg.push_back({l,r});
    }


    sort(seg.begin(), seg.end(), [](const pair<int,int>& a, const pair<int,int>& b)
    {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });
    bool yes = false;
    int end1 = -1, end2 = -1;
    for(int i=0;i<n;i++)
    {
        int l = seg[i].first;
        int r = seg[i].second;

        if(l>end1)
        {
            end1 = r;
        }
        else if(l>end2)
        {
            end2 = r;
        }

        else if(l<=end1 && l<=end2)
        {
            yes = true;
            break;
        }
    }

    if(yes)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();


    return 0;
}
