class Solution {
public:

    //The maximum of each 1*m grid will be the answer. 
    //just add up the next coming value in the next 1D array.

    // ans= max(histogram area rectangle(when i=0),  histogram area rectangle(when i=1), 
    // histogram area rectangle(when i=2),histogram area rectangle(when i=3),)

    int largestRectangleArea(vector<int>& hist) {
        stack<int>st;
        int maxArea = 0;
        int n = hist.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || hist[st.top()] >= hist[i])) {
                int height = hist[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> hist(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    hist[j] += 1;
                } else {
                    hist[j] = 0;   // Hawa me building nahi ho skti 
                }
            }
            maxArea = max(maxArea, largestRectangleArea(hist));
        }

        return maxArea;
    }
};