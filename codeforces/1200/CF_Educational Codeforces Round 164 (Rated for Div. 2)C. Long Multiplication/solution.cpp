/**
 * AUTHOR : AKASH
 * CREATED: 5/1/2025
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    string x, y;
    cin >> x >> y;

    int n = x.size();
    bool yes = false;

    // left to right
    for (int i = 0; i < n; i++)
    {
        if ((x[i] > y[i])==yes)
        {
            swap(x[i], y[i]);
        }
        
        if(x[i] != y[i])
        {
            yes = true;
        }
    }

    cout << x << "\n" << y << "\n";
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

