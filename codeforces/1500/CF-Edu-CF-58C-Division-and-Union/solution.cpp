/**
 * AUTHOR : AKASH
 * CREATED: 31/12/2025
 **/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;

    vector<vector<int>>segment(n,vector<int>(3));


    for(int i=0; i<n; i++)
    {
        cin>>segment[i][0] >> segment[i][1];
        segment[i][2]=i;
    }

    sort(segment.begin(),segment.end());

    vector<int>maxright(n);
    maxright[0] = segment[0][1];

    for (int i = 1; i < n; i++)
    {
        maxright[i] = max(maxright[i - 1], segment[i][1]);
    }

    // find a place to split
    int split = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (maxright[i] < segment[i + 1][0])
        {
            split = i;
            break;
        }
    }



    // if split not found, impossible
    if (split == -1)
    {
        cout << -1 << '\n';
        return;
    }

    // assign groups
    vector<int> answer(n);

    for (int i = 0; i <= split; i++)
        answer[segment[i][2]] = 1;

    for (int i = split + 1; i < n; i++)
        answer[segment[i][2]] = 2;

    // print in input order
    for (int i = 0; i < n; i++)
        cout << answer[i] << " ";
    cout << '\n';
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
