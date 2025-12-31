/**
 * AUTHOR : AKASH
 * CREATED: 31/12/2025
 **/
#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool>visited(n+1, false);
    vector<int>ans;

    priority_queue<int, vector<int>,greater<int>>pq; // to push smallest value in the first

    visited[1] = true;
    ans.push_back(1);

    //push the neighbour of the 1 to the pq;
    for(int x: graph[1])
    {
       if(!visited[x])
       {
           pq.push(x);
       }
    }

    // main process to push dynamically

    while(ans.size()<n)
    {
        int cur = pq.top();
        pq.pop();

        if(visited[cur])
        {
            continue;
        }

        visited[cur] = true;
        ans.push_back(cur);

        for(int x: graph[cur])
        {
            if(!visited[x])
            {
                pq.push(x);
            }
        }
    }


    // Output result
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
