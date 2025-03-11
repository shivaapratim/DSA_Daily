class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //we cannot use any random character as temporary to differentiate between 0 and other 0's
        //Or what if we use a single vector with pair<int,int> and store the occurences of 0's
        //Occuring in the given 2D array

        //Then iterate on the array and of pair and fill the other array
        //TC-> O(n*m)*k

        // Acha Set could also help to reduce complexity

        //Means rather than using a vector<pair<int,int>> as we will have to iterate through the 
        //vector all along to find if our i,j exsits, as se will do it in O(1) time. 

        //But yeah we used space of max(n,m);

        unordered_set<int> rows;
        unordered_set<int> cols;

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (rows.count(i) || cols.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};