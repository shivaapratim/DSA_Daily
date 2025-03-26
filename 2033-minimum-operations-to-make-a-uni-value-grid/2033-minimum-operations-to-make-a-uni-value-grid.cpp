class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<long long>vec;

        for(int i=0; i<grid.size();i++){
            for(int j=0; j<grid[0].size();j++){
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(),vec.end());

        int med= vec[vec.size()/2];
        int op=0;
        int diff=0;
        for (int i = 0; i < vec.size(); i++) {
            int diff = abs(vec[i] - med); // Absolute difference
            if (diff % x != 0) {
                return -1; // Impossible to align all values
            }
            op += diff / x; // Count number of operations
        }

        return op;

    }
};