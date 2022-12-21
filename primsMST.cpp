#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int m,n;
const int N = 1e5 + 6;
vector<vector<int>> adj[N];
int cost = 0;
const int INF = 1e9;
vector<int> parent (N),dist(N);
vector<bool> visited(N);
void primsMST(int source){
    for(int i = 0;i<=n;i++){
        dist[i] = INF;
    }
    set<vector<int>> s;
    dist[source] = 0;
    s.insert({0,source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        visited[x[1]] = true;

        int u = x[1];
        int v = parent[u];
        int w = x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost += w;
        for(auto it : adj[x[1]]){
            if(visited[it[0]]){
                continue;
            }
            if(dist[it[0]]>it[1]){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    primsMST(0);
    cout<<cost;
   return 0;
}

/* 4 5
0 1 10
1 2 15
0 2 5
3 1 2
3 2 40 */

//output
/* 0 0 0
2 0 5
1 0 10
3 1 2
17 */