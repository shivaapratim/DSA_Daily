class Solution {
public:
    int n,m;

    vector<vector<int>>dir={{0,1},{1,0},{1,1}};
    int dp[1001][1001];

    int solve(int i, int j, vector<vector<int>>&arr){
        
        if (i >= m || j >= n || arr[i][j] == 0)
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


    int countSquares(vector<vector<int>>& matrix) {
       
        m= matrix.size();
        n= matrix[0].size();

        int ans=0;

        memset(dp,-1,sizeof(dp));

        for(int i=0; i< m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    ans += solve(i,j,matrix);
                }

            }
        }
        
        return ans;
    }
};



 // if(matrix.size() == 0)
        //     return 0;
        // int m = matrix.size();
        // int n = matrix[0].size();
        
        // vector<vector<int>> t(m, vector<int>(n, 0));
        // int result = 0;

        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(i == 0 || j == 0) {
        //             t[i][j] = matrix[i][j];
        //         } else {
        //             if(matrix[i][j] == 1) {
        //                 // Because, if you have any 0, then you cannot expand side of square
        //                 t[i][j] = 1 + min({t[i-1][j], t[i][j-1], t[i-1][j-1]});
        //             }
        //         }
        //         result += t[i][j];
        //     }
        // }