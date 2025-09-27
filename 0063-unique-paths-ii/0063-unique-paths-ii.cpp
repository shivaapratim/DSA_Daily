class Solution {
public:

    int dp[1001][1001];
    int n=0,m=0;
  
    int solve(int i, int j, vector<vector<int>>&grid){
        if(i>=n || j>=m){
            return 0;
        }
        if(grid[i][j]==1){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = solve(i+1, j, grid) + solve(i, j+1, grid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        n=grid.size();
        m=grid[0].size();
        return solve(0,0,grid);
    }
};