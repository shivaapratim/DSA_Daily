class Solution {
public:

    int solve(int i, vector<int>&prices, bool buy,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;

        int res=0;

        if(dp[i][buy]!=-1)return dp[i][buy]; 

        if(buy){
            res = max(-prices[i]+solve(i+1,prices,false,dp), solve(i+1,prices,buy,dp)); 
        }
        else{
            res = max(prices[i]+solve(i+1,prices,true,dp),solve(i+1,prices,buy,dp));
        }

        return dp[i][buy] = res;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,prices,true,dp);
    }
};