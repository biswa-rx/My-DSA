//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> path = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    void markingDFS(vector<vector<char>> &grid, vector<vector<bool>> &isVisited, int r, int c, int m, int n)
    {
        isVisited[r][c] = true;
        for (int i = 0; i < 8; i++)
        {
            if (r + path[i][0] < m || c + path[i][1] < n || r + path[i][0] >=0 || r + path[i][0] >=0)
            {
                if (grid[r + path[i][0]][c + path[i][1]] == '1' and !isVisited[r + path[i][0]][c + path[i][1]])
                {
                    markingDFS(grid, isVisited, r + path[i][0], c + path[i][1], m, n);
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> isVisited(m + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                    // cout<<"+"<<" "<<endl;cout<<flush;
                if (!isVisited[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    markingDFS(grid, isVisited, i, j, m, n);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends

class Solution {
  public:
    // Function to find the number of islands.
    
    
    void solve(int x,int y,vector<vector<char>> &grid){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y] == '0'){
            return ;
        }
        grid[x][y]='0';
        solve(x+1,y,grid);
        solve(x-1,y,grid);
        solve(x,y+1,grid);
        solve(x,y-1,grid);
        solve(x+1,y+1,grid);
        solve(x-1,y-1,grid);
        solve(x+1,y-1,grid);
        solve(x-1,y+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    count++;
                    solve(i,j,grid);
                }
            }
        }
        return count;
    }
}; 