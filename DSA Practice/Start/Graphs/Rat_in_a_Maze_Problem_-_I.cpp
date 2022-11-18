#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isSafe(vector<vector<int> > &m,int row,int col,int n,vector<vector<bool> > &isVisited){
        if(row>=0&&col>=0&&row<n&&col<n&&m[row][col]==1&&!isVisited[row][col]){
            return true;
        }
        return false;
    }
    void ratInMaze(vector<vector<int>> &m,int n,int row,int col,vector<vector<bool>> &isVisited,vector<string> &ans,string &path){
        if(row==n-1&&col==n-1){
            ans.push_back(path);
            return;
        }
        isVisited[row][col]=true;
        if(isSafe(m,row+1,col,n,isVisited)){
            path.push_back('D');
            ratInMaze(m,n,row+1,col,isVisited,ans,path);
            path.pop_back();
        }
        if(isSafe(m,row,col+1,n,isVisited)){
            path.push_back('R');
            ratInMaze(m,n,row,col+1,isVisited,ans,path);
            path.pop_back();
        }
        if(isSafe(m,row-1,col,n,isVisited)){
            path.push_back('U');
            ratInMaze(m,n,row-1,col,isVisited,ans,path);
            path.pop_back();
        }
        if(isSafe(m,row,col-1,n,isVisited)){
            path.push_back('L');
            ratInMaze(m,n,row,col-1,isVisited,ans,path);
            path.pop_back();
        }
        isVisited[row][col] = false;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        string path;
        vector<vector<bool>> isVisited(n,vector<bool>(n,false));
        if(m[0][0]==0){
            return ans;
        }
        ratInMaze(m,n,0,0,isVisited,ans,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


int main() {
    
    return 0;
}