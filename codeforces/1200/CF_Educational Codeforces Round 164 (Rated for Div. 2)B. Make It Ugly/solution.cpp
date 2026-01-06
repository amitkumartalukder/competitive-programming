/**
 * AUTHOR : AKASH
 * CREATED: 6/1/2026
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

    bool yes = true;
    for(int i=1; i<n; i++)
    {
        if(a[i-1] != a[i])
        {
            yes = false;
            break;
        }
    }

    if(yes)
    {
        cout<<"-1"<<endl;
        return;
    }

    int maxblock = n;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[0])
        {
            curr++;
        }
        else
        {
            maxblock = min(maxblock, curr);
            curr = 0;
        }
    }

    // last block update
    maxblock = min(maxblock, curr);

    cout<<maxblock<<endl;


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





