class Solution {
public:
    vector<vector<int>>ans;

    void solve(vector<int>&nums,int i,vector<int>&arr){
        if(i>=nums.size()){
            ans.push_back(arr);
            return;
        };

        arr.push_back(nums[i]);
        solve(nums,i+1,arr);
        arr.pop_back();
        solve(nums,i+1,arr);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>arr;
        solve(nums,0,arr);
        return ans;
    }
};