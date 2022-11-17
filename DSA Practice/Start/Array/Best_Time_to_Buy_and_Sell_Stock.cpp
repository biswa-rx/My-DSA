#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int mini=0;
        int profit=0;
        for(int i=prices.size()-1;i>=0;i--){
            if(prices[i]>maxi){
                maxi=prices[i];
                mini=prices[i];
            }else{
                mini=prices[i];
            }
    
            profit=max(profit,maxi-mini);
            
        }
        return profit;
    }
};
int main()
{

   return 0;
}
