/**
 * AUTHOR : AKASH
 * CREATED: 12/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;

    vector<int>a(n),b(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }

    vector<pair<int,int>>ops;

    for(int i=0; i<n; i++)
    {
        if(a[i] > b[i])
        {
            swap(a[i],b[i]);
            ops.push_back({3,i+1});
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j+1<n; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(a[j],a[j+1]);
                ops.push_back({1, j+1});
            }
        }
    }


    for(int i=0; i<n; i++)
    {
        for(int j=0; j+1<n; j++)
        {
            if(b[j] > b[j+1])
            {
                swap(b[j],b[j+1]);
                ops.push_back({2, j+1});
            }
        }
    }

    cout << ops.size() << "\n";
    for (auto &op : ops)
    {
        cout << op.first << " " << op.second << "\n";
    }
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


