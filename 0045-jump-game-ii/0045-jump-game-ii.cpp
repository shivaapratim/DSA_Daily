class Solution {
public:

    int solve(int i, vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()-1){
            return 0;
        }

        if(dp[i]!=-1)return dp[i];
        
        int mini=nums.size();

        for(int j=1; j<=nums[i] && i+j<nums.size(); j++){
           mini= min(mini , 1+solve(i+j,nums,dp));
        }

        return dp[i]=mini;
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1);
        fill(dp.begin(),dp.end(),-1);
        return solve(0,nums,dp);
     
    }
};