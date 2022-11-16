#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    map<long long,long long> mp;
    bool containsDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==1){
                return true;
            }
            mp[nums[i]]++;
        }
        return false;
    }
};
int main()
{

   return 0;
}
