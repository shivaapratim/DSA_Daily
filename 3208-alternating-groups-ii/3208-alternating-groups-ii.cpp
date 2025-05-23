class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        // Duplicate the colors array for wrap-around.
        for(int i=0; i<n; i++){
            colors.push_back(colors[i]);
        }
        
        int count = 0;
        int i = 0; // window start
        int j = 0; // window end
        
        // Iterate while the start of our window is in the original array
        // and we have not run off the extended array.
        while (i < n && j < colors.size()) {
            // If our current window is smaller than k, try to extend it.
            if (j - i + 1 < k) {
                // If the current pair is alternating, extend the window.
                if (colors[j] != colors[j+1])
                    j++;
                else {
                    // Violation: current and next are equal.
                    // Start a new window beginning at j+1.
                    j = j + 1;
                    i = j;
                }
            }
            // If the window size is exactly k, we have a candidate.
            else if (j - i + 1 == k) {
                // Count this window only if its starting index is in [0, n-1].
                if (i < n)
                count++;
                if(j + 1 < colors.size() && colors[j] != colors[j+1]){
                    i++;
                    j++;
                }
                else{
                    i=j+1;
                    j=i;
                }
            }
        }
        return count;
    }
 
  
};
