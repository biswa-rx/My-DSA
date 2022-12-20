#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// function to find the length of the longest increasing subsequence using a bottom-up approach
int LIS(vector<int> &sequence)
{
    // create an array to store the length of the longest increasing subsequence ending at each index
    vector<int> lis(sequence.size(), 1);

    // iterate through the sequence in reverse order
    for (int i = sequence.size() - 2; i >= 0; i--)
    {
        // iterate through the elements after the current element
        for (int j = i + 1; j < sequence.size(); j++)
        {
            // if the current element is less than the element at the next index and adding it to the increasing subsequence ending at the next index results in a longer subsequence, update the value in the array for the current element
            if (sequence[i] < sequence[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // return the maximum value in the array
    return *max_element(lis.begin(), lis.end());
}

int main()
{
    // test the function with a sample sequence
    vector<int> sequence = {3, 4, -1, 0, 6, 2, 3};
    cout << "Length of longest increasing subsequence: " << LIS(sequence) << endl;

    return 0;
}
