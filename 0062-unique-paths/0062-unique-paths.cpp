class Solution {
public:

    vector<vector<int>>dir= {{0,1},{1,0}};
    int dp[101][101];

    int solve(int i, int j, int m, int n){
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(i>=m || i<0 || j>=n || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ways=0;

        for(auto it : dir){
            int i_=it[0];
            int j_=it[1];
            ways+=solve(i+i_,j+j_,m,n);
        }
        return dp[i][j]=ways;
    }

    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
    }
};