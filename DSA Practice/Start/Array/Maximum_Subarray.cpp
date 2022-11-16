#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long 
#define endl "\n"
using namespace std;

int mod=1000000007;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currentSum+=nums[i];
            if(currentSum>maxi){
                    maxi=currentSum;
            }
            if(currentSum<=0){
                currentSum=0;
            }
        }
        return maxi;
    }
};
int32_t main(){
    fio;
    
       
    return 0;
}