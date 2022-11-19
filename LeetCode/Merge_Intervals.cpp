#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),[&](vector<int>&a,vector<int>&b){
            return a[0]!=b[0]?a[0]<b[0]:a[1]<b[1];
        });
        int first = intervals[0][0];
        int second = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=second){
                if(second<intervals[i][1]){
                    second = intervals[i][1];
                }
            }else{
                ans.push_back({first,second});
                first = intervals[i][0];
                second = intervals[i][1];
            }
        }
        ans.push_back({first,second});
        return ans;
    }
};
//NOT WORKING WITH HASHING DUE TO CLOSE INTERVAL LIKE(3,5)(6,8)
//WE CAN DO IT WITH HASING 2*X INTERVAL BUT THAT VERY MESSY
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<int> arr(1e5,0);
//         for(int i=0; i<intervals.size(); i++){
//             for(int j=intervals[i][0];j<=intervals[i][1];j++){
//                 arr[j]++;
//             }
//         }

//         vector<vector<int>> ans;
//         int first = 0;
//         int second = 0;
//         bool insideFlag = false;
//         for(int i=0;i<1e4+10;i++){
//             if(insideFlag==false){
//                 if(arr[i]>0){
//                     first = i;
//                     insideFlag = true;
//                 }
//             }
//             else{
//                 if(arr[i]==0){
//                     second = i;
//                     ans.push_back({first,second});
//                     insideFlag = false;
//                 }
//             }
//         }
//         return ans;
//     }
// };
int main()
{

   return 0;
}
