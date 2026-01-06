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

    string s;
    cin>>s;

    bool ok = true; // this is for final ans

    bool cur = (s[0]=='1'); // this is for if first index start with 1 then current segment may be at risk we need to cheak

    int zerocnt = 0;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='0')
        {
            zerocnt++;
        }

        if(i==0) // for first zero
        {
            continue;
        }

        if(s[i]==s[i+1] && s[i]=='0')
        {
            cur = false; // current segment not at risk ;
        }

        if(s[i]==s[i+1] && s[i]=='1')
        {
            if(cur && (zerocnt&1)) // if current segment at risk and  zero count is odd
            {
                ok = false;
                break;
            }

            cur = true;
            zerocnt = 0;
        }
    }

    if (cur && zerocnt % 2 == 1 && s[n-1] == '1')// last segment cheak
    {
        ok = false;
    }

    cout << (ok ? "YES" : "NO") << "\n";
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
