#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define endl "\n"
using namespace std;
 
int mod=1000000007;
vector<long long> dp;
int combinaiton(int n){
    if(n==0)
        return 1;
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
      return dp[n];
    }
    long long sum = 0;
    for(int i=1;i<=6;i++){
        sum = (sum+combinaiton(n-i)%mod)%mod;
    }
    return dp[n]=sum;
}
int32_t main(){
    fio;
    dp.resize(1e6+5,-1);
    long long n;
    cin>>n;
    cout<<combinaiton(n)<<endl;
    return 0;
}