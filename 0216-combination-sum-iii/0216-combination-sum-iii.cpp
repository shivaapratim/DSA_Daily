class Solution {
public:
    void solve(int i, int k, int t, vector<int>& arr, vector<vector<int>>& ans) {
        if (t == 0 && k == 0) {
            ans.push_back(arr);
            return;
        }
        if (i > 9 || t < 0 || k < 0) return;

        // INCLUDE i
        arr.push_back(i);
        solve(i + 1, k - 1, t - i, arr, ans);
        arr.pop_back();

        // EXCLUDE i
        solve(i + 1, k, t, arr, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(1, k, n, arr, ans); // numbers from 1 to 9
        return ans;
    }
};

