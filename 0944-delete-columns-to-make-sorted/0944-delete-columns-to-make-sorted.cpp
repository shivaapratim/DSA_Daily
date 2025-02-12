class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.empty()) return 0;
        
        int cols = strs[0].length();
        int rows = strs.size();
        int cnt = 0;
        
        // For each column
        for(int col = 0; col < cols; col++) {
            // Check if column is sorted
            for(int row = 1; row < rows; row++) {
                if(strs[row][col] < strs[row-1][col]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};