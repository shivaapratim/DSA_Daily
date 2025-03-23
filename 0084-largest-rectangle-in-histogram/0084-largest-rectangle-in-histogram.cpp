class Solution {
public:
    int largestRectangleArea(vector<int>& hist) {
        int n = hist.size();
        vector<int> left(n), right(n);
        
        // Compute Next Smaller to Left (NSL) indices:
        // For each histogram bar, find the index of the nearest bar to the left which is smaller.
        stack<pair<int,int>> st;  // pair: {height, index}
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= hist[i])
                st.pop();
            
            if (st.empty())
                left[i] = -1;  // no smaller bar to the left
            else
                left[i] = st.top().second;
            
            st.push({hist[i], i});
        }
        
        // Clear the stack to reuse for Next Smaller to Right (NSR):
        while (!st.empty())
            st.pop();
        
        // Compute Next Smaller to Right (NSR) indices:
        // For each histogram bar, find the index of the nearest bar to the right which is smaller.
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= hist[i])
                st.pop();
            
            if (st.empty())
                right[i] = n;  // no smaller bar to the right
            else
                right[i] = st.top().second;
            
            st.push({hist[i], i});
        }
        
        // Now calculate the maximum rectangular area:
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = hist[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
