class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int firstOneRow= 1001;
        int firstOneCol= 1001;
        int lastOneRow= -1;
        int lastOneCol= -1;

        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size(); j++){
                
                if(grid[i][j]==1){
                    firstOneRow = min(i,firstOneRow);
                    lastOneRow  = max(i,lastOneRow);

                    firstOneCol= min(j,firstOneCol);
                    lastOneCol = max(j,lastOneCol);
                }

            }
        }

        // cout<< lastOneRow<<firstOneRow <<lastOneCol<<firstOneCol;

        int ans= (lastOneRow-firstOneRow + 1 ) * (lastOneCol-firstOneCol+1);

        return ans;

    }
};