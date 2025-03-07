class Solution {
public:
    // set<int>st;

    // int solve(int i, vector<int>&nums, int sum, bool&pre){
    //     if(i>=nums.size()){
    //         if(st.count(sum)>0){
    //             pre=true;
    //         }
    //         st.insert(sum);
    //         return 0;
    //     }
    //     return (solve(i+1,nums,sum+nums[i],pre),solve(i+1,nums,sum,pre));
    // }

   

    bool solve(int i, vector<int>&nums, int t,vector<vector<int>>&dp){
        if(i>=nums.size()){
            if(t==0)return true;
            return false;
        }

        if(dp[i][t]!=-1)return dp[i][t];

        bool take=false,nottake=false;

        if(nums[i]<=t){
            take=solve(i+1,nums,t-nums[i],dp);
        }
        nottake= solve(i+1,nums,t,dp);

        return dp[i][t]= (take || nottake);
    }


    bool canPartition(vector<int>& nums) {
        


        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;

        int t=sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(t+1,-1));

        return solve(0,nums,t,dp);

    }


    // int sum=0;
        // bool pre=false;
        // solve(0,nums,sum,pre);
        // return pre;
        // sort(nums.begin(),nums.end());

        // int sum_s=0; int sum_e=accumulate(nums.begin(),nums.end(),0);
        
        // for(int i=0; i<nums.size();i++){
        //     if(sum_s==sum_e){
        //         return true;
        //     }
        //     sum_s+=nums[i];
        //     sum_e-=nums[i];
        // }
        // return false; This will give wrong answer for [1 5 5 6 8 11]
};