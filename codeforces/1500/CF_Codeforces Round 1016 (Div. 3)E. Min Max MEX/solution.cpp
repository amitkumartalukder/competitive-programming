/**
 * AUTHOR : AKASH
 * CREATED: 10/1/2026
 **/
#include <bits/stdc++.h>
using namespace std;
bool cancheak(int x, vector<int>& a, int n, int k)

{
    if(x==0)
    {
        return true;
    }

    vector<int>seen(x,-1);
    int timer = 0;
    int need = x;
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i]<x)
        {
            if(a[i]<x && seen[a[i]] != timer)
            {
                seen[a[i]] = timer;
                need--;
            }
        }

        if(need==0)
        {
            cnt++;
            timer++;
            need = x;
        }
    }

    return cnt >= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];


    int low = 0, high = n;


    while(low<high)
    {
        int mid = (low+high+1)/2;

        if(cancheak(mid,a,n,k))
        {

          low = mid;

        }
        else
        {
            high = mid - 1;
        }
    }

    cout<<low<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
