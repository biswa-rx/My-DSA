// Kruskal
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 100;
vector<int> sz(N);
vector<int> parent(N);
void makeSet(int idx)
{
    parent[idx] = idx;
    sz[idx] = 1;
}
int findSet(int idx)
{
    if (idx == parent[idx])
    {
        return idx;
    }
    return parent[idx] = findSet(parent[idx]);
}
void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    for (int i = 0; i < 100; i++)
    {
        makeSet(i);
    }
    vector<vector<int>> edges;
    int n, m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    int cost = 0;
    sort(edges.begin(), edges.end());//Sort all the edges with respect to the its weights

    for (auto it : edges)///Iterate all weight and take one by one with conform that no cycle formed
    {
        int w = it[0];
        int u = it[1];
        int v = it[2];
        int a = findSet(u);
        int b = findSet(v);
        if (a == b)
        {
            continue;
        }
        else
        {
            cout << u << " " << v << endl;
            cost += w;
            unionSet(u, v);
        }
    }
    cout << cost << endl;

    return 0;
}
/* 8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1
8 5 1 */

