class Solution {
public:

    int dp[101];

    int solve(vector<int>nums,int i){
        if(i>=nums.size())return 0;

        if(dp[i]!=-1){
            return dp[i];
        }

        int pick = nums[i]+solve(nums,i+2);
        int notpick= solve(nums,i+1);

        return dp[i]=max(pick,notpick);
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }

};