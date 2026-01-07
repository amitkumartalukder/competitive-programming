/**
 * AUTHOR : AKASH
 * CREATED: 7/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin>>n;

    vector<ll>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    vector<ll>odd, even;
    for(ll x: a)
    {
        if(x&1)
        {
            odd.push_back(x);
        }
        else
        {
            even.push_back(x);
        }
    }


    sort(odd.begin(),odd.end());
    sort(even.rbegin(),even.rend());

    int oddsize = odd.size();
    int evensize = even.size();

    vector<ll>prefix(evensize+1, 0);

    for(int i=0; i<evensize; i++)
    {
        prefix[i+1] = prefix[i] + even[i];
    }

    int odd1 = (oddsize > 0 ? 1 :0);
    int even1 = 0;

    for(int k=1; k<=n; k++)
    {
        if(k>1)
        {
            if(even1 < evensize)
            {
                even1++;
            }
            else
            {
                if(odd1+2 <= oddsize && even1 > 0)
                {
                    odd1 += 2;
                    even1--;

                }
                else
                {
                    odd1++;
                }
            }
        }

        if(odd1&1)
        {
            cout<<odd.back()+prefix[even1]<<" ";
        }
        else
        {
            cout<<0<<" ";
        }
    }

    cout<<endl;


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
