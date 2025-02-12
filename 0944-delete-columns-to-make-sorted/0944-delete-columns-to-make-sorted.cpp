class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if (strs.empty()) return 0;
        int cnt = 0;
        
        // For each row
        for(int r = 0; r < strs[0].length(); r++) {
            // For each column
            for(int c = 1; c < strs.size(); c++) {
                if(strs[c][r] < strs[c-1][r]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};