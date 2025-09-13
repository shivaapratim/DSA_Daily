class Solution {
public:

    void solve(int i, vector<int>& arr, vector<vector<int>>& ans, vector<int>& c, int t) {
        if (t == 0) {
            ans.push_back(arr);
            return;
        }
        
        if (i >= c.size() || t < 0) return;  // base cases

        // CHOICE 1: Include c[i]
        arr.push_back(c[i]);
        solve(i, arr, ans, c, t - c[i]);   // not i+1, because we can reuse same element
        arr.pop_back();

        // CHOICE 2: Exclude c[i] and move forward
        solve(i+1, arr, ans, c, t);
    }

    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0,arr,ans,can,t);
        return ans;
    }
};