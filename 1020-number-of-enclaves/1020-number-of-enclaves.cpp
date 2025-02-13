class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    int n=0; int m=0;
    void solve(vector<vector<int>>&grid, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1)return;

        grid[i][j]=2;

        for(auto&it: dir){
            int i_= it[0];
            int j_= it[1];
            solve(grid,i+i_,j+j_);
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j==0 || i==n-1 || j==m-1 && grid[i][j]==1){
                    solve(grid,i,j);
                }
            }
        }

        int ans=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};