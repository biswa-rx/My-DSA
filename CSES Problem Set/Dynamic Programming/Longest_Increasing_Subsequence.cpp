#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long 
#define endl "\n"
using namespace std;

// int mod=1000000007;

// int lis(vector<int>& v,int index){
//     int longest=1;
//     for(int i=0;i<index;i++){
//         if(v[i]<v[index]){
//             longest = max(longest,1+lis(v,i));
//         }
//     }
//     return longest;
// }
// int longestIncreasingSubsequence(vector<int> nums){
//     int size = nums.size();
//     int ans = 0;
//     for (int i = 0; i < size; i++)
//     {
//         ans = max(ans,lis(nums,i));
//     }

//     return ans;
// }

// int32_t main(){
//     fio;
//     int num;
//     cin>>num;
//     vector<int> vi(num);
//     for (int i = 0; i < num; i++)
//     {
//         cin>>vi[i];
//     }
//     cout<<longestIncreasingSubsequence(vi);
    
       
//     return 0;
// }
///////////////////////////////////////////Dynamic programming
// #include <bits/stdc++.h>
// #define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// #define ll long long 
// #define endl "\n"
// using namespace std;

// int mod=1000000007;

// int lis(vector<int>& v,int index,vector<int>& dp){
//     if(dp[index]!=-1){
//         return dp[index];
//     }
//     dp[index]=1;
//     for(int i=0;i<index;i++){
//         if(v[i]<v[index]){
//             dp[index] = max(dp[index],1+lis(v,i,dp));
//         }
//     }
//     return dp[index];
// }
// int longestIncreasingSubsequence(vector<int> nums){
//     int size = nums.size();
//     int ans = 0;
//     vector<int> dpTable(size+1,-1);
//     for (int i = 0; i < size; i++)
//     {
//         ans = max(ans,lis(nums,i,dpTable));
//     }

//     return ans;
// }

int longestIncreasingSubsequence(vector<int> vi){
    int size = vi.size();
    vector<int> ans;
    ans.push_back(vi[0]);
    for(int i=1;i<size;i++){
        if(vi[i]>ans.back()){
            ans.push_back(vi[i]);
        }else{
            ans[lower_bound(ans.begin(),ans.end(),vi[i])-ans.begin()] = vi[i];
        }
    }
    return ans.size();
}
int32_t main(){
    fio;
    int num;
    cin>>num;
    vector<int> vi(num);
    for (int i = 0; i < num; i++)
    {
        cin>>vi[i];
    }
    cout<<longestIncreasingSubsequence(vi);    
    return 0;
}

