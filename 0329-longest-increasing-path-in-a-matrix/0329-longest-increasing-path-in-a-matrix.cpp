class Solution {
public:
    int n, m;
    
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int dp[201][201];

    int solve(int i, int j, vector<vector<int>>& mat) {
        // Check memoization at the beginning
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxpath = 1;

        for(auto it: dir) {
            int i_ = i + it[0];
            int j_ = j + it[1];

            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                if(mat[i][j] < mat[i_][j_]) {
                    maxpath = max(maxpath, 1 + solve(i_, j_, mat));
                }
            }
        }
        return dp[i][j] = maxpath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        
        m = matrix.size();
        n = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        
        int maxi = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                maxi = max(maxi, solve(i, j, matrix));
            }
        }
        return maxi;
    }
};