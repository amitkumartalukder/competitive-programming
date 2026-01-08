/**
 * AUTHOR : AKASH
 * CREATED: 8/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
   string l, r;
   cin>>l>>r;

   int n = l.size();
   int idx = 0;
   while(idx < n && l[idx] == r[idx])
   {
       idx++;
   }

   int ans = 2*idx;

   if(idx==n)
   {
       cout<<ans<<endl;
       return;
   }



       int a = l[idx] - '0';
       int b = r[idx] - '0';

        // if difference >= 2 → done
       if(abs(a-b) >=2)
       {
           cout<<ans<<endl;
           return;
       }
       //abs(a-b)==1
       ans++;

       idx++;
       while(idx<n&&l[idx] =='9' && r[idx]=='0')
       {
           ans ++;
           idx++;
       }


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
