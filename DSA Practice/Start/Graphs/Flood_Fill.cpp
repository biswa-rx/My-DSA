#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int prevColor = image[sr][sc];
        vector<vector<bool>> vis(image.size(),vector<bool>(image[0].size(),false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            int sr = q.front().first;
            int sc = q.front().second;
            ans[sr][sc]=color;
            vis[sr][sc] = true;
            q.pop();
            if(sr>0){
                if(!vis[sr-1][sc]&&image[sr-1][sc]==prevColor){
                    q.push({sr-1,sc});
                }
            }
            if(sc>0){
                if(!vis[sr][sc-1]&&image[sr][sc-1]==prevColor){
                    q.push({sr,sc-1});
                }
            }
            if(sr<image.size()-1){
                if(!vis[sr+1][sc]&&image[sr+1][sc]==prevColor){
                    q.push({sr+1,sc});
                }
            }
            if(sc<image[0].size()-1){
                if(!vis[sr][sc+1]&&image[sr][sc+1]==prevColor){
                    q.push({sr,sc+1});
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> image = {{0,0,0},{0,0,0}};
    Solution sc;
    vector<vector<int>> ans = sc.floodFill(image,1,1,2);

    for (int i = 0; i < ans.size(); i++)
    {
       for (size_t j = 0; j < ans[0].size(); j++)
       {
        cout<<ans[i][j]<<" ";
       }
       cout<<endl;
    }
    

   return 0;
}
//DFS APPROCH
// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// private:
//     void dfs(int row, int col, vector<vector<int>>&ans,
//      vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
//      int iniColor) {
//         // color with new color
//         ans[row][col] = newColor; 
//         int n = image.size();
//         int m = image[0].size(); 
//         // there are exactly 4 neighbours
//         for(int i = 0;i<4;i++) {
//             int nrow = row + delRow[i]; 
//             int ncol = col + delCol[i]; 
//             // check for valid coordinate 
//             // then check for same initial color and unvisited pixel
//             if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
//             image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
//                 dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
//             }
//         }
//     }
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, 
//     int sr, int sc, int newColor) {
//         // get initial color
//         int iniColor = image[sr][sc]; 
//         vector<vector<int>> ans = image; 
//         // delta row and delta column for neighbours
//         int delRow[] = {-1, 0, +1, 0};
//         int delCol[] = {0, +1, 0, -1}; 
//         dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
//         return ans; 
//     }
// };

// int main(){
		
// 	vector<vector<int>>image{
// 	    {1,1,1},
// 	    {1,1,0},
// 	    {1,0,1}
// 	};
	
// // sr = 1, sc = 1, newColor = 2  	
// 	Solution obj;
// 	vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
// 	for(auto i: ans){
// 		for(auto j: i)
// 			cout << j << " ";
// 		cout << "\n";
// 	}
	
// 	return 0;
// }