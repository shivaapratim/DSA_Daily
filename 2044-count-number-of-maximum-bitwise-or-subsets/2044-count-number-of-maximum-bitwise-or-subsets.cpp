class Solution {
public:
 
    int solve(int i, int curr, vector<int>&nums, int maxor, vector<vector<int>>&dp){
        if(nums.size()==i){
            if(curr==maxor){
                return 1;
            }
            return 0;
        }

        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }

        int pick= solve(i+1, curr|nums[i], nums, maxor, dp);

        int nonpick= solve(i+1, curr, nums, maxor, dp);

        return dp[i][curr] = pick+nonpick;
    }


    int countMaxOrSubsets(vector<int>& nums) {
        int maxor=0;
        for(auto it: nums){
            maxor|=it;
        }
        int curr=0;
        int n=nums.size();
        vector<vector<int>>dp(n+1, vector<int>(maxor+1,-1));
        return solve(0,curr,nums,maxor,dp);
    }
};