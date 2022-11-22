//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        int y=x;
        int index=0;
        while(y){
            if(y&1){
                break;
            }
            y>>=1;
            index++;
        }
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            if((temp>>index)&1){
                x^=temp;
            }
        }
        int num1=x;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        int num2=x;
        
        vector<int> ans;
        ans.push_back(min(num1,num2));
        ans.push_back(max(num1,num2));
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends