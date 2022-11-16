//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int dp[1005][1005];
class Solution{
public:
Solution(){
    memset(dp,-1,sizeof(dp));
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        if(N<0){
            return 0;
        }
        if(W<0){
            return 0;
        }
        if(dp[N][W]!=-1){
            return dp[N][W];
        }
        int temp;
        if(W>=wt[N-1] && N-1>=0){
            temp = max(knapSack(N-1,W,val,wt),knapSack(N,W-wt[N-1],val,wt)+val[N-1]);
        }else{
            temp = knapSack(N-1,W,val,wt);
        }
        return dp[N][W] = temp;
    }
    
  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends