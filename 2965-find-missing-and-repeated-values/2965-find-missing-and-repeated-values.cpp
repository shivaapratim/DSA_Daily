class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr;
        
         
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                arr.push_back(grid[i][j]);
            }
        }
        
        sort(arr.begin(), arr.end());
        
        int rep = 0, miss = 0;
        
        
        for(int i=1; i<arr.size(); i++) {
            if(arr[i] == arr[i-1]) {
                rep = arr[i];
                break;
            }
        }
        
        // Find the missing number
        // We need to check for values 1 to n²
        int expected = 1;
        for(int i=0; i<arr.size(); i++) {
            // Skip the repeated number
            if(i > 0 && arr[i] == arr[i-1]) {
                continue;
            }
            
            // If we find a gap, we found our missing number
            if(arr[i] != expected) {
                miss = expected;
                break;
            }
            
            expected++;
        }
        
        // If we didn't find a missing number yet, it must be n²
        if(miss == 0) {
            miss = n*n;
        }
        
        return {rep, miss};

    }
};