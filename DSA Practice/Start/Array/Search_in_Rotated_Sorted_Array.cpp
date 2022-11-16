
#include <bits/stdc++.h>
using namespace std;
#define ll long long int



class Solution {
public:
    int bs(vector<int> &nums,int l,int r,int target){
        if(l>r){
            return -1;
        }
        int mid=(l+r)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>=nums[l]){
            if(nums[l]<=target&&nums[mid]>=target){
                return bs(nums,l,mid-1,target);
            }else{
                return bs(nums,mid+1,r,target);
            }
        }else{
            if(nums[r]>=target&&nums[mid]<=target){
                return bs(nums,mid+1,r,target);
            }else{
                return bs(nums,l,mid-1,target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return bs(nums,0,nums.size()-1,target);
    }
};
int main()
{
    vector<int> nums={4,5,6,7,0,1,2};
    Solution obj;
    cout<<obj.search(nums,1);

   return 0;
}