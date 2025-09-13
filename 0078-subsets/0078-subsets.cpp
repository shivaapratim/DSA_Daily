class Solution {
public:

    void solve(int i,vector<vector<int>>&ans, vector<int>&arr,vector<int>&nums){
        if(i>=nums.size()){
            ans.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        solve(i+1,ans,arr,nums);
        arr.pop_back();
        solve(i+1,ans,arr,nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(0,ans,arr,nums);
        return ans;
    }
};