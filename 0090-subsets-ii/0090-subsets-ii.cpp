class Solution {
public:

    void find(int ind, vector<vector<int>>&ans, vector<int>&ds,vector<int>&nums){
        ans.push_back(ds);
         for(int i=ind; i<nums.size(); i++){
             if(i>ind && nums[i-1]==nums[i])continue;
             ds.push_back(nums[i]);
             find(i+1,ans,ds,nums);
             ds.pop_back();
         }
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        find(0,ans,ds,nums);
        return ans;
    }
};