class Solution {
public:

    vector<vector<int>>dir= {{1,0},{0,1},{-1,0},{0,-1}};
    int n;
    int m;

    void solve(int i, int j, vector<vector<int>>&grid, long long&s){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0)return;

        int temp= grid[i][j];
        grid[i][j]=0;

        s+=temp;

        for(auto it: dir){
            int i_= i+it[0];
            int j_= j+it[1];

            solve(i_,j_,grid, s);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();

        int cnt;

        for(int i=0; i<m; i++){
            
            for(int j=0; j<n; j++){

                if(grid[i][j]>0){
                    long long s=0;
                    solve(i,j,grid,s);

                    if(s%k==0){
                        cnt++;
                    }
                }
            }
           
        }

        return cnt;
    }
};