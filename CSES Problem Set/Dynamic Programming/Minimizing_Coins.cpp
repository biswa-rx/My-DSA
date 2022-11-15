#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define endl "\n"
using namespace std;
 
int inf=1e9;
// vector<vector<int>> dp;
int Minimize(vector<int>& arr,int n,int k,vector<int>dp[]){
    if(k<0){
        return inf;
    }
    if(k==0){
        return 0;
    }
 
    if(n<0){
        return inf;
    }
    if(dp[n][k]!=-1){
        return dp[n][k];
    }
    if(k-arr[n]>=0)
    return dp[n][k]=min(Minimize(arr,n-1,k,dp),Minimize(arr,n,k-arr[n],dp)+1);
    else
    return dp[n][k]=Minimize(arr,n-1,k,dp);
 
}
int32_t main(){
    fio;
    // dp.resize(105,vector<int>(1e6+5,-1));
    vector<int>dp[101];
    for (int i = 0; i <101; i++)
    {
        dp[i].resize(1e6+5,-1);
    }
    
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=Minimize(v,n-1,k,dp);
    cout<<(ans==inf?-1:ans)<<endl;
 
       
    return 0;
}