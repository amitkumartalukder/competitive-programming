/**
 * AUTHOR : AKASH
 * CREATED: 4/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;

    vector<int>toprow(n+1),bottomrow(n+1);
    for(int i=1; i<=n; i++)
    {
        cin>>toprow[i];
    }

    for(int i=1; i<=n; i++)
    {
        cin>>bottomrow[i];
    }


    int maxn = 2*n;

    //kun kun (row, colum) a value gula same
    vector<vector<pair<int,int>>> pos(maxn+1);
    for(int i=1; i<=n; i++)
    {
        pos[toprow[i]].push_back({1,i});
        pos[bottomrow[i]].push_back({2,i});
    }

    set<int>top,bottom;

    for(int i=1; i<=n; i++)
    {
        top.insert(i);
        bottom.insert(i);
    }
    ll ans = 0;
    int r = 0;

    for(int l=1; l<=maxn; l++)
    {
        while(r<maxn)
        {
            int a = top.empty() ? (n+1) : *top.begin();
            int b = bottom.empty() ? 0 : *bottom.rbegin();


            if(a-1>b)
            {
                break;
            }


            r++;
            //newcell active
            for(auto p : pos[r])
            {
                if(p.first==1)
                {
                    top.erase(p.second);
                }

                else
                {
                    bottom.erase(p.second);
                }
            }
        }




        int a = top.empty() ? (n+1) : *top.begin();
        int b = bottom.empty() ? 0 : *bottom.rbegin();


        if(a-1>b)
        {
            ans += (maxn-r+1);
        }
        for (auto p : pos[l])
        {
            if (p.first == 1)
                top.insert(p.second);
            else
                bottom.insert(p.second);
        }



    }
    cout << ans << "\n";
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
