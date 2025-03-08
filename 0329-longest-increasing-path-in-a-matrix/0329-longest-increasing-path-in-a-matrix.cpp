class Solution {
public:
    //Maxpath isliye because we have to search for the longest path not all the possible
    //Tum 1+solve() hi sirf return kar rhe the.

    //Also for checking offsets be sure what to check..u were checking i_(0),j_(1)...
    //Whether we have to check i+i_ and j+j_

    int n,m;
    
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    int dp[201][201];

    int solve(int i, int j, vector<vector<int>>&mat){
        int maxpath=1;

        //Pareshaan mat ho jo i or j aayega vo hamesha in bound hoga kyunki hamne check 
        //bhejne se pehle hi kar liya hai.

        if(dp[i][j]!=-1)return dp[i][j];

        for(auto it: dir){
            int i_=i+it[0];
            int j_=j+it[1];

            if(i_<m && j_<n && i_>=0 && j_>=0){
               
                if(mat[i][j]<mat[i_][j_]){
                    maxpath= max(maxpath, 1+solve(i_,j_,mat));
                }
            }
        }
        return dp[i][j]= maxpath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi=0;
        n=matrix[0].size();
        m=matrix.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<matrix.size();i++){
            for(int j=0; j<matrix[0].size();j++){
                maxi=max(maxi,solve(i,j,matrix));
            }
        }
        return maxi;
    }
};