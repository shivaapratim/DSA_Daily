class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0}};

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> arr;

        queue<pair<int,int>> q;
        q.push({0,0});
 
        vector<vector<char>> seen(m, vector<char>(n, 0));
        seen[0][0] = 1;

        while (!q.empty()) {
            int x = q.size();
            vector<int> temp;

            while (x--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                temp.push_back(mat[i][j]);

                for (auto &d : dir) {
                    int i_ = i + d[0], j_ = j + d[1];
                    if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n && !seen[i_][j_]) {
                        seen[i_][j_] = 1;            
                        q.push({i_, j_});
                    }
                }
            }
            arr.push_back(temp);
        }

        for (int i = 0; i < (int)arr.size(); i++)
            if (i % 2 == 0) reverse(arr[i].begin(), arr[i].end());

        vector<int> ans;
        ans.reserve(m * n);
        for (auto &row : arr) for (int v : row) ans.push_back(v);
        return ans;
    }
};
