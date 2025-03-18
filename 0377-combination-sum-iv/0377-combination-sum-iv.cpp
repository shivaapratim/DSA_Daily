class Solution {
public:

    int solve(vector<int>&nums, int t, vector<int>&dp){
        if(t==0){
            return 1;
        }
        if(t<0)return 0;
        
        if(dp[t]!=-1)return dp[t];

        int pick=0;

        for(int j=0; j<nums.size(); j++){
            pick += solve(nums,t-nums[j],dp);
        }

        return dp[t]=pick;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return solve(nums, target, dp);
    }
};












