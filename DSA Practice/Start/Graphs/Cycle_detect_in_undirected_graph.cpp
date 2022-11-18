//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCyclePresent(int src,vector<int> adj[],vector<bool> &isVisited,int parent){
        isVisited[src] = true;
        for(auto it:adj[src]){
            if(it!=parent){
                if(isVisited[it]){
                    return true;
                }
                if(isCyclePresent(it,adj,isVisited,src)){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> isVisited(V,false);
        for(int i=0;i<V;i++){
            if(!isVisited[i]&&isCyclePresent(i,adj,isVisited,-1)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends