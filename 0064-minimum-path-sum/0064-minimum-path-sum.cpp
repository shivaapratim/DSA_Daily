class Solution {
public:
    int dp[1001][1001];
    vector<vector<int>>dir= {{0,1},{1,0}};

    int solve(int i, int j, int n, int m, vector<vector<int>>&grid){
        if(i>=n || j>=m || i<0 || j<0){
            return INT_MAX;
        }

        if (i == n-1 && j == m-1)
            return grid[i][j];

        if(dp[i][j]!=-1)return dp[i][j];
        
        int  mini= INT_MAX;
        for(auto it: dir){
            int i_= i+ it[0];
            int j_= j+ it[1];
            int sub = solve(i_, j_, n, m, grid);
            if (sub != INT_MAX) 
                mini = min(mini, grid[i][j] + sub);
        }

        return dp[i][j] = mini;
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n=grid.size();
        int m=grid[0].size();

        return solve(0,0,n,m,grid);
    }
};