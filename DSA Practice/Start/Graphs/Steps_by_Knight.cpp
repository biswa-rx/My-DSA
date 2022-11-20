#include <bits/stdc++.h>
using namespace std;
#define ll long long int


//FOOL DFS 
// ***********************************NOT WORKING********************************


// bool isSafe(int row,int col,int n,vector<vector<bool>> &isVisited){
//     if(row>=0 and col>=0 and row<n and col<n and !isVisited[row][col]){
//         return true;
//     }
//     return false;
// }
// void knight_step(int row,int col,int n,vector<vector<bool>> &isVisited,vector<int> &TargetPos,int &stepCount,int &ans){
//     if(row==TargetPos[0] and col == TargetPos[1]){
//         if(stepCount<ans){
//             ans=stepCount;
//         }
//         return;
//     }
//     isVisited[row][col] = true;
//     if(isSafe(row+2,col+1,n,isVisited)){
//         stepCount++;
//         knight_step(row+2,col+1,n,isVisited,TargetPos,stepCount,ans);
//         stepCount--;
//     }
//     if(isSafe(row+2,col-1,n,isVisited)){
//         stepCount++;
//         knight_step(row+2,col-1,n,isVisited,TargetPos,stepCount,ans);
//         stepCount--;
//     }
//     if(isSafe(row-2,col+1,n,isVisited)){
//         stepCount++;
//         knight_step(row-2,col+1,n,isVisited,TargetPos,stepCount,ans);
//         stepCount--;
//     }
//     if(isSafe(row-2,col-1,n,isVisited)){
//         stepCount++;
//         knight_step(row-2,col-1,n,isVisited,TargetPos,stepCount,ans);
//         stepCount--;
//     }
//     if(isSafe(row+1,col+2,n,isVisited)){
//         stepCount++;
//         knight_step(row+1,col+2,n,isVisited,TargetPos,stepCount,ans);
//         stepCount--;
//     }
//     if(isSafe(row+1,col-2,n,isVisited)){
//         stepCount++;
//         knight_step(row+1,col-2,n,isVisited,TargetPos,stepCount,ans);
//         stepCount--;
//     }
//     if(isSafe(row-1,col+2,n,isVisited)){
//         stepCount++;
//         knight_step(row-1,col+2,n,isVisited,TargetPos,stepCount,ans);
//         stepCount--;
//     }
//     if(isSafe(row-1,col-2,n,isVisited)){
//         stepCount++;
//         knight_step(row-1,col-2,n,isVisited,TargetPos,stepCount,ans);
//         stepCount--;
//     }
//     // isVisited[row][col] = false;
// }
// int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
// {
//     int minStep = 0;
//     int ans = INT_MAX;
//     vector<vector<bool>> isVisited(N,vector<bool>(N,false));
//     knight_step(KnightPos[0],KnightPos[1],N,isVisited,TargetPos,minStep,ans);

//     return minStep;

// }

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    bool isValid(int i, int j, int n, vector<vector<bool>>&visited){
        if(i>=0 && i<n && j>=0 && j<n && visited[i][j] == false){
            return true;
        }
        return false;
    }
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int n = N;
	    int tx = TargetPos[0]-1, ty = TargetPos[1]-1;
	    int x1 = KnightPos[0]-1, y1 = KnightPos[1]-1;
	    
	    if(x1 == tx && y1 == ty) return 0;
	    
	    vector<vector<bool>>visited(n, vector<bool>(n, false));
	    
	    queue<pair<int, int>>q;
	    q.push({x1, y1});
	    visited[x1][y1] = true;
	    
	    int ans = 0;
	    while(!q.empty()){
	        
	        int size = q.size();
	        ans++;
	        while(size != 0){
	            pair<int,int>p = q.front();
	            q.pop();
	            
	            int xx = p.first;
	            int yy = p.second;
	            
	            int ax[8] = {1, 1, -1, -1, 2, -2, 2, -2};
	            int ay[8] = {2, -2, 2, -2, 1, 1, -1, -1};
	            
	            for(int i=0; i<8; i++){
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                
	                if(nx == tx && ny == ty) return ans;
	                
	                if(isValid(nx, ny, n, visited)){
	                    visited[nx][ny] = true;
	                    q.push({nx, ny});
	                }
	            }
	           
	            size--;
	        }
	    }
	    
	    
	    return ans;
	    
	    
	}
};
int main()
{
    vector<int>a={4,5};
    vector<int>b={1,1};
    // cout<<minStepToReachTarget(a,b,6);

    return 0;
}
