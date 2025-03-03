    class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        vector<vector<int>> result;
        
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }

private:
    void dfs(vector<vector<int>>& heights, vector<vector<int>>& ocean, int i, int j) {
        static vector<int> dir = {-1, 0, 1, 0, -1};
        ocean[i][j] = 1;
        int m = heights.size();
        int n = heights[0].size();
        
        for (int d = 0; d < 4; ++d) {
            int x = i + dir[d];
            int y = j + dir[d + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && !ocean[x][y] && heights[x][y] >= heights[i][j]) {
                dfs(heights, ocean, x, y);
            }
        }
    }
};
