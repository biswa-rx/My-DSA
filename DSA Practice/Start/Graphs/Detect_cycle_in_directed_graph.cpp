//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCyclePresent(int src,vector<int> adj[],vector<bool>&isVisited,vector<bool>&stack){
        stack[src]=true;
        if(!isVisited[src]){
            isVisited[src]=true;
            for(auto it:adj[src]){
                if(!isVisited[it] and isCyclePresent(it,adj,isVisited,stack)){
                    return true;
                }else if(stack[it]){
                    return true;
                }
            }
        }
        stack[src]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool>isVisited(V,false);
        vector<bool>stack(V,false);
        for(int i=0;i<V;i++){
            if(!isVisited[i] and isCyclePresent(i,adj,isVisited,stack)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends