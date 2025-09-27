class Solution {
public:

    int dp[201][201];
    vector<vector<int>>dir={{0,1},{1,0}};

    int solve(int i, int j, int m, int n){
        if(i==m-1 && j==n-1)return 1;

        if(i>=m || j>=n || j<0 || i<0){
            return 0;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        int ans=0;

        for(auto it: dir){
            int i_= it[0]+i;
            int j_= it[1]+j;

            ans+=solve(i_,j_,m,n);
        }

        return dp[i][j] = ans;
    }

    int uniquePaths(int m, int n) { 
        memset(dp,-1,sizeof(dp)); 

        return solve(0,0,m,n);
    }
};