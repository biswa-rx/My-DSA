#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        bool flag = false;
        int i;
        for (i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            int index = i;
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] <= nums[index] && nums[j] > nums[i - 1])
                {
                    index = j;
                }
            }
            swap(&nums[index], &nums[i - 1]);
            //
            sort(nums, i, nums.size() - 1);
        }
        else
        {
            sort(nums, 0, nums.size() - 1);
        }
    }
    void sort(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            swap(&nums[start], &nums[end]);
            start++;
            end--;
        }
    }
    void swap(int *x, int *y)
    {
        *x ^= *y;
        *y ^= *x;
        *x ^= *y;
    }
};
int main()
{
    vector<int> nums = {1, 2, 3, 2, 3};
    Solution ob;
    ob.nextPermutation(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}
