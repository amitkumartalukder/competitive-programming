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

  vector<int>a(n);
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }

  // case 1 ( total array gcd > 1)
  int g = a[0];
  for(int i=1;i<n;i++)
  {
      g = __gcd(g, a[i]);
  }

  if(g > 1)
  {
      cout<<-1<<endl;
      return;
  }

  //case 2 (count total number of 1)
  ll cnt1 = 0;
  for(int x : a)
  {
      if(x==1)
      {
          cnt1++;
      }
  }


    if(cnt1 > 0)
    {
        cout << n - cnt1 << "\n";
        return;
    }

  // case 3 (best case);

  int best = n;
  for(int i=0;i<n;i++)
  {
      int x = a[i];

      for(int j=i;j<n;j++)
      {
          x = __gcd(x,a[j]);

          if(x==1)
          {
              best = min(best, j-i+1);
              break;
          }
      }
  }

     cout << (best - 1) + (n - 1) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();



    return 0;
}

