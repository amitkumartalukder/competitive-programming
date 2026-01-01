/**
 * AUTHOR : AKASH
 * CREATED: 1/1/2026
 **/
#include<bits/stdc++.h>
using namespace std;
int dfs(int node,int parent,vector<vector<int>>&graph,int &cuts)
{
    int subtree = 1;

    for(int child : graph[node])
    {
        if(child==parent)
        {
            continue;
        }

        int childsize = dfs(child,node,graph,cuts);

        subtree += childsize;

        if(!(childsize&1))
        {
            cuts++;
        }
    }

    return subtree;
}
void solve()
{
   int n;
   cin>>n;

   vector<vector<int>>graph(n+1);

   //adjacency list
   for(int i=0;i<n-1;i++)
   {
       int u,v;
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
   }

   if(n&1)
   {
       cout<<-1<<endl;
       return;
   }
   int cuts = 0;
   dfs(1,0,graph,cuts);

   cout<<cuts<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();


    return 0;
}
