class Solution {
public:
    int n,m;

    vector<vector<int>>dir={{0,1},{1,0},{1,1}};
    int dp[1001][1001];

    int solve(int i, int j, vector<vector<char>>&arr){
        
        if (i >= m || j >= n || arr[i][j] == '0')
            return 0;

        int ans=INT_MAX;

        if(dp[i][j]!=-1)return dp[i][j];

        for(auto it : dir){
            int i_= it[0]+i;
            int j_= it[1]+j;   
        
            ans = min(ans,solve(i_,j_,arr));
 
        }
        return dp[i][j] = ans+1;

    }

    int maximalSquare(vector<vector<char>>& matrix) {
          m= matrix.size();
          n= matrix[0].size();

        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        // int ans=0;
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=m; j++){
        //         if(matrix[i-1][j-1]=='1'){
        //             dp[i][j]= min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]})+1;
        //             ans=max(dp[i][j],ans);
        //         }
        //     }
        // }
        int ans=0;

        memset(dp,-1,sizeof(dp));

        for(int i=0; i< m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1'){
                    ans = max(ans, solve(i,j,matrix));
                }

            }
        }

        return ans*ans;
    }
};