class Solution {
public:
    int m,n;

    vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};

    int solve(int i, int j, vector<vector<int>>&grid){
        if(i>=n || i<0 || j<0 || j>=m || grid[i][j] == 0)return 0;
        
        grid[i][j] = 0; 
        int area = 1;

        for(auto it: dir){
            grid[i][j]=0;
            int i_=i+it[0];
            int j_=j+it[1];
            area+=solve(i_,j_,grid);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int curr=0;
        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                if(grid[i][j]==1){
                   curr = max(curr, solve(i, j, grid));
                }
            }
        }
        return curr;
    }
};