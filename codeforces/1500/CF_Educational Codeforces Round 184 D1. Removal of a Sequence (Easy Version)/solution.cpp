/**
 * AUTHOR : AKASH
 * CREATED: 3/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
static const ll LIMIT = (ll)1e12;
void solve()
{
  ll x,y,k;
  cin>>x>>y>>k;

  ll low = 1, high = (ll)1e18;
  ll ans =  -1;

  while(low<=high)
  {
      ll mid = low + (high-low)/2;

      ll cur = mid;
      for(int i=0;i<x; i++)
      {
          cur -= (cur/y);
          if(cur<k)
          {
              break;
          }
      }

      if(cur >= k)
      {
          ans = mid;
          high = mid - 1;
      }
      else
      {
          low = mid + 1;
      }
  }
  if (ans > LIMIT) ans = -1;
  cout<<ans<<endl;
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


