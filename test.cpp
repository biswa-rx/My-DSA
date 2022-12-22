#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution
{
public:
   /**
    * @param nums: a sorted integer array
    * @param lower: An integer
    * @param upper: An integer
    * @return: a list of its missing ranges
    */
   vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
   {
      int previous = lower;
      vector<string> ans;
      for (int i = 0; i < nums.size(); i++)
      {
         // cout<<previous<<" "<<nums[i]<<endl;cout<<flush;
         if (nums[i] - previous > 2)
         {
            string temp = "";
            temp += to_string(previous + 1);
            temp += "->";
            temp += to_string(nums[i] - 1);
            ans.push_back(temp);
            previous = nums[i];
         }
         else if (nums[i] - previous == 2)
         {
            ans.push_back(to_string(previous + 1));
            previous = nums[i];
         }
         else
         {
            previous = nums[i];
         }
      }



      if (upper - previous > 2)
      {
         string temp;
         temp += to_string(previous+1);
         temp += "->";
         temp += to_string(upper);
         ans.push_back(temp);
      }
      else if (upper - previous == 2)
      {
         ans.push_back(to_string(previous + 1));
      }
      return ans;
   }
};
int main()
{
   vector<int> nums = {0, 1, 3, 50, 75};
   Solution s;
   vector<string> ans = s.findMissingRanges(nums, 0, 99);

   for (auto it : ans)
   {
      cout << it << " ";
   }
   return 0;
}
